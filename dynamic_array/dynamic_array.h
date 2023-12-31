typedef int ArrayType;

typedef struct _dynArray {
    ArrayType* data;
    int size;
    int capacity;
} Array, *ArrayPtr;


ArrayPtr initializeArray();

void freeArray(ArrayPtr);

void resize(ArrayPtr);

void add(ArrayPtr, ArrayType);

void insertAt(ArrayPtr, int, ArrayType);

ArrayType pop(ArrayPtr);

void removeAt(ArrayPtr, int);

int removeKey(ArrayPtr, ArrayType);

void set(ArrayPtr, int, ArrayType);

ArrayType get(ArrayPtr, int);

int isEmpty(ArrayPtr);

int isFull(ArrayPtr);

void printArrayInt(ArrayPtr);
