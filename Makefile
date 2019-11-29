DEBUG=1
ifeq ($(DEBUG), 0)
	STRIP=strip --strip-debug $@
else
	STRIP=true
endif

CFLAGS=-Wno-unused-command-line-argument -O3 -Wall -Wpedantic -g -o $@
LDFLAGS= -lc -lbsd -e main -dynamic-linker /lib64/ld-linux-x86-64.so.2 -g -o $@
# tcc can rebuild the entire thing extremely quickly!
# with 4 threads... 0.086s
CC=gcc $(CFLAGS)
LD=ld $(LDFLAGS)
OCC=$(CC) -c
AR=ar rcs $@

.PHONY : screened check

screened : screened.o lib/screenop.a lib/iomanip.a lib/dynstr.a
	$(LD) $^ 
	$(STRIP)
	echo Done!

screened.o : screened.c
	$(OCC) $<

# Create screen operations static library
lib/screenop.a : screenop/objects/screenmanip.o screenop/objects/screeninfo.o
	$(AR) $^
	$(STRIP)

screenop/objects/screenmanip.o : screenop/screenmanip.c
	$(OCC) $< 

screenop/objects/screeninfo.o : screenop/screeninfo.c
	$(OCC) $<

# Create I/O manipulation static library
lib/iomanip.a : iomanip/objects/input.o iomanip/objects/output.o iomanip/objects/file.o
	$(AR) $^
	$(STRIP)

iomanip/objects/input.o : iomanip/input.c
	$(OCC) $<

iomanip/objects/output.o : iomanip/output.c
	$(OCC) $<

iomanip/objects/file.o : iomanip/file.c
	$(OCC) $<

# Create dynamic string static library
lib/dynstr.a : dynstr/objects/strop.o
	$(AR) $^
	$(STRIP)

dynstr/objects/strop.o : dynstr/strop.c
	$(OCC) $<

check : FORCE
	mkdir lib/ >& /dev/null || true
	mkdir screenop/objects/ >& /dev/null || true
	mkdir iomanip/objects/ >& /dev/null || true
	mkdir dynstr/objects/ >& /dev/null || true

clean : /dev/null
	rm */objects/*
	rm lib/*
	rm screened.o
	
normal : /dev/null
	stty cooked
FORCE :
