# include <stdbool.h>

# define MAXQUEUE 5


typedef int Item_type;


typedef struct queue_tag{
    Item_type entry[MAXQUEUE];
    int count;
    int front;
    int rear;
} Queue, *QueuePtr;


void initializeQueue(QueuePtr);

void enqueue(QueuePtr, Item_type);

void dequeue(QueuePtr, Item_type *);

bool isFull(QueuePtr);

bool isEmpty(QueuePtr);

void Error(char *);
