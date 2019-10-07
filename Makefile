CC=gcc -O2 -g -o $@
LD=gcc -O2 -g -o $@
OCC=gcc -O2 -g -c -o $@
AR=ar rcs $@

.PHONY : screened

screened : screened.o lib/screenop.a lib/iomanip.a
	$(LD) $^ 
	echo Done!

screened.o : screened.c
	$(OCC) $<

lib/screenop.a : screenop/objects/screenmanip.o screenop/objects/screendraw.o screenop/objects/screeninfo.o
	$(AR) $^

screenop/objects/screenmanip.o : screenop/screenmanip.c screenop/objects/screendraw.o screenop/objects/screeninfo.o
	$(OCC) $< 

screenop/objects/screendraw.o : screenop/screendraw.c screenop/objects/screeninfo.o
	$(OCC) $<

screenop/objects/screeninfo.o : screenop/screeninfo.c
	$(OCC) $<

lib/iomanip.a : iomanip/objects/iomanip.o iomanip/objects/ibuf.o
	$(AR) $^

iomanip/objects/iomanip.o : iomanip/iomanip.c
	$(OCC) $<

iomanip/objects/ibuf.o : iomanip/ibuf.c
	$(OCC) $<

clean : /dev/null
	rm */objects/*
	rm lib/*
