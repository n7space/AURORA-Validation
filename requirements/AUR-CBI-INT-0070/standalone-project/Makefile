export CC = gcc
export CFLAGS =
export LIBS =
export LDFLAGS =

export OBJDIR = "$(shell pwd)/objs"
export LIBDIR = "$(shell pwd)/libs"
export BINDIR = "$(shell pwd)/bin"

SUBDIRS = src
SUBDIRS_CLEAN = $(SUBDIRS%:=% clean)

all: dirs $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@ all

$(SUBDIRS_CLEAN):
	$(MAKE) -C $@

dirs:
	@mkdir -p $(OBJDIR)
	@mkdir -p $(LIBDIR)
	@mkdir -p $(BINDIR)

include .depend

clean: $(SUBDIRS_CLEAN)
	@rm -rf $(OBJDIR) $(LIBDIR) $(BINDIR)

.PHONY: all clean dirs $(SUBDIRS) $(SUBDIRS_CLEAN)
