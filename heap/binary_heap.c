# include <stdio.h>
# include <stdlib.h>

# include "binary_heap.h"


void initializeArray(ArrayPtr heap) {
    heap->size = 0;
    heap->data = (ArrayType**)calloc(5, sizeof(ArrayType*));
    if (heap->data == NULL) {
        // Process allocation error
    }
    heap->capacity = 5;
}


void freeArray(ArrayPtr heap) {
    for (int i = 0; i < heap->size; i++) free(heap->data[i]);
    free(heap->data);
    free(heap);
}


void resize(ArrayPtr heap) {
    int newSize = heap->capacity * 2;
    heap->data = (ArrayType**)realloc(heap->data, sizeof(ArrayType*)*newSize);
    if (heap->data == NULL) {
        // Process error
    }
    heap->capacity = newSize;
}


void add(ArrayPtr heap, ArrayType data) {
    if (isFull(heap)) {
        resize(heap);
    }
    ArrayType* value = (ArrayType*)calloc(1, sizeof(ArrayType));
    *value = data;
    heap->data[heap->size++] = value;
    bubble(heap);
}


void sink(ArrayPtr heap) {
    int indexFirstChild, indexSecondChild;
    int flag = 0;
    int index = 0;
    childIndex(heap->size, index, &indexFirstChild, &indexSecondChild);
    while (indexFirstChild != -1 || indexSecondChild != -1) {
        printf("FirstIndex: %d, SecondIndex: %d\n", indexFirstChild, indexSecondChild);
        if (indexSecondChild != -1) {
            // Both of them exists
            if (*heap->data[indexFirstChild] <= *heap->data[indexSecondChild]) {
                flag = 1;
            } else {
                flag = 2;
            }
            switch (flag) {
                case 1:
                    if (*heap->data[index] > *heap->data[indexFirstChild]) {
                        swap(heap, index, indexFirstChild);
                        index = indexFirstChild;
                    }
                    flag = 0;
                    break;
                case 2:
                    if (*heap->data[index] > *heap->data[indexSecondChild]) {
                        swap(heap, index, indexSecondChild);
                        index = indexSecondChild;
                    }
                    flag = 0;
                    break;
            }
        } else {
            // Only one of them exist
            if (*heap->data[index] > *heap->data[indexFirstChild]) {
                swap(heap, index, indexFirstChild);
                index = indexFirstChild;
            }
        }
        childIndex(heap->size, index, &indexFirstChild, &indexSecondChild);
    }
}


int parentIndex(int index) {
    if (index % 2 == 0) {
        return (index - 2) / 2;
    } else {
        return (index - 1) / 2;
    }
}


void childIndex(int heapSize, int index, int* firstChild, int* secondChild) {
    int possibleFirstIndex = index * 2 + 1;
    int possibleSecondIndex = index * 2 + 2;
    
    if (possibleFirstIndex < heapSize) {
        *firstChild = possibleFirstIndex;
    } else {
        *firstChild = -1;
    }

    if (possibleSecondIndex < heapSize) {
        *secondChild = possibleSecondIndex;
    } else {
        *secondChild = -1;
    }
}


void bubble(ArrayPtr heap) {
    int index = heap->size - 1;
    int indexToCmp = parentIndex(index);
    
    while (indexToCmp >= 0 && *heap->data[index] < *heap->data[indexToCmp]) {
        swap(heap, index, indexToCmp);
        index = indexToCmp;
        indexToCmp = parentIndex(index);
    }
}


ArrayType poll(ArrayPtr heap) {
    ArrayType temp = *heap->data[0];
    int index = heap->size - 1;
    swap(heap, 0, index);
    free(heap->data[index]);
    heap->size--;
    sink(heap);
    return temp;
}


void swap(ArrayPtr heap, int index1, int index2) {
    ArrayType* temp = heap->data[index1];
    heap->data[index1] = heap->data[index2];
    heap->data[index2] = temp;
}


int isEmpty(ArrayPtr heap) {
    if (heap->size == 0) return 1;
    return 0;
}


int isFull(ArrayPtr array) {
    if (array->size == array->capacity) return 1;
    return 0;
}
