TEMPLATE = lib
CONFIG -= qt
CONFIG += generateC

DISTFILES +=  $(HOME)/tool-inst/share/taste-types/taste-types.asn \
    leon3.dv.xml
DISTFILES += TestPerfMon.msc
DISTFILES += interfaceview.xml
DISTFILES += work/binaries/*.msc
DISTFILES += work/binaries/coverage/index.html
DISTFILES += work/binaries/filters

DISTFILES += TestPerfMon.asn
DISTFILES += TestPerfMon.acn
include(work/taste.pro)
message($$DISTFILES)

