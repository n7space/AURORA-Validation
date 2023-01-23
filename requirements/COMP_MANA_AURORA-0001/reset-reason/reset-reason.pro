TEMPLATE = lib
CONFIG -= qt
CONFIG += generateC

DISTFILES +=  $(HOME)/tool-inst/share/taste-types/taste-types.asn \
    leon3.dv.xml
DISTFILES += reset-reason.msc
DISTFILES += interfaceview.xml
DISTFILES += work/binaries/*.msc
DISTFILES += work/binaries/coverage/index.html
DISTFILES += work/binaries/filters
DISTFILES += work/system.asn

DISTFILES += reset-reason.asn
DISTFILES += reset-reason.acn
include(work/taste.pro)
message($$DISTFILES)

