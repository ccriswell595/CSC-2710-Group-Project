/*
   Hannah Bush
   bubblesort.cpp
   g++ bubblesort.cpp -o bubble.out
   ./bubble.out
*/ 
   #include "sortingAlgorithms.h"
   #include <iostream>
   #include <ctime>
   #include <chrono>
   
  using namespace std;


void bubbleSort(int arr[], int length) {
   int counter = 0;
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        counter++;
        }
    counter++;
    }

   for(int i = 0; i < length; i++)
          cout << arr[i] << ", ";

   
}
