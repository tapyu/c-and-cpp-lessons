#include <stdio.h>

struct Person {
    char name;
    int age;
};

void updateStructure(struct Person *p, int age, char *c) {
    p->age = age;
    printf("The name here is %s\n", c);
    p->name = c[2];
}

void idiotUpdate(struct Person x, int i) {
    x.age = i; // the variable x in created within this local scope, and it is lost once the function ends
}

int main(void) {
    struct Person mike;
    updateStructure(&mike, 100, "Mike");
    // idiotUpdate(mike, 100); // uncomment it to see that the we couldn't change this variable without a pointer
    printf("The age of %c is %d", mike.name, mike.age);
}
