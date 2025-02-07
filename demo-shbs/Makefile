BOTAN = ../botan

all: build

.PHONY: configure build

configure:
	cd ${BOTAN} && ./configure.py --prefix=.

build: configure
	cd ${BOTAN} && make

install: build
	cd ${BOTAN} && make install

clean:
	rm -rf ${BOTAN}