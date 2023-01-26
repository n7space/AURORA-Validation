CFLAGS += -I../src -I../../dataview/C -I../..

SOURCES = \
	calculate_pid_QGenC.QGenC.c \
	calculate_mppt_QGenC.QGenC.c \
	algorithms_vm_if.c \
	algorithms_invoke_ri.c

OBJECTS = $(SOURCES:%.c=$(OBJDIR)/%.o)

all: .depend $(LIBDIR)/libalgorithms_wrappers.a

.depend: $(SOURCES)
	@rm -f "$@"
	@$(CC) $(CFLAGS) -MM $^ > $@

$(LIBDIR)/libalgorithms_wrappers.a: $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@

$(OBJDIR)/%.o : %.c
	$(CC) $(CFLAGS) $(LIBS) -c -o $@ $<

clean:
	@rm -rf .depend $(OBJECTS) $(LIBDIR)/libalgorithms_wrappers.a

.PHONY: all clean
