CFLAGS += -I../../dataview/C
SOURCES = controller.c

OBJECTS = $(SOURCES:%.c=$(OBJDIR)/%.o)

all: .depend $(LIBDIR)/libcontroller.a

.depend: $(SOURCES)
	@rm -f "$@"
	@$(CC) $(CFLAGS) -MM $^ > $@

$(LIBDIR)/libcontroller.a: $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@

$(OBJDIR)/%.o : %.c
	$(CC) $(CFLAGS) $(LIBS) -c -o $@ $<

clean:
	@rm -rf .depend $(OBJECTS) $(LIBDIR)/libcontroller.a

.PHONY: all clean
