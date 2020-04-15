CC = gcc
CFLAGS = -Wall

MAIN = main.o
OBJS = vis.o

DEPS = vis.h

main: ${OBJS} ${MAIN} ${DEPS}
	${CC} -o main ${MAIN} ${OBJS} ${CFLAGS}

clean:
	rm -f ${OBJS} ${MAIN}

clear:
	bash -c "clear"

all: clear main clean

.PHONY: clean clear main all