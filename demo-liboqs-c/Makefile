CC=gcc
CFLAGS=-I../liboqs/build/include
LDFLAGS=-L../liboqs/build/lib -loqs -lcrypto -pthread

.PHONY: all clean liboqs demo

all: demo

liboqs: ../liboqs/build/lib/liboqs.a

../liboqs/build/lib/liboqs.a:
	mkdir -p ../liboqs/build
	cd ../liboqs/build && cmake -GNinja .. && ninja

demo: ../liboqs/build/lib/liboqs.a
	$(CC) $(CFLAGS) demo-liboqs.c -o demo-liboqs $(LDFLAGS)

run: demo
	./demo-liboqs $(kem)

clean:
	rm -rf ../liboqs/build demo-liboqs
