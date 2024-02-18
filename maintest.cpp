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
int* fillList(int length);

int main()
{
    int choice;
    int* arr;
    int length;

    while (true) {
        displayMenu();
        cin >> choice;

        if (choice == 7) {
            cout << "Exiting Program..." << endl;
            break;
        }

        cout << "Enter array size (<= 100): ";
        cin >> length;

        if (length <= 0 || length > 100) {
            cout << "Invalid array size. Please enter a size between 1 and 100." << endl;
            continue;
        }

        arr = fillList(length);

        switch (choice) {
            case 1:
                selectionSort(arr, length);
                break;
            case 2:
                bubbleSort(arr, length);
                break;
            case 3:
                insertionSort(arr, length);
                break;
            case 4:
                mergeSort(arr, 0, length - 1);
                break;
            case 5:
                quickSort(arr, 0, length - 1);
                break;
            case 6:
                heapSort(arr, length);
                break;
            default:
                cout << "Invalid choice. Please choose a number between 1 and 7." << endl;
        }

        delete[] arr;
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

int* fillList(int length)
{
    int* arr = new int[length];
    srand(time(NULL));

    for (int i = 0; i < length; i++) {
        int num = rand() % 101;
        arr[i] = num;
    }

    return arr;
}
