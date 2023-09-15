1. Run:

```shell
for file in {main.c,functions.c,math.c}; do
        echo ${file/%.*/.o}
done
```
To get the object files done.
1. Run:
```shell
gcc main.o functions.o math.o -o program
```
To obtain the excutable file.
