SUBDIRS := $(wildcard */.)

all: $(SUBDIRS)
$(SUBDIRS):
		$(MAKE) -C $@ test

.PHONY: all $(SUBDIRS)