#
# Run `make clean' before modifying this file
#
CFLAGS=-Wno-unused-command-line-argument -O0 -Wall -Wpedantic -g -o $@
LDFLAGS=-lbsd -g -o $@
# tcc can rebuild the entire thing extremely quickly!
# with 4 threads... 0.086s
CC=CCOMPILER $(CFLAGS)
LD=LINKER $(LDFLAGS)
OCC=$(CC) -c
AR=ARCHIVER rcs $@

ifeq (DEBUG, 0)
	STRIP=strip --strip-debug
else ifeq (DEBUG, 1)
	STRIP=true
endif

.PHONY : screened check

all:
	@make check
	@make screened

screened : screened.o lib/screenop.a lib/iomanip.a lib/dynstr.a
	$(LD) $^ 
	$(STRIP) $@
	@echo Done!

screened.o : screened.c
	$(OCC) $<

# Create screen operations static library
lib/screenop.a : screenop/objects/screenmanip.o screenop/objects/screeninfo.o
	$(AR) $^
	$(STRIP) $@

screenop/objects/screenmanip.o : screenop/screenmanip.c
	$(OCC) $< 

screenop/objects/screeninfo.o : screenop/screeninfo.c
	$(OCC) $<

# Create I/O manipulation static library
lib/iomanip.a : iomanip/objects/input.o iomanip/objects/output.o iomanip/objects/file.o
	$(AR) $^
	$(STRIP) $@

iomanip/objects/input.o : iomanip/input.c
	$(OCC) $<

iomanip/objects/output.o : iomanip/output.c
	$(OCC) $<

iomanip/objects/file.o : iomanip/file.c
	$(OCC) $<

# Create dynamic string static library
lib/dynstr.a : dynstr/objects/strop.o
	$(AR) $^
	$(STRIP) $@

dynstr/objects/strop.o : dynstr/strop.c
	$(OCC) $<

check : FORCE
	mkdir lib/ >& /dev/null || true
	mkdir screenop/objects/ >& /dev/null || true
	mkdir iomanip/objects/ >& /dev/null || true
	mkdir dynstr/objects/ >& /dev/null || true

clean : /dev/null
	rm -f */objects/*
	rm -f lib/*
	rm -f screened.o
	rm -f vgcore*
	rm -f core*
	mv Makefile.bkp Makefile

normal : /dev/null
	stty cooked

recurse : /dev/null
	make recurse

FORCE :
