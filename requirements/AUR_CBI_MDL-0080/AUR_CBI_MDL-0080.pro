TEMPLATE = lib
CONFIG -= qt
CONFIG += generateC

DISTFILES +=  $(HOME)/tool-inst/share/taste-types/taste-types.asn
DISTFILES += AUR_CBI_MDL-0080.msc
DISTFILES += interfaceview.xml
DISTFILES += work/binaries/*.msc
DISTFILES += work/binaries/coverage/index.html
DISTFILES += work/binaries/filters
DISTFILES += work/system.asn

DISTFILES += AUR_CBI_MDL-0080.asn
DISTFILES += AUR_CBI_MDL-0080.acn
include(work/taste.pro)
message($$DISTFILES)

