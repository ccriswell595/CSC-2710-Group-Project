// Chris Smith
// insertionSort.cpp
// g++ insertionSort.cpp -o insert.out
// ./insert.out
   
   #include <iostream>
   #include <ctime>
   #include <chrono>
   
  using namespace std;
  using namespace std::chrono;

void insertionSort(arr[], int length)
{
      int length;
      int S[length];
      int count = 0;
      int x;
      
      //testing array, int S[] = {7, 5 , 2, 4, 6, 8, 1, 9, 3, 10};
   
      auto start = high_resolution_clock::now();
  
      for(int i = 1; i < length; i++)
      {
          x = S[i];
          int j = i-1;
 
          while(j >= 0 && S[j] > x)
          {
              S[j + 1] = S[j];
              j--;
              count++;
          }
          S[j + 1] = x;
      }
 
      auto stop = high_resolution_clock::now();
  
      auto duration = duration_cast<microseconds>(stop - start);
  // shows first 50 sorted numbers
      for(int i = 0; i < 50; i++)
          cout << S[i] << ", ";
   
   cout << "\nTime taken: " << duration.count() << " microseconds" << endl;
   cout << "Comparisons: " << count << endl;
}   
