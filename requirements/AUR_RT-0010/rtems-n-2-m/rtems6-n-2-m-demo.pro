TEMPLATE = lib
CONFIG -= qt
CONFIG += generateC

DISTFILES +=  $(HOME)/tool-inst/share/taste-types/taste-types.asn \
    rtems6.dv.xml
DISTFILES +=
DISTFILES += interfaceview.xml
DISTFILES += work/binaries/*.msc
DISTFILES += work/binaries/coverage/index.html
DISTFILES += work/binaries/filters

DISTFILES += rtems6-n-2-m-demo.asn
DISTFILES += rtems6-n-2-m-demo.acn
include(work/taste.pro)
message($$DISTFILES)

