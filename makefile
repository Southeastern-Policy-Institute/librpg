# Adaptive Multipurpose Makefile
# Southeastern Policy Institute, 2020

# Project Name
PROJ_NAME := librpg

# Dependencies
LIBS      := spi user32 kernel32

# Definitions / Un-definitions
DEFS      := __PROJ_NAME=\"$(PROJ_NAME)\" DEBUG WIN32 WINVER=0x0501 UNICODE
UNDEFS    :=

# Commands
GCC_PREFIX:= i686-w64-mingw32-
AR        := $(GCC_PREFIX)ar
AS        := nasm
CC        := $(GCC_PREFIX)gcc
CPP       := $(GCC_PREFIX)g++
LD        := $(GCC_PREFIX)g++
RES       := $(GCC_PREFIX)windres
STRIP     := $(GCC_PREFIX)strip

# Directories
SRCDIR    := src
INCDIR    := inc /home/claudia/Projects/libspi/inc
OUTDIR    := lib
OBJDIR    := obj
RESDIR    := res
LIBDIR    := /home/claudia/Projects/libspi/lib /usr/i686-w64-mingw32/lib

# Files
OUTPUT    := $(PROJ_NAME:%=$(OUTDIR)/%.dll)
SRC       := $(wildcard $(SRCDIR)/*.*)
WIN32_SRC := $(wildcard i686_win32/*.*)
OBJ       := $(SRC:$(SRCDIR)/%=$(OBJDIR)/%.o)
            # $(WIN32_SRC:i686_win32/%=$(OBJDIR)/%.o)

# Flags
CPPFLAGS  := -c -Wall -fPIC -ffreestanding -fno-builtin -nostdinc++ \
             -fno-exceptions -fno-ident \
             $(INCDIR:%=-I%) $(DEFS:%=-D%) $(UNDEFS:%=-U%)
CFLAGS    := $(CPPFLAGS)
LDFLAGS   := -shared -mwindows \
             -Wl,--out-implib,$(OUTDIR)/$(PROJ_NAME).a \
             $(LIBDIR:%=-L%) $(LIBS:%=-l%)

# Rules
$(OBJDIR)/%.cpp.o : i686_win32/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<

$(OBJDIR)/%.asm.o : i686_win32/%.asm
	$(AS) -f win32 -o $@ $<

$(OBJDIR)/%.cpp.o : $(SRCDIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<

$(OBJDIR)/%.c.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -o $@ $<

$(OUTPUT) : $(OBJ)
	$(LD) $^ $(LDFLAGS) -o $(OUTPUT)
	$(STRIP) -s $(OUTPUT)
#	$(AR) rcs $@ $^

$(OUTDIR)/test : $(OUTPUT)
	cd test && $(MAKE) all

.PHONY : all
all : $(OUTDIR)/test

.PHONY : clean
clean :
	clear
	rm -f $(wildcard $(OBJDIR)/*.*) $(wildcard $(OUTDIR)/*.*)
