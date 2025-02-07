BOTAN = ../botan

all: build

.PHONY: configure build

configure:
	cd ${BOTAN} && ./configure.py

build: configure
	cd ${BOTAN} && make

clean:
	rm -rf ${BOTAN}