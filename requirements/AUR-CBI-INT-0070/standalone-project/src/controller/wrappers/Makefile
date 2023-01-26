CFLAGS += -I../src -I../../dataview/C -I../..

SOURCES = \
	C_ASN1_Types.c \
	controller_invoke_ri.c \
	controller_vm_if.c

OBJECTS = $(SOURCES:%.c=$(OBJDIR)/%.o)

all: .depend $(LIBDIR)/libcontroller_wrappers.a

.depend: $(SOURCES)
	@rm -f "$@"
	@$(CC) $(CFLAGS) -MM $^ > $@

$(LIBDIR)/libcontroller_wrappers.a: $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@

$(OBJDIR)/%.o : %.c
	$(CC) $(CFLAGS) $(LIBS) -c -o $@ $<

clean:
	@rm -rf .depend $(OBJECTS) $(LIBDIR)/libcontroller_wrappers.a

.PHONY: all clean
