#include "Stack.h"

typedef struct node {
    void* el;
    struct node* next;
} Node;

struct stack {
    Node* head;
    int size;
};

Stack* createStack(void) {
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    if (stack == NULL) {
        printf("Failed to create Stack\n");
        exit(-1);
    } else {
        stack->head = NULL;
        stack->size = 0;
        return stack;
    }
}

void destroyStack(Stack** s) {
    Node* iter = (*s)->head;
    while (iter) {
        Node* temp = iter->next;
        free(iter);
        iter = temp;
    }
    free(*s);
    *s = NULL;
}

void push(Stack* s, void* el) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->next = s->head;
    node->el = el;
    s->head = node;
    s->size++;
}
void* pop(Stack* s) {
    if (s->size) {
        Node *pop = s->head;
        void *data = pop->el;
        s->head = s->head->next;
        s->size--;
        free(pop);
        return data;
    } else {
        printf("Stack is empty\n");
        return 0;
    }
}

int isEmpty(Stack* s) {
    if (s->size > 0) {
        return 0;
    }
    return 1;
}

int size(Stack* s) {
    return s->size;
}

void display(Stack* s) {
    Node* iter = s->head;
    while (iter) {
        printf("%d\n", iter->el);
        iter = iter->next;
    }
}

