# include <stdlib.h>


typedef struct RingBuffer {
    int head, tail;
    int size, capacity;
    int *array;
} RingBuffer, *RingBufferPtr;


RingBufferPtr initializeBuffer(int);

void resizeBuffer(RingBufferPtr);

void push(RingBufferPtr, int);

int pop(RingBufferPtr);

void enqueue(RingBufferPtr, int);

int dequeue(RingBufferPtr);

void printBuffer(RingBufferPtr);

void freeBuffer(RingBufferPtr);
