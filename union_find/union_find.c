# include "union_find.h"


UnionFind *initializeUnionFind(int n) {
    UnionFind *temp = (UnionFind *)malloc(sizeof(UnionFind));
    temp->size = n;
    temp->sizes = (int *)malloc(n * sizeof(int));
    temp->p = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        temp->sizes[i] = 1;
        temp->p[i] = i;
    }

    temp->rank = (int *)calloc(n, sizeof(int));

    return temp;
}


int findSet(UnionFind *ufds, int i) {
    return (ufds->p[i] == i) ? i : (ufds->p[i] = findSet(ufds, ufds->p[i]));
}


int isSameSet(UnionFind *ufds, int i, int j) {
    return findSet(ufds, i) == findSet(ufds, j);
}


void unionSet(UnionFind *ufds, int i, int j) {
    if (!isSameSet(ufds, i, j)) {
        int x = findSet(ufds, i);
        int y = findSet(ufds, j);

        if (ufds->rank[x] > ufds->rank[y]) {
            ufds->p[y] = x;
            ufds->sizes[x] += ufds->sizes[y];
        } else {
            ufds->p[x] = y;
            ufds->sizes[y] += ufds->sizes[x];
            if (ufds->rank[x] == ufds->rank[y]) ufds->rank[y]++;
        }
    }
}


int numOfSets(UnionFind *ufds) {
    int num = 0;
    for (int i = 0; i < ufds->size; i++) {
        if (ufds->p[i] == i) num++;
    }
    return num;
}


int sizeOfSet(UnionFind *ufds, int i) {
    int representative = findSet(ufds, i);
    return ufds->sizes[representative];
}


void freeUnionFind(UnionFind *ufds) {
    free(ufds->p);
    free(ufds->sizes);
    free(ufds->rank);
    free(ufds);
}
