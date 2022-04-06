CFLAGS=-std=c99 -pedantic -Wall -Wextra -g \
	   -I/usr/local/include -I/usr/X11R6/include
LDFLAGS=-L/usr/local/lib -L/usr/X11R6/lib
LDLIBS=-lXm -lXt -lX11

all: label scale

.c:
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $< $(LDLIBS)
