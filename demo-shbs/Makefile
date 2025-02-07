BOTAN = ../botan

all: build

.PHONY: configure build

configure:
	cd ${BOTAN} && ./configure.py

build: configure
	make

clean:
	rm -rf ${BOTAN}