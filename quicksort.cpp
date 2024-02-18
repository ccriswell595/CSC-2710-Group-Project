//Colton Criswell
//quicksort.cpp

#include <iostream>
#include <ctime>
#include <chrono>
   
using namespace std;

void partition(int arr[], int low, int high, int* pivot); 

void quicksort(int arr[], int low, int high)
{
    if (low < high) {
        int pivot;
        partition(arr, low, high, &pivot); 
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
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

int main() 
{
    int arr[100000];
    for (int i = 0; i < 100000; i++) {
        arr[i] = rand() % 100000;
    }
    quicksort(arr, 0, 99999);
    return 0;
}
