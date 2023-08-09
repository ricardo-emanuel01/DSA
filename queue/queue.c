# include <stdlib.h>
# include <stdio.h>
# include "queue.h"

void initializeQueue(QueuePtr queue) {
    queue->front = 0;
    queue->rear = 0;
    queue->count = 0;
}

void enqueue(QueuePtr queue, Item_type item) {
    if (isFull(queue)) Error("The queue is full!");
    queue->entry[queue->rear++] = item;
    queue->rear = queue->rear % MAXQUEUE;
    queue->count++;
}

void dequeue(QueuePtr queue, Item_type *item) {
    if (isEmpty(queue)) Error("The queue is empty!");
    *item = queue->entry[queue->front++];
    queue->front = queue->front % MAXQUEUE;
    queue->count--;
}

bool isFull(QueuePtr queue) { return (queue->count >= MAXQUEUE); }

bool isEmpty(QueuePtr queue) { return (queue->count == 0); }

void Error(char *s) {
    fprintf(stderr, "%s\n", s);
    exit(1);
}
