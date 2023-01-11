TEMPLATE = lib
CONFIG -= qt
CONFIG += generateC

DISTFILES +=  $(HOME)/tool-inst/share/taste-types/taste-types.asn \
    linux.dv.xml
DISTFILES += linux-cpp-startup-priority-demo.msc
DISTFILES += interfaceview.xml
DISTFILES += work/binaries/*.msc
DISTFILES += work/binaries/coverage/index.html
DISTFILES += work/binaries/filters

DISTFILES += linux-cpp-startup-priority-demo.asn
DISTFILES += linux-cpp-startup-priority-demo.acn
include(work/taste.pro)
message($$DISTFILES)

