TEMPLATE = lib
CONFIG -= qt
CONFIG += generateC

DISTFILES +=  $(HOME)/tool-inst/share/taste-types/taste-types.asn \
    Event-data.acn \
    Event-data.asn \
    linux.dv.xml
DISTFILES += event-with-unique-id.msc
DISTFILES += interfaceview.xml
DISTFILES += work/binaries/*.msc
DISTFILES += work/binaries/coverage/index.html
DISTFILES += work/binaries/filters
DISTFILES += work/system.asn

DISTFILES += event-with-unique-id.asn
DISTFILES += event-with-unique-id.acn
include(work/taste.pro)
message($$DISTFILES)

