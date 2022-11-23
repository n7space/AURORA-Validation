TEMPLATE = lib
CONFIG -= qt
CONFIG += generateC

DISTFILES +=  $(HOME)/tool-inst/share/taste-types/taste-types.asn \
    Error-data.acn \
    Error-data.asn \
    linux.dv.xml
DISTFILES += error-communication-with-timestamp.msc
DISTFILES += interfaceview.xml
DISTFILES += work/binaries/*.msc
DISTFILES += work/binaries/coverage/index.html
DISTFILES += work/binaries/filters
DISTFILES += work/system.asn

DISTFILES += error-communication-with-timestamp.asn
DISTFILES += error-communication-with-timestamp.acn
include(work/taste.pro)
message($$DISTFILES)

