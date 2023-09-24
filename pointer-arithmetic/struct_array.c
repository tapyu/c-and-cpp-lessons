#include <stdio.h>
#include <string.h>

struct Person
{
    char name[64];
    int age;
};

int main(void)
{
    struct Person people[100];
    struct Person *ppeople = people; // pass the address of the first element of the struct Person array (i.e., the internal pointer variable of `people`)

    printf("The memory size (in bytes) of struct Person is %zu.\n\n", sizeof(struct Person));

    for (int i = 0; i < 100; i++)
    {
        if (i < 2)
        {
            printf("The stored memory address of ppeople is %p.\n\n", ppeople);
        }
        
        ppeople->age = 0; // equivalent to `(ppeople*).age = 0;`
        // ppeople->name = "Mike"';
        strcpy(ppeople->name, "Mike"); // Use strcpy to copy a string into the name array
        ppeople++;
    }
    return 0;   
}