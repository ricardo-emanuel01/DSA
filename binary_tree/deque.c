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


Deque *initializeDeque() {
    Deque *list = (Deque *)malloc(sizeof(Deque));
    NodePtr left = newNode(newTreeNode(INT_MAX));
    list->head = left;
    NodePtr right = newNode(newTreeNode(INT_MAX));
    list->tail = right;
    left->next = right;
    right->prev = left;
    list->size = 0;

    return list;
}


void freeDeque(Deque* list) {
    NodePtr current_node;
    NodePtr next_node = list->head;

    do {
        current_node = next_node;
        next_node = current_node->next;
        // To deallocate the sentinels
        if (current_node == list->tail || current_node == list->head)
            free(current_node->value);
        free(current_node);

    } while (next_node != NULL);

    free(list);
}


int isEmpty(Deque* list) {
    if (list->size == 0) return 1;
    return 0;
}


void push(Deque* list, NodeType data) {
    NodePtr node = newNode(data);
    list->tail->prev->next = node;
    node->prev = list->tail->prev;
    node->next = list->tail;
    list->tail->prev = node;
    list->size++;
}


NodeType pop(Deque* list) {
    NodePtr nodeToFree = list->tail->prev;
    NodeType nodeValue = nodeToFree->value;
    nodeToFree->prev->next = list->tail;
    list->tail->prev = nodeToFree->prev;
    free(nodeToFree);
    list->size--;
    return nodeValue;
}


void enqueue(Deque *list, NodeType data) {
    NodePtr node = newNode(data);
    list->tail->prev->next = node;
    node->prev = list->tail->prev;
    node->next = list->tail;
    list->tail->prev = node;
    list->size++;
}


NodeType dequeue(Deque* list) {
    NodePtr nodeToFree = list->head->next;
    NodeType nodeValue = nodeToFree->value;
    nodeToFree->next->prev = list->head;
    list->head->next = nodeToFree->next;
    free(nodeToFree);
    list->size--;
    return nodeValue;
}


NodeType front(Deque* list) {
    if (isEmpty(list) == 0) return list->head->next->value;
    else exit(1);
}

NodeType top(Deque* list) {
    if (isEmpty(list) == 0) return list->tail->prev->value;
    else exit(1);
}


void printDeque(Deque* list) {
    NodePtr current_node;
    NodePtr next_node = list->head->next;

    do {
        current_node = next_node;
        printf("%d ", current_node->value->value);
        next_node = current_node->next;
    } while (next_node->value->value != INT_MAX);
    printf("\n");
}
