export CC = gcc
export CFLAGS = -O0 -g -fno-omit-frame-pointer
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

clean: $(SUBDIRS_CLEAN)
	@rm -rf $(OBJDIR) $(LIBDIR) $(BINDIR)

test: all
	./test.sh

.PHONY: all clean dirs test $(SUBDIRS) $(SUBDIRS_CLEAN)
