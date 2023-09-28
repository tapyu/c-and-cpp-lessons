## Example
![](../assets/example.png)

### Performing it manually

To compile `tip`, run:
```
gcc -c -o build/gd.o src/gd.c
gcc -c -o build/tip.o src/tip.c
gcc -o bin/tip build/tip.o build/gd.o
```

To compile `geom`, run:
```
gcc -c -o build/gd.o src/gd.c
gcc -c -o build/geom.o src/geom.c
gcc -o bin/geom build/gd.o build/geom.o -lm
```

### Performing it by using `./Makefile`

Just run `make`.
