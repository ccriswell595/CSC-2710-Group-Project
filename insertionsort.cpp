// Chris Smith
// insertionSort.cpp
// g++ insertionSort.cpp -o insert.out
// ./insert.out
   
   #include <iostream>
   #include <ctime>
   #include <chrono>
   
  using namespace std;
  using namespace std::chrono;
  
  int main()
  {
      int size = 10;
      int S[] = {7, 5, 2, 4, 6, 8, 1, 9, 3, 10};
  
      int x;
  
      auto start = high_resolution_clock::now();
  
      for(int i = 1; i < size; i++)
      {
          x = S[i];
          int j = i-1;
 
          while(j >= 0 && S[j] > x)
          {
              S[j + 1] = S[j];
              j--;
          }
          S[j + 1] = x;
      }
 
      auto stop = high_resolution_clock::now();
  
      auto duration = duration_cast<nanoseconds>(stop - start);
  
      for(int i = 0; i < size; i++)
          cout << S[i] << ", ";
   cout << "\n Time taken: " << duration.count() << " nanoseconds" << endl;
   return 0;
 }   
