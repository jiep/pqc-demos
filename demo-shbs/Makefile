BOTAN=../botan
PREFIX=../botan
BUILD_DIR ?= build


JOBS ?= $(shell nproc)

all: build

.PHONY: configure build install clean


configure:
	cd ${BOTAN} && ./configure.py --prefix=${PREFIX}

build: configure
	$(MAKE) -C ${BUILD_DIR} -j${JOBS}

install: build
	$(MAKE) -C ${BUILD_DIR} install

clean:
	rm -rf ${BUILD_DIR} Botan-${BOTAN_VERSION}