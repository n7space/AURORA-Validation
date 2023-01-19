CFLAGS += -I../dataview/C -I../controller/src -I../controller/wrappers -I../algorithms/src -I../algorithms/wrappers
LIBS += -Wl,--start-group -lcontroller_wrappers -lcontroller -Wl,--end-group -Wl,--start-group -lalgorithms_wrappers -Wl,--start-group -lalgorithms -ldataview
LDFLAGS += -L$(LIBDIR)
SOURCES = main.c

OBJECTS = $(SOURCES:%.c=$(OBJDIR)/%.o)

all: .depend $(BINDIR)/main

.depend: $(SOURCES)
	@rm -f "$@"
	@$(CC) $(CFLAGS) -MM $^ > $@

$(BINDIR)/main: $(OBJECTS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

$(OBJDIR)/%.o : %.c
	$(CC) $(CFLAGS) $(LIBS) -c -o $@ $<

clean:
	@rm -rf .depend $(OBJECTS) $(BINDIR)/main

.PHONY: all clean
