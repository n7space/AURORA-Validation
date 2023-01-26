SOURCES = calculate_mppt.c \
	calculate_pid.c \
	qgen_base_workspace.c \
	qgen_entry_calculate_mppt.c \
	qgen_entry_calculate_pid.c

OBJECTS = $(SOURCES:%.c=$(OBJDIR)/%.o)

all: .depend $(LIBDIR)/libalgorithms.a

.depend: $(SOURCES)
	@rm -f "$@"
	@$(CC) $(CFLAGS) -MM $^ > $@

$(LIBDIR)/libalgorithms.a: $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@

$(OBJDIR)/%.o : %.c
	$(CC) $(CFLAGS) $(LIBS) -c -o $@ $<

clean:
	@rm -rf .depend $(OBJECTS) $(LIBDIR)/libalgorithms.a

.PHONY: all clean
