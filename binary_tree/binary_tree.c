# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

# include "deque.h"

# define PREORDER 0
# define INORDER 1
# define POSTORDER 2


int max(int a, int b) {
    if (a > b) return a;
    return b;
}


TreeNodePtr newTreeNode(int value) {
    TreeNodePtr node = (TreeNodePtr)calloc(1, sizeof(TreeNode));
    if (node == NULL) {
        // Process allocation error
    }
    node->value = value;
    node->left = node->right = NULL;
    return node;
}


TreeNodePtr buildLevelOrder() {
    int rootValue, c1, c2;
    scanf("%d", &rootValue);

    Deque* queue = (Deque*)calloc(1, sizeof(Deque));
    initializeDeque(queue);

    TreeNodePtr root = newTreeNode(rootValue);
    enqueue(queue, root);

    TreeNodePtr current;
    while (isEmpty(queue) == 0) {
        current = dequeue(queue);
        scanf(" %d %d", &c1, &c2);

        if (c1 != -1) {
            current->left = newTreeNode(c1);
            enqueue(queue, current->left);
        }
        if (c2 != -1) {
            current->right = newTreeNode(c2);
            enqueue(queue, current->right);
        }
    }
    
    freeDeque(queue);
    return root;
}


TreeNodePtr buildPreOrder() {
    int rootValue;
    scanf("%d", &rootValue);

    if (rootValue == -1) return NULL;

    TreeNodePtr root = newTreeNode(rootValue);
    root->left = buildPreOrder();
    root->right = buildPreOrder();

    return root;
}


TreeNodePtr buildBST() {
    int size, temp, rootValue;
    printf("Type the size of the binary tree: ");
    scanf("%d", &size);
    scanf("%d", &rootValue);
    TreeNodePtr root = newTreeNode(rootValue);

    for (int i = 0; i < size - 1; i++) {
        scanf("%d", &temp);
        insertBST(root, temp);
    }
    return root;
}


TreeNodePtr insertBST(TreeNodePtr root, int key) {
    if (root == NULL) return newTreeNode(key);

    if (key < root->value) root->left = insertBST(root->left, key);
    else root->right = insertBST(root->right, key);

    return root;
}


void freeTree(TreeNodePtr root) {
    Deque* queue = (Deque*)calloc(1, sizeof(Deque));
    initializeDeque(queue);
    TreeNodePtr current;
    push(queue, root);

    while(isEmpty(queue) == 0) {
        current = pop(queue);
        if (current->left != NULL) push(queue, current->left);
        if (current->right != NULL) push(queue, current->right);
        free(current);
    }
    freeDeque(queue);
}


TreeNodePtr findMin(TreeNodePtr root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}


TreeNodePtr removeBST(TreeNodePtr root, int key) {
    if (root == NULL) return NULL;
    else if (key < root->value) root->left = removeBST(root->left, key);
    else if (key > root->value) root->right = removeBST(root->right, key);
    else {
        if (root->left == NULL && root->right == NULL) {
            // NO CHILDREN
            free(root);
            root = NULL;

        } else if (root->left == NULL) {
            // RIGTH SUBTREE
            TreeNodePtr temp = root;
            root = root->right;
            free(temp);

        } else if (root->right == NULL) {
            // LEFT SUBTREE
            TreeNodePtr temp = root;
            root = root->left;
            free(temp);

        } else {
            // TWO CHILDS
            TreeNodePtr temp = findMin(root->right);
            root->value = temp->value;
            root->right = removeBST(root->right, temp->value);
        }
    }
    return root;
}


int searchBST(TreeNodePtr root, int key) {
    if (root == NULL) return 0;

    if (root->value == key) return 1;
    else {
        // Must follow the same criteria to insert element
        if (key < root->value) return searchBST(root->left, key);
        return searchBST(root->right, key);
    }
}


int breadthFirstSearch(TreeNodePtr root, int key) {
    Deque* deque = (Deque*)calloc(1, sizeof(Deque));
    initializeDeque(deque);
    enqueue(deque, root);
    TreeNodePtr currentNode;
    while (!isEmpty(deque)) {
        currentNode = dequeue(deque);
        if (currentNode->value == key) {
            freeDeque(deque);
            return 1;
        } else {
            if (currentNode->left != NULL) enqueue(deque, currentNode->left);
            if (currentNode->right != NULL) enqueue(deque, currentNode->right);
        }
    }
    freeDeque(deque);
    return 0;
}


int depthFirstSearch(TreeNodePtr root, int key) {
    Deque* deque = (Deque*)calloc(1, sizeof(Deque));
    initializeDeque(deque);
    push(deque, root);
    TreeNodePtr currentNode;
    while (!isEmpty(deque)) {
        currentNode = pop(deque);
        if (currentNode->value == key) {
            freeDeque(deque);
            return 1;
        } else {
            if (currentNode->right != NULL) push(deque, currentNode->right);
            if (currentNode->left != NULL) push(deque, currentNode->left);
        }
    }
    freeDeque(deque);
    return 0;
}


int height(TreeNodePtr root) {
    if (root == NULL) return 0;

    int h1 = height(root->left);
    int h2 = height(root->right);

    return max(h1, h2) + 1;
}


// TODO: improve
int diameter(TreeNodePtr root) {
    if (root == NULL) return 0;

    int D1 = height(root->left) + height(root->right);
    int D2 = diameter(root->left);
    int D3 = diameter(root->right);

    return max(D1, max(D2, D3));
}


void preOrder(TreeNodePtr root) {
    if (root == NULL) return;

    printf("%d ", root->value);
    preOrder(root->left);
    preOrder(root->right);
}


void inOrder(TreeNodePtr root) {
    if (root == NULL) return;

    inOrder(root->left);
    printf("%d ", root->value);
    inOrder(root->right);
}


void postOrder(TreeNodePtr root) {
    if (root == NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->value);
}


void printTree(TreeNodePtr root, int type) {
    switch (type) {
        case PREORDER:
            preOrder(root);
            break;
        case INORDER:
            inOrder(root);
            break;
        case POSTORDER:
            postOrder(root);
            break;
    }
    printf("\n");
}
