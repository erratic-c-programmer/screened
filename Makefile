CC=gcc -O2 -g -o $@
LD=gcc -O2 -g -o $@
OCC=gcc -O2 -g -c -o $@
AR=ar rcs $@

.PHONY : screened

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
lib/iomanip.a : iomanip/objects/iomanip.o 
	$(AR) $^

iomanip/objects/iomanip.o : iomanip/iomanip.c
	$(OCC) $<

# Create dynamic string static library
lib/dynstr.a : dynstr/objects/strop.o
	$(AR) $^

dynstr/objects/strop.o : dynstr/strop.c
	$(OCC) $<

clean : /dev/null
	rm */objects/*
	rm lib/*
