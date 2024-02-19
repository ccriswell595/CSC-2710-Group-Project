



void heapsort (int n, heap H, const S[])
{
    makeheap(n, H);
    removekeys(n, H, S);
}

void removekeys(int n, heap& H, const S[])
{
    index i;
    for(i=n; i>= 1; i--)
        S[i] = root(H);
}

void makeheap(int n, heap& H)
{
    index i;

    H.heapsize = n;
    for(i = [n/2]; i>=1; i--)
        siftdown(H, i);
}

keytype root(heap&, H)
{
    keytype keyout;
    keyout = key;
    //move key at the bottom of the node to the root
    // delete the bottom node
    siftdown(H);
    return keyout;
}

void siftdown(heap& H)
{
    index parent, lchild;
    keytype siftkey;
    bool found;

    siftkey = H.S[i];
    parent = i;
    found = false;
    
    while(parent <= H.heapsize && ! found)
    {
        if(parent < H.heapsize && H.S[parent] < H.S[parent + 1])
            lchild = parent + 1;
        else
            lchild = parent;
        if(siftkey < H.S[lchild])
        {
            H.S[parent] = H.S[lchild]
            parent = lchild
        }
        else 
        found = true;
    }
    H.S[parent] = siftkey;
}

struct heap
{
    const S[1..n];
    int heapsize;
}

