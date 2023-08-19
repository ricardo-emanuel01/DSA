# include <stdlib.h>


typedef struct {
    long *data;
    int size;
} FenwickTree, *FenwickTreePtr;


void buildFenwickTree(FenwickTreePtr, long *, int);

void freeFenwickTree(FenwickTreePtr);

long prefixSum(FenwickTreePtr, int);

long sumInterval(FenwickTreePtr, int, int);

void updateAt(FenwickTreePtr, int, long);

void set(FenwickTreePtr, int, long);

long get(FenwickTreePtr, int);

void copyValues(FenwickTreePtr, long *);

int lsb(int);
