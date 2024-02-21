/********************************************************
* Colton Criswell, 
* Course: CSC2710-01
* Date: 2/20/2024
* Description:
**********************************************************/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include "sortingAlgorithms.h" //includes the functions for all the sorting algorithms in separate files
using namespace std;

void displayMenu();
int* fillList(int* arr, int length);
void outputList(int arr[], int length);
void almostSorted(int* arr, int length);
void reverseSorted(int* arr, int length);
void manyDuplicates(int* arr, int length);

int main()
{
    int choice = 0;
    int length;
    int input = -1;
    double time = 0;
    int* arr = nullptr; //initialize the pointer array to null

    displayMenu();
    cin >> choice;
    while (choice != 7 && choice > 0 && choice < 8) {
        cout << endl;
        cout << "Enter array size (non negative (greater than 10)): ";
        cin >> length;
        arr = new int[length]; //allocate memory for an array of size length
        fillList(arr, length); //fill list with random numbers; we will decide after what data set we want

        cout << "\nEnter Dataset Type" << endl; 
        cout << "--------------------" << endl;
        cout << "1. Randomly Distrubuted" << endl;
        cout << "2. Almost Sorted" << endl;
        cout << "3. Reverse Sorted" << endl;
        cout << "4. Set with many duplicates" << endl;  
        cin >> input;
        cout << endl;
        while (input < 1 && input > 4)
        {
            cout << "Enter Dataset Type" << endl;
            cout << "--------------------" << endl;
            cout << "1. Randomly Distrubuted" << endl;
            cout << "2. Almost Sorted" << endl;
            cout << "3. Reverse Sorted" << endl;
            cout << "4. Set with many duplicates" << endl;  
            cin >> input;
            cout << endl;
        }
    
        switch (input) {
            case 1:
                break;
            case 2:
                almostSorted(arr, length);
                break;
            case 3:
                reverseSorted(arr, length);
                break;
            case 4:
                manyDuplicates(arr, length);
                break;
            default:
                cout << "Invalid choice. Please choose a number between 1 and 5." << endl;
        }

        auto start = chrono::steady_clock::now(); //record start time

        switch (choice) {
            case 1:
                outputList(arr, length);
                selectionsort(arr, length);
                break;
            case 2:
                outputList(arr, length);
                //bubbleSort(arr, length);
                break;
            case 3:
                outputList(arr, length);
                //insertionSort(arr, length);
                break;
            case 4:
                outputList(arr, length);
                mergesort(arr, 0, length - 1);
                break;
            case 5:
                outputList(arr, length);
                quicksort(arr, 0, length - 1);
                break;
            case 6:
                outputList(arr, length);
                //heapSort(arr, length);
                break;
            default:
                cout << "Invalid choice. Please choose a number between 1 and 7." << endl;
        }
        auto end = chrono::steady_clock::now(); //record end time

        chrono::microseconds elapsed = chrono::duration_cast<chrono::microseconds>(end - start);
        time = elapsed.count();

        cout << "First 10 elements of sorted array: " << endl; //only output first and last 10 elements to show it is sorted
        for (int i=0; i<10; i++)
                cout << i+1 << ": " << arr[i] << endl;
        cout << endl;
        cout << "Last 10 elements of sorted array: " << endl;
        for (int i=length-1; i>=length-11; i--)
            cout << i+1 << ": " << arr[i] << endl;
        cout << endl;

        cout << "Time: " << time << " microseconds" << endl;
            
        delete[] arr; //deallocate memory

        displayMenu();
        cin >> choice;
    }

    return 0;
}

void displayMenu()
{
    cout << "--------------------------------------------------------------------------" << endl;
    cout << "Choose Your Sorting Algorithm or 7 to quit program." << endl;
    cout << "1. Selection Sort" << endl;
    cout << "2. Bubble Sort" << endl;
    cout << "3. Insertion Sort" << endl;
    cout << "4. Merge Sort" << endl;
    cout << "5. Quick Sort" << endl;
    cout << "6. Heap Sort" << endl;
    cout << "7. Quit" << endl << endl;
    cout << "Enter your choice: ";
}

int* fillList(int arr[], int length) //fills the array with random numbers from 0-length
{
    srand(time(NULL));

    for (int i = 0; i < length; i++) {
        int num = rand() % length + 1;
        arr[i] = num;
    }
    return arr;
}

void outputList(int arr[], int length) //outputs the array before the sorting
{
    cout << "First 10 elements of original array: " << endl;
    for (int i=0; i<10; i++)
        cout << i+1 << ": " << arr[i] << endl;
    cout << endl;
}

void almostSorted(int* arr, int length) //uses quicksort to sort the array and then swaps the first 10% of the array with the last 10%
{
    quicksort(arr, 0, length - 1);
    int temp;

    for (int i = 0; i < length / 10; i++) {
        temp = arr[i];
        arr[i] = arr[length - i - 1];
        arr[length - i - 1] = temp;
    }   
}

void reverseSorted(int* arr, int length) //uses quicksort to sort the array and then swaps the first and last elements, incrementing and decrementing until it reaches the middle
{
    quicksort(arr, 0, length - 1);
    int temp;

    for (int i = 0; i < length / 2; i++) {
        temp = arr[i];
        arr[i] = arr[length - i - 1];
        arr[length - i - 1] = temp;
    }
}

void manyDuplicates(int* arr, int length) //essentially uses modulo and rand() to make every element a digit 1-10
{
    srand(time(NULL));

    for (int i = 0; i < length; i++) {
        int num = rand() % 10 + 1;
        arr[i] = num;
    }
}

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
