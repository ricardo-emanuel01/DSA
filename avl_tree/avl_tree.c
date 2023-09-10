# include <stdlib.h>
# include "avl_tree.h"


int max(int a, int b) {
    return (a > b) ? a : b;
}


int height(NodePtr node) {
    if (node == NULL) return 0;
    return node->height;
}


NodePtr newNode(int key) {
    NodePtr node = (NodePtr)malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}


NodePtr leftRotate(NodePtr x) {
    NodePtr y = x->right;
    NodePtr temp = y->left;

    y->left = x;
    x->right = temp;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}


NodePtr rightRotate(NodePtr x) {
    NodePtr y = x->left;
    NodePtr temp = y->right;

    y->right = x;
    x->left = temp;

    x->height = max(height(x->left), height(x->right)) +1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}


int getBalance(NodePtr node) {
    if (node == NULL) return 0;
    return height(node->left) - height(node->right);
}


NodePtr insertNode(NodePtr node, int key) {
    if (node == NULL) return newNode(key);

    if (key < node->key) node->left = insertNode(node->left, key);
    else if (key > node->key) node->right = insertNode(node->right, key);
    else return node;

    node->height = max(height(node->left), height(node->right)) + 1;
    int balance = getBalance(node);

    // Rebalance
    if (balance > 1) {
        if (key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        } else if (key < node->left->key) return rightRotate(node);
    } else if (balance < -1) {
        if (key > node->right->key) return leftRotate(node);
        else if (key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }

    return node;
}


NodePtr deleteNode(NodePtr root, int key) {
    if (root == NULL) return root;

    if (key < root->key) root->left = deleteNode(root->left, key);
    else if (key > root->key) root->right = deleteNode(root->right, key);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            NodePtr temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else *root = *temp;

            free(temp);
        } else {
            NodePtr temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == NULL) return root;

    root->height = max(height(root->left), height(root->right)) + 1;
    int balance = getBalance(root);

    if (balance > 1) {
        if (getBalance(root->left) >= 0) return rightRotate(root);
        else {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    } else if (balance < -1) {
        if (getBalance(root->right) <= 0) return leftRotate(root);
        else {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }

    return root;
}


int search(NodePtr root, int key) {
    if (root == NULL) return 0;

    if (root->key == key) return 1;
    else if (root->key > key) return search(root->right, key);
    else if (root->key < key) return search(root->left, key);
}


NodePtr minValueNode(NodePtr node) {
    NodePtr current = node;
    while (current->left != NULL) current = current->left;
    return current;
}


void freeTree(NodePtr root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
