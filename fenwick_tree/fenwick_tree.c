# include "fenwick_tree.h"

// O primeiro elemento está no index 1
void buildFenwickTree(FenwickTreePtr tree, long *array, int size) {
    tree->data = (long *)malloc((size + 1) * sizeof(long));
    tree->size = size;
    
    copyValues(tree, array);
    
    int j;
    for (int i = 1; i < size + 1; i++) {
        j = i + lsb(i);
        if (j < size) tree->data[j] += tree->data[i];
    }
}


void freeFenwickTree(FenwickTreePtr tree) {
    free(tree->data);
    free(tree);
}


long prefixSum(FenwickTreePtr tree, int index) {
    long sum = 0L;
    
    while (index != 0) {
        sum += tree->data[index];
        index -= lsb(index);
    }
    return sum;
}


long sumInterval(FenwickTreePtr tree, int indexEnd, int indexBegin) {
    if (indexBegin < indexEnd) {
        freeFenwickTree(tree);
        exit(1);
    }
    return prefixSum(tree, indexEnd) - prefixSum(tree, indexBegin - 1);
}


void updateAt(FenwickTreePtr tree, int index, long value) {
    if (index < 1) {
        freeFenwickTree(tree);
        exit(1);
    }
    while (index < tree->size + 1) {
        tree->data[index] += value;
        index += lsb(index);
    }
}


void set(FenwickTreePtr tree, int index, long newValue) {
    if (index < 1) {
        freeFenwickTree(tree);
        exit(1);
    }
    long oldValue = sumInterval(tree, index, index);
    updateAt(tree, index, newValue - oldValue);
}


void get(FenwickTreePtr tree, int index) {
    if (index < 1) {
        freeFenwickTree(tree);
        exit(1);
    }
    return sumInterval(tree, index, index);
}


void copyValues(FenwickTreePtr tree, long *array) {
    for (int i = 1; i < tree->size + 1; i++) tree->data[i] = array[i - 1];
}


int lsb(int n) {
    return n & -n;
}
