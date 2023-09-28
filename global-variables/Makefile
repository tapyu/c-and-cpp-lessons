.PHONY: all clean

all: bin/prog1

bin/prog1: build/prog1.o build/file1.o build/file2.o src/prog1.c include/global.h include/prog1.h
	gcc -o $@ $(wildcard build/*.o)

build/prog1.o: src/prog1.c include/global.h include/prog1.h
	gcc -c -o $@ $<

build/file1.o: src/file1.c include/global.h include/prog1.h
	gcc -c -o $@ $<

build/file2.o: src/file2.c include/global.h include/prog1.h
	gcc -c -o $@ $<

clean:
	rm -rf $(wildcard build/*.o) bin/prog1
