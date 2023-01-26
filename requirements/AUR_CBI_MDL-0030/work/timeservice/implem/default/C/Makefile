VISUAL?=kate

all: compile-linux

clean:
	rm -rf obj

edit:
	$(VISUAL) ../../dataview/C/dataview-uniq.h \
				  src/timeservice_api/timeservice-api.h \
				  src/timeservice_api/timeservice-api.c \
				  src/timeservice_api/timeservice-linux.h \
                  src/timeservice.h \
                  src/timeservice.c \


compile-linux:
	mkdir -p obj && cd obj && gcc -c ../src/timeservice_api/*.c ../src/*.c
