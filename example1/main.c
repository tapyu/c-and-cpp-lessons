#include <stdio.h>

struct Person {
    char name[64];
    int age;
};

void updateStructure(struct Person *p, int age) {
    p->age = age;
}

void idiotUpdate(struct Person x, int i) {
    x.age = i; // the variable x in created within this local scope, and it is lost once the function ends
}

int main(void) {
    struct Person mike;
    updateStructure(&mike, 100);
    // idiotUpdate(mike, 100); // uncomment it to see that the we couldn't change this variable without a pointer
    printf("The age of Mike is %d", mike.age);
}
