typedef int NodeType;


typedef struct _node {
    NodeType value;
    struct _node* next;
    struct _node* prev;
} Node, *NodePtr;


typedef struct _deque {
    NodePtr head;
    NodePtr tail;
    int size;
} Deque, *DequePtr;


NodePtr newNode(NodeType);

void initializeDeque(DequePtr);

void freeDeque(DequePtr);

int isEmpty(DequePtr);

void push(DequePtr, NodeType);

void enqueue(DequePtr, NodeType);

NodeType pop(DequePtr);

NodeType dequeue(DequePtr);

NodeType front(DequePtr);

NodeType top(DequePtr);

void printDeque(DequePtr);
