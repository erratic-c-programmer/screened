CC=gcc -O2 -o $@ 
OCC=gcc -O2 -c -o $@

all : screenop/objects/screenmanip.o screenop/objects/screendraw.o screenop/objects/screeninfo.o iomanip/objects/iomanip.o kilo_hmod.o
	$(CC) $^ 

kilo_hmod.o : kilo_hmod.c
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
