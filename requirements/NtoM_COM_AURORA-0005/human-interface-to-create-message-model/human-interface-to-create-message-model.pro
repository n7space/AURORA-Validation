TEMPLATE = lib
CONFIG -= qt
CONFIG += generateC

DISTFILES +=  $(HOME)/tool-inst/share/taste-types/taste-types.asn \
    linux.dv.xml
DISTFILES += human-interface-to-create-message-model.msc
DISTFILES += interfaceview.xml
DISTFILES += work/binaries/*.msc
DISTFILES += work/binaries/coverage/index.html
DISTFILES += work/binaries/filters
DISTFILES += work/system.asn

DISTFILES += human-interface-to-create-message-model.asn
DISTFILES += human-interface-to-create-message-model.acn
include(work/taste.pro)
message($$DISTFILES)

