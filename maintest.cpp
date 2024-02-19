/********************************************************
* Colton Criswell, 
* Course: CSC2710-01
* Date: 
* Description:
**********************************************************/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "sortingAlgorithms.h"

using namespace std;

void displayMenu();
int* fillList(int* arr, int length);

int main()
{
    int choice=0;
    int length;

    displayMenu();
    cin >> choice;
    while (choice != 7) {

        cout << endl;
        cout << "Enter array size (non negative (greater than 10)): ";
        cin >> length;

        int* arr = new int[length];
        fillList(arr, length);

        int time = 0;

        switch (choice) {
            case 1:
                //selectionSort(arr, length);
                break;
            case 2:
                //bubbleSort(arr, length);
                break;
            case 3:
                //insertionSort(arr, length);
                break;
            case 4:
                //mergeSort(arr, 0, length - 1);
                break;
            case 5:
                quicksort(arr, 0, length - 1);
                break;
            case 6:
                //heapSort(arr, length);
                break;
            default:
                cout << "Invalid choice. Please choose a number between 1 and 7." << endl;
        }
        cout << endl;
        cout << "First 10 elements of sorted array: " << endl;
        for (int i=0; i<10; i++)
            {
                cout << i+1 << ": " << arr[i] << endl;
            }
        cout << endl;
        cout << "Time: " << time << " nanoseconds" << endl;
            
        delete[] arr;

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

int* fillList(int arr[], int length)
{
    srand(time(NULL));

    for (int i = 0; i < length; i++) {
        int num = rand() % length + 1;
        arr[i] = num;
    }

    return arr;
}
