#include <iostream>
#include "sortingAlgorithms.h"

typedef int keytype;

void heapsort(int n, heap& H, keytype S[]);
void removekeys(int n, heap& H, keytype S[]);
void makeheap(int n, heap& H);
keytype root(heap& H);
void siftdown(heap& H, int i);

void heapsort(int n, heap& H, keytype S[])
{
    H.S = S;
    makeheap(n, H);
    removekeys(n, H, S);
}

void removekeys(int n, heap& H, keytype S[])
{
    int i;
    for (i = n; i > 0; i--)
        S[i] = root(H);
}

void makeheap(int n, heap& H)
{
    int i;
    H.heapsize = n;
    for (i = n / 2; i >= 0; i--)
        siftdown(H, i);
}

keytype root(heap& H)
{
    keytype keyout = H.S[0];
    H.S[0] = H.S[H.heapsize--];
    siftdown(H, 0);
    return keyout;
}

void siftdown(heap& H, int i)
{
    int lchild;
    keytype siftkey;
    bool found;

    siftkey = H.S[i];
    int parent = i;
    found = false;

    while (parent * 2 <= H.heapsize && !found)
    {
        lchild = parent * 2;
        if (lchild < H.heapsize && H.S[lchild] < H.S[lchild + 1])
            lchild++;
        if (siftkey < H.S[lchild])
        {
            H.S[parent] = H.S[lchild];
            parent = lchild;
        }
        else
            found = true;
    }
    H.S[parent] = siftkey;
}
