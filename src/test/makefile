# Leaf Makefile
# Southeastern Policy Institute, 2020

# Project Name
PROJ_NAME := $(shell basename $(dir $(abspath $(firstword $(MAKEFILE_LIST)))))
DEFS      += __PROJ_NAME=\"$(PROJ_NAME)\"
OUTDIR    := $(addprefix $(MAINDIR)/,bin)

# Dependencies
LIBS      := spi rpg
ifeq ($(TARGET),WIN32)
  LIBS    += user32 kernel32
endif

# Files
ifeq ($(TARGET),WIN32)
OUTPUT    := $(PROJ_NAME:%=$(OUTDIR)/%.exe)
else
OUTPUT    := $(PROJ_NAME:%=$(OUTDIR)/%)
endif
SRC       := $(wildcard $(SRCDIR)/$(PROJ_NAME)/*.*)
OBJ       := $(SRC:$(SRCDIR)/%=$(OBJDIR)/%.o)

CPPFLAGS  += $(INCDIR:%=-I%) $(DEFS:%=-D%) $(UNDEFS:%=-U%)
LDFLAGS   += -mwindows -fno-ident \
             $(LIBDIR:%=-L%) $(LIBS:%=-l%)

# Rules
$(OBJDIR)/%.cpp.o : $(SRCDIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<

$(OBJDIR)/%.c.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -o $@ $<

$(OUTPUT) : $(OBJ)
ifeq ($(TARGET),WIN32)
	$(AR) rcs $@ $^
else
	$(AR) rcs $@ $^
endif

.PHONY : all
all : $(OUTPUT)
