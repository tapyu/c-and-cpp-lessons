#include <stdio.h>
#include <string.h>

struct Person
{
    char name[64];
    int age;
};

void update_structure(struct Person *p, int age, char *c, int *test)
{
    p->age = age;
    p->age = test;
    strcpy(p->name, c);
}

int main(void)
{
    struct Person mike;
    int my_age[] = 50;
    char my_name[] = "Mike";

    int *pmy_age = my_age;
    char *pmy_name = my_name;

    mike.age = pmy_age;
    strcpy(mike.name, pmy_name);
    printf("The age of %s is %d", mike.name, mike.age);
}