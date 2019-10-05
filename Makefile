CC=gcc -O2 -g -o $@ 
OCC=gcc -O2 -g -c -o $@

.PHONY : screened

screened : screenop/objects/screenmanip.o screenop/objects/screendraw.o screenop/objects/screeninfo.o iomanip/objects/iomanip.o iomanip/objects/ibuf.o screened.o
	$(CC) $^ 
	echo Done!

screened.o : screened.c
	$(OCC) $<

screenop/objects/screenmanip.o : screenop/screenmanip.c screenop/objects/screendraw.o screenop/objects/screeninfo.o
	$(OCC) $< 

screenop/objects/screendraw.o : screenop/screendraw.c screenop/objects/screeninfo.o
	$(OCC) $<

screenop/objects/screeninfo.o : screenop/screeninfo.c
	$(OCC) $<

iomanip/objects/iomanip.o : iomanip/iomanip.c
	$(OCC) $<

iomanip/objects/ibuf.o : iomanip/ibuf.c
	$(OCC) $<
