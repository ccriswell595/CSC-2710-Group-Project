/*
Liz Doyle
CSC 2710
mergesort.cpp
g++ mergesort.cpp -o merge.out
./merge.out
*/

#include "sortingAlgorithms.h"
#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;

void merge(int* arr, int start, int mid, int end)
{   
    int leftPtr = start; 
    int rightPtr = mid + 1; 
    int mergedArrSize = end - start + 1;
    int mergedArray[mergedArrSize];
    
    int i = 0;
    while(leftPtr <= mid && rightPtr <= end)
    {   
        if(arr[leftPtr] <= arr[rightPtr])
        {   
            mergedArray[i] = arr[leftPtr];
            leftPtr++;
        }
        else
        {   
            mergedArray[i] = arr[rightPtr];
            rightPtr++;
        }
        i++;
    }
    
    while(leftPtr <= mid)
    {   
        mergedArray[i] = arr[leftPtr];
        leftPtr += 1;
        i++;
    }
    
    while(rightPtr <= end)
    {   
        mergedArray[i] = arr[rightPtr];
        rightPtr += 1;
        i++;
    }
    
    for (int j = 0; j < mergedArrSize; j++)
    {   
      arr[start + j] = mergedArray[j];
    }
}

void mergesort (int arr[], int start, int end)
{
  if (start < end)
  {
    int mid = (start + end)/2;
    int lower[mid];
    int upper[end];

    for (int i = 0; i < mid; i++)
    {
      lower[i] = arr[i];
    }

    for(int j = mid - 1; j < end; j++)
    {
      upper[j] = arr[j];
    }
    mergesort(arr, start, mid);
    mergesort(arr, mid + 1, end);
    merge(arr, start, mid, end);
  }
}

int main()
{
        int arr[] = {1, 7, 8, 2, 3, 5, 4, 6};
        int arrsize = sizeof(arr) / sizeof(arr[0]);

        mergesort(arr, 0, arrsize - 1);

        cout << "Sorted: ";
        for(int i = 0; i <arrsize; i++)
        {
           cout << arr[i] << " ";
        }

        cout << endl;

        return 0;
}1,1           Top
