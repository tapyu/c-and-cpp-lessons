#include <stdio.h>
#include <string.h>

struct Person {
    char name[64];
    int age;
};

void update_structure(struct Person *p, int age, char *c) {
    p->age = age;
    printf("The name here is %s\n", c);
    strcpy(p->name, c);
}

void wrong_update(struct Person x, int i) {
    x.age = i; // the variable x in created within this local scope, and it is lost once the function ends
}

int main(void) {
    struct Person mike;
    update_structure(&mike, 100, "Mike");
    wrong_update(mike, 2000); // without a pointer, we cannot update the variable
    printf("The age of %s is %d", mike.name, mike.age);
}
