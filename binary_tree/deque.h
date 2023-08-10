# include <stdio.h>

# include "binary_tree.h"


typedef TreeNodePtr NodeType;


typedef struct _node {
    NodeType value;
    struct _node* next;
    struct _node* prev;
} Node, *NodePtr;


typedef struct _deque {
    NodePtr head;
    NodePtr tail;
    int size;
} Deque;


NodePtr newNode(NodeType);

void initializeDeque(Deque*);

void freeDeque(Deque*);

int isEmpty(Deque*);

void push(Deque*, NodeType);

NodeType pop(Deque*);

void enqueue(Deque*, NodeType);

NodeType dequeue(Deque*);

NodeType front(Deque*);

NodeType top(Deque*);
