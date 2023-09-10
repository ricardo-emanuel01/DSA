# include <stdio.h>
# include <stdlib.h>

# include "dynamic_array.h"


ArrayPtr initializeArray() {
    ArrayPtr array = (ArrayPtr)malloc(sizeof(Array));
    array->size = 0;
    array->data = (ArrayType *)calloc(5, sizeof(ArrayType));
    if (array->data == NULL) {
        // Process allocation error
    }
    array->capacity = 5;

    return array;
}


void freeArray(ArrayPtr array) {
    free(array->data);
    free(array);
}


void resize(ArrayPtr array) {
    int newSize = array->capacity * 2;
    array->data = realloc(array->data, sizeof(ArrayType)*newSize);
    if (array->data == NULL) {
        // Process error
    }
    array->capacity = newSize;
}


void add(ArrayPtr array, ArrayType value) {
    if (isFull(array)) {
        resize(array);
    }
    array->data[array->size++] = value;
}


void insertAt(ArrayPtr array, int index, ArrayType value) {
    if (index == array->size) {
        add(array, value);
    } else if (index < 0 || index > array->size) {
        // Process error
    } else {
        int counter = 1;
        int newSize = array->size + 1;
        ArrayType temp1 = array->data[index];
        ArrayType temp2;
        array->data[index] = value;

        while((index + counter) < newSize) {
            if (counter % 2 != 0) {
                temp2 = array->data[index + counter];
                array->data[index + counter] = temp1;
            } else {
                temp1 = array->data[index + counter];
                array->data[index + counter] = temp2;
            }
            counter++;
        }
        array->size = newSize;
    }
}


ArrayType pop(ArrayPtr array) {
    if (!isEmpty(array)) return array->data[--array->size];
    else {
        // Process error
        freeArray(array);
        exit(1);
    }
}


void removeAt(ArrayPtr array, int index) {
    if (index < 0 || index >= array->size) {
        // Process error
        return;
    }
    int i;
    int j;
    ArrayType* newData = (ArrayType*)malloc(array->capacity * sizeof(ArrayType));
    for (i = 0, j = 0; i < array->size; i++, j++) {
        if (i == index) j--;
        else newData[j] = array->data[i];
    }
    free(array->data);

    array->data = newData;
    array->size--;
}


int removeKey(ArrayPtr array, ArrayType key) {
    for (int i = 0; i < array->size; i++) {
        if (array->data[i] == key) {
            removeAt(array, i);
            return 1;
        }
    }
    return 0;
}


void set(ArrayPtr array, int index, ArrayType newElement) {
    if (index < 0 || index >= array->size) {
        // Process error
        return;
    }
    array->data[index] = newElement;
}


ArrayType get(ArrayPtr array, int index) {
    if (index < 0 || index >= array->size) {
        // Process error
        exit(1);
    }
    return array->data[index];
}


int isEmpty(ArrayPtr array) {
    if (array->size == 0) return 1;
    return 0;
}


int isFull(ArrayPtr array) {
    if (array->size == array->capacity) return 1;
    return 0;
}


void printArrayInt(ArrayPtr array) {
    int current_size = array->size;
    for (int i = 0; i < current_size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}
