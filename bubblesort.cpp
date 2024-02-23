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
   cout << "Comparisons: " << counter << endl;

   
}

int main()
{
      int counter;
      int arr[] = { };
        int arrsize = sizeof(arr) / sizeof(arr[0]);
        auto start = chrono::steady_clock::now(); //record start time
        bubblesort(arr, r, length;

                auto end = chrono::steady_clock::now(); //record end time

        chrono::microseconds elapsed = chrono::duration_cast<chrono::microseconds>(end - start);
        int time = elapsed.count();
        cout << "Time: " << time << " microseconds" << endl;

        cout << "Sorted: ";
        for(int i = 0; i <arrsize; i++)
        {
           cout << arr[i] << " ";
        }
        cout << "counter: ";
        cout << counter;
        cout << endl;

        return 0;
