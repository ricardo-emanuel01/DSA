# include <limits.h>
# include <stdlib.h>
# include "deque.h"


NodePtr newNode(NodeType data) {
    NodePtr node = (NodePtr)calloc(1, sizeof(Node));
    if (node == NULL) {
        // Process allocation error
    }
    node->value = data;
    return node;
}


void initializeDeque(DequePtr list) {
    NodePtr left = newNode(newTreeNode(INT_MAX));
    list->head = left;
    NodePtr right = newNode(newTreeNode(INT_MAX));
    list->tail = right;
    left->next = right;
    right->prev = left;
}


void freeDeque(DequePtr list) {
    NodePtr current_node;
    NodePtr next_node = list->head;

    do {
        current_node = next_node;
        next_node = current_node->next;
        free(current_node->value);
        free(current_node);

    } while (next_node != NULL);

    free(list);
}


int isEmpty(DequePtr list) {
    if (list->size == 0) return 1;
    return 0;
}


/* It is the same as enqueue */
void push(DequePtr list, NodeType data) {
    NodePtr node = newNode(data);
    list->tail->prev->next = node;
    node->prev = list->tail->prev;
    node->next = list->tail;
    list->tail->prev = node;
    list->size++;
}


void enqueue(DequePtr list, NodeType data) {
    NodePtr node = newNode(data);
    list->tail->prev->next = node;
    node->prev = list->tail->prev;
    node->next = list->tail;
    list->tail->prev = node;
    list->size++;
}


NodeType pop(DequePtr list) {
    NodePtr nodeToFree = list->tail->prev;
    NodeType nodeValue = nodeToFree->value;
    nodeToFree->prev->next = list->tail;
    list->tail->prev = nodeToFree->prev;
    free(nodeToFree);
    list->size--;
    return nodeValue;
}


NodeType dequeue(DequePtr list) {
    NodePtr nodeToFree = list->head->next;
    NodeType nodeValue = nodeToFree->value;
    nodeToFree->next->prev = list->head;
    list->head->next = nodeToFree->next;
    free(nodeToFree);
    list->size--;
    return nodeValue;
}


NodeType front(DequePtr list) {
    if (isEmpty(list) == 0) return list->head->next->value;
    else {
        // Deal with emptyness
        // TODO: improve this case
        exit(1);
    }
}

NodeType top(DequePtr list) {
    if (isEmpty(list) == 0) return list->tail->prev->value;
    else {
        // Deal with emptyness
        // TODO: improve this case
        exit(1);
    }
}


void printDeque(DequePtr list) {
    NodePtr current_node;
    NodePtr next_node = list->head->next;

    do {
        current_node = next_node;
        printf("%d ", current_node->value);
        next_node = current_node->next;
    } while (next_node->value != INT_MAX);
    printf("\n");
}
