#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include "sortingAlgorithms.h"
using namespace std;
//int selectionSort(int s[], int n);



   //selection sort code
int selectionsort(int s[], int n)
{
   //time start
 auto start = std::chrono::high_resolution_clock::now();
int temp;
int count = 0;
int i, j, smallest;
for(i=1; i<=n-2; i++)
 {
   smallest=i;
   for(j=i+1; j<=n-1; j++)
   {
      count++;
       if (s[j]<s[smallest])
          smallest=j;
   
     temp = s[i];
     s[i] = s[smallest];
     s[smallest] = temp;
   }
 }
  //time end
auto end = std::chrono::high_resolution_clock::now(); 
std::chrono::nanoseconds elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    int time= elapsed.count();
cout << "comepares: " << count << endl;
   return time;
 }
   
  
