#! /bin/bash
rm -f screenop.h
for i in "../*/headers/"; do # Only search two levels deep
	next_header=$i/$(echo $i | cut -d'/' -f2)_all.h
	cat ./autogen-header-msg $i/*.h > $next_header
done
