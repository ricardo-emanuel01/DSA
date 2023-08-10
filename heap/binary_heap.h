typedef int ArrayType;

typedef struct _dynArray {
    ArrayType** data;
    int size;
    int capacity;
} Array, *ArrayPtr;


void initializeArray(ArrayPtr);

void freeArray(ArrayPtr);

void resize(ArrayPtr);

void add(ArrayPtr, ArrayType);

void sink(ArrayPtr);

int parentIndex(int);

void childIndex(int, int, int*, int*);

void bubble(ArrayPtr);

ArrayType poll(ArrayPtr);

void swap(ArrayPtr, int, int);

int isEmpty(ArrayPtr);

int isFull(ArrayPtr);
