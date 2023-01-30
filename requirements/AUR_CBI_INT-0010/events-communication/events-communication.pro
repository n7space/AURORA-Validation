TEMPLATE = lib
CONFIG -= qt
CONFIG += generateC

DISTFILES +=  $(HOME)/tool-inst/share/taste-types/taste-types.asn \
    Event-data.acn \
    Event-data.asn \
    linux.dv.xml
DISTFILES += events-communication.msc
DISTFILES += interfaceview.xml
DISTFILES += work/binaries/*.msc
DISTFILES += work/binaries/coverage/index.html
DISTFILES += work/binaries/filters
DISTFILES += work/system.asn

DISTFILES += events-communication.asn
DISTFILES += events-communication.acn
include(work/taste.pro)
message($$DISTFILES)

