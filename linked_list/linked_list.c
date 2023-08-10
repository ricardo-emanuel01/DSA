# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

# include "linked_list.h"


NodePtr newNode(NodeType data) {
    NodePtr node = (NodePtr)calloc(1, sizeof(Node));
    NodeType* value = (NodeType*)malloc(sizeof(NodeType));
    *value = data;
    if (node == NULL) {
        // Process allocation error
    }
    node->value = value;
    return node;
}


void initializeList(ListPtr list) {
    NodePtr left = newNode(INT_MAX);
    list->head = left;
    NodePtr right = newNode(INT_MAX);
    list->tail = right;
    left->next = right;
    right->prev = left;
}


void freeList(ListPtr list) {
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


void addAtTail(ListPtr list, NodeType data) {
    NodePtr node = newNode(data);
    node->next = list->tail;
    node->prev = list->tail->prev;
    list->tail->prev->next = node;
    list->tail->prev = node;
    list->size++;
}


void removeAtTail(ListPtr list) {
    NodePtr node = list->tail->prev;
    node->prev->next = list->tail;
    list->tail->prev = node->prev;
    free(node->value);
    free(node);
    list->size--;
}


void addAtHead(ListPtr list, NodeType data) {
    NodePtr node = newNode(data);
    node->prev = list->head;
    node->next = list->head->next;
    list->head->next->prev = node;
    list->head->next = node;
    list->size++;
}


void removeAtHead(ListPtr list) {
    NodePtr node = list->head->next;
    node->next->prev = list->head;
    list->head->next = node->next;
    free(node->value);
    free(node);
    list->size--;
}


void removeAt(ListPtr list, int index) {
    if (index == 0) removeAtHead(list);
    else if (index == (list->size - 1)) removeAtTail(list);
    else if (index < 0 || index >= list->size) {
        // Process error
    } else {
        NodePtr currentNode = list->head;
        NodePtr temp;
        for (int i = 0; i < index; i++) {
            currentNode = currentNode->next;
        }
        temp = currentNode->next;
        currentNode->next = currentNode->next->next;
        currentNode->next->next->prev = currentNode;
        free(temp->value);
        free(temp);
        list->size--;
    }
}


void insert(ListPtr list, int index, NodeType data) {
    if (index == 0) addAtHead(list, data);
    else if (index == list->size) addAtTail(list, data);
    else if (index < 0 || index > list->size) {
        // Process error
    } else {
        NodePtr node = newNode(data);
        NodePtr currentNode = list->head;
        for (int i = 0; i < index; i++) {
            currentNode = currentNode->next;
        }
        node->next = currentNode->next;
        currentNode->next->prev = node;
        node->prev = currentNode;
        currentNode->next = node;
        list->size++;
    }
}


NodePtr getNode(ListPtr list, int index) {
    if (index < 0 || index >= list->size) {
        // Process error
        freeList(list); /* To clear heap if it crashes */
        exit(1);
    } else {
        NodePtr currentNode = list->head->next;
        for (int i = 0; i < index; i++) {
            currentNode = currentNode->next;
        }
        return currentNode;
    }
}


NodeType get(ListPtr list, int index) {
    if (index < 0 || index >= list->size) {
        // Process error
        freeList(list); /* To clear heap if it crashes */
        exit(1);
    } else {
        NodePtr currentNode = getNode(list, index);
        return *currentNode->value;
    }
}


void set(ListPtr list, int index, NodeType data) {
    if (index < 0 || index >= list->size) {
        // Process error
        freeList(list); /* To clear heap if it crashes */
        exit(1);
    } else {
        NodePtr currentNode = getNode(list, index);
        *currentNode->value = data;
    }
}


int isEmpty(ListPtr list) {
    if (list->size == 0) return 1;
    return 0;
}
