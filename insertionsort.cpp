// Chris Smith
// insertionSort.cpp
// g++ insertionSort.cpp -o insert.out
// ./insert.out
   
   #include <iostream>
   #include <ctime>
   #include <chrono>
   
  using namespace std;
  using namespace std::chrono;

void insertionSort(int arr[], int length)
{
      int length;
      int arr[length];
      int count = 0;
      int x;
      
      //testing array, int S[] = {7, 5 , 2, 4, 6, 8, 1, 9, 3, 10};
   
      auto start = high_resolution_clock::now();
  
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
 
      auto stop = high_resolution_clock::now();
  
      auto duration = duration_cast<microseconds>(stop - start);
  // shows first 10 sorted numbers
      for(int i = 0; i < 10; i++)
          cout << arr[i] << ", ";
   
   cout << "\nTime taken: " << duration.count() << " microseconds" << endl;
   cout << "Comparisons: " << count << endl;
}   
