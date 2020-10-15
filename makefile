# Twig Makefile
# Southeastern Policy Institute, 2020

# Definitions / Un-definitions
export TARGET   := WIN32
export DEBUG    := DEBUG
ifeq ($(TARGET),WIN32)
  export DEFS   := WINVER=0x0501 UNICODE $(TARGET) $(DEBUG)
  export UNDEFS :=
  export PREFIX := i686-w64-mingw32-
  export LIBDIR += /usr/i686-w64-mingw32/lib
else
  export DEFS   := $(DEBUG)
  export UNDEFS := UNICODE
  export PREFIX :=
endif

# Commands
export AR       := $(addprefix $(PREFIX),ar)
export AS       := nasm
export CC       := $(addprefix $(PREFIX),gcc)
export CPP      := $(addprefix $(PREFIX),g++)
export LD       := $(addprefix $(PREFIX),g++)
export RES      := $(addprefix $(PREFIX),windres)
export STRIP    := $(addprefix $(PREFIX),strip)

# Directories
export MAINDIR  := $(realpath .)
export SRCDIR   := $(addprefix $(MAINDIR)/,src)
export INCDIR   := $(addprefix $(MAINDIR)/,inc)
export BINDIR   := $(addprefix $(MAINDIR)/,bin)
export OBJDIR   := $(addprefix $(MAINDIR)/,obj)
export RESDIR   := $(addprefix $(MAINDIR)/,res)
export LIBDIR   := $(addprefix $(MAINDIR)/,lib)

# Flags
ifeq ($(TARGET),WIN32)
  export ASFLAGS:= -f win32
else
  export ASFLAGS:= -f elf
endif
export CPPFLAGS := -c -Wall -fPIC -ffreestanding -fno-builtin -nostdinc++ \
                   -fno-exceptions -fno-ident
export CFLAGS   := -c -Wall -fPIC -ffreestanding -fno-builtin -nostdinc \
                   -fno-exceptions -fno-ident

# Rules
REQS            := libspi librpg test

% : $(SRCDIR)/%
	@echo ===== BUILDING $^ =====
	@cd $^ && $(MAKE) all

.PHONY : all
all : $(REQS)
	@echo ===== FINISHED $^ =====

.PHONY : clean
clean :
	clear
	rm -f $(wildcard $(REQS:%=$(OBJDIR)/%/*.*)) $(wildcard $(LIBDIR:%=%/*.*)) \
        $(wildcard $(BINDIR:%=%/*.*))
