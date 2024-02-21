#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

void selectionsort(int arr[], int length);
void bubbleSort(int arr[], int length);
//void insertionSort(int arr[], int length);
void mergesort(int arr[], int start, int end);
void quicksort(int arr[], int low, int high);
struct heap {
    int *S;
    int heapsize;
};
void heapsort(int n, heap& H, int S[]);


#endif 
