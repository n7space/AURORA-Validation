SUBDIRS = \
    dataview \
	algorithms \
	controller \
	application

SUBDIRS_CLEAN = $(SUBDIRS)

all: $(SUBDIRS)

SUBDIRS_CLEAN = $(SUBDIRS%:=% clean)

$(SUBDIRS):
	$(MAKE) -C $@ all

$(SUBDIRS_CLEAN):
	$(MAKE) -C $@

.PHONY: all clean $(SUBDIRS) $(SUBDIRS_CLEAN)
