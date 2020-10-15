# Leaf Makefile
# Southeastern Policy Institute, 2020

# Project Name
PROJ_NAME := $(shell basename $(dir $(abspath $(firstword $(MAKEFILE_LIST)))))
DEFS      += __PROJ_NAME=\"$(PROJ_NAME)\"
OUTDIR    := $(addprefix $(MAINDIR)/,lib)

# Dependencies
LIBS      :=

# Files
ifeq ($(TARGET),WIN32)
OUTPUT    := $(PROJ_NAME:%=$(OUTDIR)/%.a)
else
OUTPUT    := $(PROJ_NAME:%=$(OUTDIR)/%.a)
endif
SRC       := $(wildcard $(SRCDIR)/$(PROJ_NAME)/*.*)
OBJ       := $(SRC:$(SRCDIR)/%=$(OBJDIR)/%.o)

CPPFLAGS  += $(INCDIR:%=-I%) $(DEFS:%=-D%) $(UNDEFS:%=-U%)
LDFLAGS   += -shared -mwindows -fno-ident \
             -Wl,--out-implib,$(OUTDIR)/$(PROJ_NAME).a \
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
