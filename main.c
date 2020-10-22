#include <stdio.h>
#include "Stack.h"

int main() {

    Stack* stack;
    stack = createStack();
    push(stack,(void*) 10);
    push(stack,(void*) 15);
    push(stack,(void*) 20);

    if (isEmpty(stack)) {
        printf("Stack has no elements");
    } else {
        printf("Stack has %d elements\n", size(stack));
        display(stack);
    }
    printf("Item popped: %d\n", pop(stack));
    printf("Item popped: %d\n", pop(stack));
    printf("Item popped: %d\n", pop(stack));
    if (isEmpty(stack)) {
        printf("Stack has no elements");
    } else {
        printf("Stack has %d elements\n", size(stack));
        display(stack);
    }

    destroyStack(&stack);
    return 0;
}
