



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





/////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>

using namespace std;

// Heapify function to heapify a subtree rooted at index i
void heapify(vector<int>& arr, int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Heap sort function
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

