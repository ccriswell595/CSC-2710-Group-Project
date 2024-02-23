//Colton Criswell
//quicksort.cpp
#include "sortingAlgorithms.h"
#include <iostream>

void partition(int arr[], int low, int high, int* pivot); 
void quicksort(int arr[], int low, int high)
{
    int counter = 0;
    if (low < high) {
        int pivot;
        partition(arr, low, high, &pivot); 
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
        counter++;
    }
    return; 
}

void partition(int arr[], int low, int high, int* pivot) 
{
    int counter = 0;
    int mid = low + (high - low) / 2;
    int pivotIndex = (arr[low] < arr[mid]) ? //use conditional logic to find the median of the 3 points
                     ((arr[mid] < arr[high]) ? mid : ((arr[low] < arr[high]) ? high : low)):
                     ((arr[high] < arr[mid]) ? mid : ((arr[high] < arr[low]) ? high : low));

    // Swap the pivot element with the element at the low index
    std::swap(arr[low], arr[pivotIndex]);


    int pivotVal = arr[low];
    int i = low + 1;
    int j = high;

    while (true) 
    {
        while (i <= j && arr[i] <= pivotVal) {
            i++;
            counter++;
        }
        while (i <= j && arr[j] > pivotVal) {
            j--;
            counter++;
        }
        if (i >= j) {
            break;
        }
        std::swap(arr[i], arr[j]);
    }
    std::swap(arr[low], arr[j]);
    *pivot = j; // Update the pivot index through the pointer
}
