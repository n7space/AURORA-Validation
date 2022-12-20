TEMPLATE = lib
CONFIG -= qt
CONFIG += generateC

DISTFILES +=  $(HOME)/tool-inst/share/taste-types/taste-types.asn \
    Error-data.acn \
    Error-data.asn \
    linux.dv.xml
DISTFILES += standard-protocol-error-communication.msc
DISTFILES += interfaceview.xml
DISTFILES += work/binaries/*.msc
DISTFILES += work/binaries/coverage/index.html
DISTFILES += work/binaries/filters
DISTFILES += work/system.asn

DISTFILES += standard-protocol-error-communication.asn
DISTFILES += standard-protocol-error-communication.acn
include(work/taste.pro)
message($$DISTFILES)

