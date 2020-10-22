//
// Created by chase on 10/20/20.
//

#ifndef MOD3_STACK_H
#define MOD3_STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct stack Stack;

Stack* createStack();
void destroyStack(Stack** s);
void push(Stack* s, void* el);
void* pop(Stack* s);
int isEmpty(Stack* s);
int size(Stack* s);
void display(Stack* s);

#endif //MOD3_STACK_H
