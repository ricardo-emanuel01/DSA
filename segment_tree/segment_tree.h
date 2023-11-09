# include <stdlib.h>


typedef struct ST {
    int *segmentT, *A, n;
} SegmentTree;


int left(int);

int right(int);

SegmentTree *initializeSegmentTree(int *, int);

void build(SegmentTree *, int, int, int);

int rmqAux(SegmentTree *, int, int, int, int, int);

int rmq(SegmentTree *, int, int);

void freeSegmentTree(SegmentTree *);
