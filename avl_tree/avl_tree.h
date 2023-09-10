typedef struct Node{
    int key, height;
    struct Node *left;
    struct Node *right;
} Node, *NodePtr;

int max(int, int);

int height(NodePtr);

NodePtr newNode(int);

NodePtr leftRotate(NodePtr);

NodePtr rightRotate(NodePtr);

int getBalance(NodePtr);

NodePtr insertNode(NodePtr, int);

NodePtr deleteNode(NodePtr, int);

int search(NodePtr, int);

NodePtr minValueNode(NodePtr);

void freeTree(NodePtr);
