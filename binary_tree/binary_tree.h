typedef struct _treeNode {
    // TODO: value could be a pointer to element
    int value;
    struct _treeNode* left;
    struct _treeNode* right;
} TreeNode, *TreeNodePtr;


int max(int, int);

TreeNodePtr newTreeNode(int);

TreeNodePtr buildLevelOrder();

TreeNodePtr buildPreOrder();

TreeNodePtr buildBST();

TreeNodePtr insertBST(TreeNodePtr, int);

void freeTree(TreeNodePtr);

TreeNodePtr findMin(TreeNodePtr);

TreeNodePtr removeBST(TreeNodePtr, int);

int searchBST(TreeNodePtr, int);

int breadthFirstSearch(TreeNodePtr, int);

int depthFirstSearch(TreeNodePtr, int);

int height(TreeNodePtr);

int diameter(TreeNodePtr);

void preOrder(TreeNodePtr);

void inOrder(TreeNodePtr);

void postOrder(TreeNodePtr);

void printTree(TreeNodePtr, int);
