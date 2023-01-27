VISUAL?=kate

all: compile-linux

clean:
	rm -rf obj

edit:
	$(VISUAL) ../../dataview/C/dataview-uniq.h \
                  src/simulated_acs_hw.h \
                  src/simulated_acs_hw.c

compile-linux:
	mkdir -p obj && cd obj && gcc -c ../src/*.c
