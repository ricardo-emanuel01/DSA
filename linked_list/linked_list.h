typedef int NodeType;

typedef struct _node {
    NodeType* value;
    struct _node* prev;
    struct _node* next;
} Node, *NodePtr;

typedef struct _list {
    NodePtr head;
    NodePtr tail;
    int size;
} List, *ListPtr;


NodePtr newNode(NodeType);

void initializeList(ListPtr);

void freeList(ListPtr);

void addAtTail(ListPtr, NodeType);

void removeAtTail(ListPtr);

void addAtHead(ListPtr, NodeType);

void removeAtHead(ListPtr);

void removeAt(ListPtr, int);

void insert(ListPtr, int, NodeType);

NodePtr getNode(ListPtr, int);

NodeType get(ListPtr, int);

void set(ListPtr, int, NodeType);

int isEmpty(ListPtr);
