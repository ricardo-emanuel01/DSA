# include <stdio.h>
# include <stdlib.h>
# include "stack.h"


bool isFull(StackPtr stack_ptr) {
    return stack_ptr->top >= MAXSTACK;
}


bool isEmpty(StackPtr stack_ptr) {
    return stack_ptr->top <= 0;
}


void initializeStack(StackPtr stack_ptr) {
    stack_ptr->top = 0;
}


void push(StackPtr stack_ptr, Item_type value) {
    if (isFull(stack_ptr)) Error("Stack is full!");
    else stack_ptr->entry[stack_ptr->top++] = value;
}


void pop(StackPtr stack_ptr, Item_type* popped) {
    if (isEmpty(stack_ptr)) Error("Stack is empty!");
    else *popped = stack_ptr->entry[--stack_ptr->top];
}


Item_type peek(StackPtr stack_ptr) {
    if (isEmpty(stack_ptr)) Error("Stack is empty!");
    else return stack_ptr->entry[stack_ptr->top - 1];
}


void Error(char* s) {
    fprintf(stderr, "%s\n", s);
    exit(1);
}
