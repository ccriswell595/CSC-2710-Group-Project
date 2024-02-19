//Colton Criswell
//quicksort.cpp
#include "sortingAlgorithms.h"
#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;

void partition(int arr[], int low, int high, int* pivot); 
int quicksort(int arr[], int low, int high)
{
    auto start = std::chrono::high_resolution_clock::now(); // Record start time
    if (low < high) {
        int pivot;
        partition(arr, low, high, &pivot); 
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
       
    }
    auto end = std::chrono::high_resolution_clock::now(); // Record end time

    std::chrono::nanoseconds elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    int time= elapsed.count();
    return time;
}

void partition(int arr[], int low, int high, int* pivot) 
{
    int pivotVal = arr[low];
    int i = low + 1;
    int j = high;

    while (true) 
    {
        while (i <= j && arr[i] <= pivotVal) {
            i++;
        }
        while (i <= j && arr[j] > pivotVal) {
            j--;
        }
        if (i >= j) {
            break;
        }
        swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    *pivot = j; // Update the pivot index through the pointer
}
