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
  using namespace std::chrono;


void bubbleSort(int arr[], int length) {
   auto start = high_resolution_clock::now(); //time start

    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
   auto stop = high_resolution_clock::now(); //time end
   auto duration = duration_cast<microseconds>(stop - start);

   for(int i = 0; i < length; i++)
          cout << arr[i] << ", ";
   
   cout << "\nTime taken: " << duration.count() << " microseconds" << endl;
   cout << "Comparisons: " << count << endl;
   
}
