#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

int main (int argc, char *argv[]) {
    init_stack();

    push_int(1);
    struct StackElement int_elem1 = pop();
    push_int(11);
    struct StackElement int_elem2 = pop();
    push_int(111);
    struct StackElement int_elem3 = pop();

    char test1[] = "testing123";
    push_string(test1);
    struct StackElement string_elem1 = pop();
    char test2[] = "testing456";
    push_string(test2);
    struct StackElement string_elem2 = pop();

    printf("%i\n", int_elem1.integer);
    printf("%i\n", int_elem2.integer);
    printf("%i\n", int_elem3.integer);

    printf("%s\n", string_elem1.string);
    printf("%s\n", string_elem2.string);

    return 0;
}
