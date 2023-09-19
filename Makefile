geom: geom.o gd.o
	gcc geom.o gd.o geom -lm

geom.o: geom.c
	gcc -c geom.c

gd.o: gd.c
	gcc -c gd.c