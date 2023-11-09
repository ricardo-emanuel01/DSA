# include <stdlib.h>
# include "segment_tree_sum.h"


int left(int p) { return p << 2; }
int right(int p) { return (p << 2) + 1; }


SegmentTree *initializeSegmentTree(int *array, int size) {
    SegmentTree *temp = (SegmentTree *)malloc(sizeof(SegmentTree));
    temp->A = (int *)malloc(size * sizeof(int));
    temp->segmentT = (int *)malloc((4 * size) * sizeof(int));
    temp->n = size;

    for (int i = 0; i < size; i++) {
        temp->A[i] = array[i];
    }
    build(temp, 1, 0, size - 1);

    return temp;
}


void build(SegmentTree *st, int p, int L, int R) {
    if (L == R) st->segmentT[p] = st->A[L];
    else {
        build(st, left(p), L, (L + R) / 2);
        build(st, right(p), (L + R) / 2 + 1, R);
        int p1 = st->segmentT[left(p)];
        int p2 = st->segmentT[right(p)];
        st->segmentT[p] = p1 + p2;
    }
}


int rmqAux(SegmentTree *st, int p, int L, int R, int i, int j) {
    if (i > R || j < L) return -1;
    if (L >= i && R <= j) return st->segmentT[p];

    int p1 = rmqAux(st, left(p), L, (L + R) / 2, i, j);
    int p2 = rmqAux(st, right(p), (L + R) / 2 + 1, R, i, j);

    if (p1 == -1) return p2;
    if (p2 == -1) return p1;

    return p1 + p2;
}


int rmq(SegmentTree *st, int i, int j) {
    return rmqAux(st, 1, 0, st->n - 1, i, j);
}


void freeSegmentTree(SegmentTree *st) {
    free(st->A);
    free(st->segmentT);
    free(st);
}
