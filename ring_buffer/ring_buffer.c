# include <stdio.h>

# include "ring_buffer.h"


RingBufferPtr initializeBuffer(int cap) {
    if (cap < 2) {
        return NULL;
    }
    
    RingBufferPtr temp = (RingBufferPtr)calloc(1, sizeof(RingBuffer));
    temp->head = temp->tail = temp->size = 0;
    temp->capacity = cap;
    
    temp->array = (int *)malloc(cap * sizeof(int));
    
    return temp;
}


void resizeBuffer(RingBufferPtr buff) {
    int newCapacity = 2 * buff->capacity;
    int *temp = (int *)malloc(newCapacity * sizeof(int));
    for (int i = 0; i < buff->size; ++i) {
        int idx = (buff->tail + i) % buff->capacity;
        temp[i] = buff->array[idx];
    }
    
    free(buff->array);
    buff->array = temp;
    
    buff->capacity = newCapacity;
    buff->tail = 0;
    buff->head = buff->size;
}


void push(RingBufferPtr buff, int item) {
    if (buff->size == buff->capacity) {
        resizeBuffer(buff);
    }
    
    buff->array[buff->head] = item;
    buff->head = (buff->head + 1) % buff->capacity;
    buff->size++;
}


int pop(RingBufferPtr buff) {
    int temp = buff->array[buff->head];
    buff->head--;
    
    if (buff->head == -1) {
        buff->head = buff->capacity - 1;
    }

    buff->size--;
    return temp;
}


void enqueue(RingBufferPtr buff, int item) {
    push(buff, item);
}


int dequeue(RingBufferPtr buff) {
    int idx = buff->tail;
    int temp = buff->array[idx];
    buff->tail = (buff->tail + 1) % buff->capacity;
    buff->size--;
    
    return temp;
}


void printBuffer(RingBufferPtr buff) {
    int i = buff->tail;
    printf("%d ", buff->array[i]);

    for (i = i + 1; (i % buff->capacity) != buff->head; ++i) {
        i = i % buff->capacity;
        printf("%d ", buff->array[i]);
    }
    printf("\n");
}


void freeBuffer(RingBufferPtr temp) {
    free(temp->array);
    free(temp);
}
