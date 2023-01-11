TEMPLATE = lib
CONFIG -= qt
CONFIG += generateC

DISTFILES +=  $(HOME)/tool-inst/share/taste-types/taste-types.asn \
    Event-data.acn \
    Event-data.asn \
    linux.dv.xml
DISTFILES += unregister-event-listener.msc
DISTFILES += interfaceview.xml
DISTFILES += work/binaries/*.msc
DISTFILES += work/binaries/coverage/index.html
DISTFILES += work/binaries/filters
DISTFILES += work/system.asn

DISTFILES += unregister-event-listener.asn
DISTFILES += unregister-event-listener.acn
include(work/taste.pro)
message($$DISTFILES)

