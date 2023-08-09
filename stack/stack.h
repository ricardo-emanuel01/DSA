# include <stdbool.h>

# define MAXSTACK 10


typedef int Item_type;


typedef struct stack_tag {
    int top;
    Item_type entry[MAXSTACK];
} Stack, *StackPtr;


bool isFull(StackPtr);

bool isEmpty(StackPtr);

void initializeStack(StackPtr);

void push(StackPtr, Item_type);

void pop(StackPtr, Item_type*);

Item_type peek(StackPtr);

void Error(char*);
