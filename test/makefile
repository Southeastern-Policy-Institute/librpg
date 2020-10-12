# Adaptive Multipurpose Makefile
# Southeastern Policy Institute, 2020

# Project Name
PROJ_NAME := test

# Dependencies
LIBS      := spi rpg

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

SRCDIR    := .
INCDIR    := ../inc /home/claudia/Projects/libspi/inc
OUTDIR    := ../bin
OBJDIR    := ../obj
LIBDIR    := ../lib /home/claudia/Projects/libspi/lib

# Files
OUTPUT    := $(PROJ_NAME:%=$(OUTDIR)/%.exe)
SRC       := $(wildcard $(SRCDIR)/*.*)
OBJ       := $(SRC:$(SRCDIR)/%=$(OBJDIR)/%.o)

CPPFLAGS  := -c -Wall -fPIC \
             $(INCDIR:%=-I%) $(DEFS:%=-D%) $(UNDEFS:%=-U%)
LDFLAGS   := -mwindows $(LIBDIR:%=-L%) $(LIBS:%=-l%)

$(OBJDIR)/%.cpp.o : $(SRCDIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<

$(OBJDIR)/%.c.o : $(SRCDIR)/%.c
	$(CC) $(CPPFLAGS) -o $@ $<

$(OUTPUT) : $(OBJ)
	$(LD) $^ $(LDFLAGS) -o $(OUTPUT)

all: $(OUTPUT)
	$(STRIP) -s $(OUTPUT)

.PHONY : clean
clean :
	rm -f $(OBJ) $(OUTPUT)
