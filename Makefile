CFLAGS=-Wall -Os -lX11
CC=gcc ${CFLAGS}
DESTDIR=/usr/local/bin

.PHONY: all
all: colorpicker

colorpicker:
	${CC} -o $@ *.c

clean:
	rm -f ./colorpicker

install:
	install ./colorpicker -D --mode 755 --target-directory "${DESTDIR}"
