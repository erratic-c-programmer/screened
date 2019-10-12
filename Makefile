CC=gcc -O2 -g -o $@
LD=$(CC)
OCC=$(CC) -c
AR=ar rcs $@

.PHONY : screened check

screened : screened.o lib/screenop.a lib/iomanip.a lib/dynstr.a
	$(LD) $^ 
	echo Done!

screened.o : screened.c
	$(OCC) $<

# Create screen operations static library
lib/screenop.a : screenop/objects/screenmanip.o screenop/objects/screendraw.o screenop/objects/screeninfo.o
	$(AR) $^

screenop/objects/screenmanip.o : screenop/screenmanip.c
	$(OCC) $< 

screenop/objects/screendraw.o : screenop/screendraw.c 
	$(OCC) $<

screenop/objects/screeninfo.o : screenop/screeninfo.c
	$(OCC) $<

# Create I/O manipulation static library
lib/iomanip.a : iomanip/objects/input.o
	$(AR) $^

iomanip/objects/input.o : iomanip/input.c
	$(OCC) $<

# Create dynamic string static library
lib/dynstr.a : dynstr/objects/strop.o
	$(AR) $^

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
	
FORCE :
