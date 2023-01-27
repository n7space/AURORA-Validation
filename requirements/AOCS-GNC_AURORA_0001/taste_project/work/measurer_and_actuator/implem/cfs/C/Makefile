VISUAL?=kate

all: compile-linux

clean:
	rm -rf obj

edit:
	$(VISUAL) ../../dataview/C/dataview-uniq.h \
                  src/measurer_and_actuator.h \
                  src/measurer_and_actuator.c

compile-linux:
	mkdir -p obj && cd obj && gcc -c ../src/*.c
