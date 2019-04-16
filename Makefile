CC = gcc
CFLAGS = `pkg-config --cflags gtk+-2.0`
LDFLAGS = `pkg-config --libs gtk+-2.0`

test_gtk: test_de_base.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -c $^ $(CFLAGS)

all: test_gtk


.PHONY: clean
clean:
	rm -f *.o 
	rm -f test_gtk
	rm -f *~

