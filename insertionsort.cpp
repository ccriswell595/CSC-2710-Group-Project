// Chris Smith
// insertionSort.cpp

   #include "sortingAlgorithms.h"
   #include <iostream>
   #include <ctime>
   #include <chrono>
   
  using namespace std;
  using namespace std::chrono;

void insertionSort(int arr[], int length)
{
      int count = 0;
      int x;
      
      //testing array, int S[] = {7, 5 , 2, 4, 6, 8, 1, 9, 3, 10};
   
      auto start = high_resolution_clock::now(); //time start
  
      for(int i = 1; i < length; i++)
      {
          x = arr[i];
          int j = i-1;
 
          while(j >= 0 && arr[j] > x)
          {
              arr[j + 1] = arr[j];
              j--;
              count++;
          }
          arr[j + 1] = x;
      }
 
      auto stop = high_resolution_clock::now(); //time end
  
      auto duration = duration_cast<microseconds>(stop - start);
      
   int time = duration.count();
      return time;
      return count;
   
}   
