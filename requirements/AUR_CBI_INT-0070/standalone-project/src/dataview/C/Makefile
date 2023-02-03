SOURCES = \
	timeInMS.c \
	PrintTypesAsASN1.c \
	debug_messages.c \
	dataview-uniq.c \
	asn1crt_encoding_uper.c \
	asn1crt_encoding.c \
	asn1crt_encoding_acn.c \
	asn1crt.c \

OBJECTS = $(SOURCES:%.c=$(OBJDIR)/%.o)

all: .depend $(LIBDIR)/libdataview.a

.depend: $(SOURCES)
	@rm -f "$@"
	@$(CC) $(CFLAGS) -MM $^ > $@

$(LIBDIR)/libdataview.a: $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@

$(OBJDIR)/%.o : %.c
	$(CC) $(CFLAGS) $(LIBS) -c -o $@ $<

clean:
	@rm -rf .depend $(OBJECTS) $(LIBDIR)/libdataview.a

.PHONY: all clean
