.PHONY: all liboqs venv liboqs_python run check install_requirements run_hybrid_signature clean

LIBOQS_DIR=../liboqs
LIBOQS_BUILD=$(LIBOQS_DIR)/build-shared
LIBOQS_SO=$(LIBOQS_BUILD)/lib/liboqs.so
PYTHON_DIR=../2-demo-liboqs-python
VENV_DIR=venv
LIBOQS_PYTHON_DIR=../liboqs-python
EXAMPLES_DIR=../liboqs-python/examples

all: run

liboqs:
	@if [ ! -f $(LIBOQS_SO) ]; then \
		cd $(LIBOQS_DIR) && mkdir -p build-shared && cd build-shared && \
		cmake -GNinja .. -DBUILD_SHARED_LIBS=ON && ninja && sudo ninja install; \
	fi

venv:
	@if [ ! -d $(VENV_DIR) ]; then \
		python3 -m venv $(VENV_DIR); \
	fi

liboqs_python:
	. $(VENV_DIR)/bin/activate && \
	cd $(LIBOQS_PYTHON_DIR) && pip install .

install_requirements:
	. $(VENV_DIR)/bin/activate && pip install -r $(PYTHON_DIR)/requirements.txt

run: liboqs venv liboqs_python install_requirements
	export LD_LIBRARY_PATH=$$LD_LIBRARY_PATH:/usr/local/lib && \
	. $(VENV_DIR)/bin/activate

check: liboqs_python
	. $(VENV_DIR)/bin/activate && \
	python3 $(EXAMPLES_DIR)/sig.py

run_hybrid_signature: install_requirements
	. $(VENV_DIR)/bin/activate && \
	python3 $(PYTHON_DIR)/hybrid-signature.py

clean:
	@if [ -d $(LIBOQS_BUILD) ]; then \
		cd $(LIBOQS_BUILD) && ninja clean; \
	fi
