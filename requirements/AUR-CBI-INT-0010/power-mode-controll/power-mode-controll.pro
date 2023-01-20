TEMPLATE = lib
CONFIG -= qt
CONFIG += generateC

DISTFILES +=  $(HOME)/tool-inst/share/taste-types/taste-types.asn \
    linux.dv.xml
DISTFILES += power-mode-controll.msc
DISTFILES += interfaceview.xml
DISTFILES += work/binaries/*.msc
DISTFILES += work/binaries/coverage/index.html
DISTFILES += work/binaries/filters
DISTFILES += work/system.asn

DISTFILES += power-mode-controll.asn
DISTFILES += power-mode-controll.acn
include(work/taste.pro)
message($$DISTFILES)

