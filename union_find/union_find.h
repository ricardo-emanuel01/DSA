# include <stdlib.h>


typedef struct UnionFind {
    int *p, *rank, *sizes, size;
} UnionFind;


UnionFind *initializeUnionFind(int);

int findSet(UnionFind *, int);

int isSameSet(UnionFind *, int, int);

void unionSet(UnionFind *, int, int);

int numOfSets(UnionFind *);

int sizeOfSet(UnionFind *, int);

void freeUnionFind(UnionFind *);
