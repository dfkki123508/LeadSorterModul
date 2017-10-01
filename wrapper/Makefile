MFILENAME="files.txt"

all: CGnsdkLookup

CGnsdkLookup: setup.py
	python3 setup.py install --record $(MFILENAME)

clean:
	@echo "Removing build `cat $(MFILENAME)`"
	rm -rf build
	cat $(MFILENAME) | xargs rm -f
