#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include "sortingAlgorithms.h"
using namespace std;
void selectionSort(int n, int s[]);
void randomArray(int n, int s[]);
void nearlySorted(int n,int ne[]);
void reversed(int n, int re[]);
void fewUnique(int n, int fe[]);



int main()
{

int n=10;
int s[n];
randomArray(n,s);
int ne[n]= {1,2,4,3,6,7,5,8,9,0};
nearlySorted(n, ne);
int re[n] ={0,9,8,7,6,5,4,3,2,1};
reversed(n, ne);
n=12;
int fe[n]= {3,4,3,4,5,7,6,8,6,5,6,8};
fewUnique(n, fe);

return 0;
}

//selection sort code
void selectionSort(int n, int s[])
{
//time start
auto start = std::chrono::system_clock::now();
 
int temp;
int i, j, smallest;
for(i=1; i<=n-2; i++)
 {
   smallest=i;
   for(j=i+1; j<=n-1; j++)
       if (s[j]<s[smallest])
          smallest=j;

     temp = s[i];
     s[i] = s[smallest];
     s[smallest] = temp;

  //time end
auto end = std::chrono::system_clock::now();


std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "sort time  " << elapsed_seconds.count() << "s"
              << std::endl;
 }
   
//random array initialize aand sort
void randomArray(int n, int s[])
{
//fill array with random
for ( int a = 0; a<n; a++)
   {int r = rand()%1000;
     s[a]=r;
   }

int i;


//time start
auto start = std::chrono::system_clock::now();

//selection sort call
selectionSort(n, s);

//time end
auto end = std::chrono::system_clock::now();

for (i=0; i<n; i++)
  cout<<s[i]<<endl;

std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "sort time for random: " << elapsed_seconds.count() << "s"
              << std::endl;

}
//nearly sorted array and call sort
void nearlySorted(int n, int ne[])
{
//time start
auto start = std::chrono::system_clock::now();

//selection sort call
selectionSort(n, ne);

//time end
auto end = std::chrono::system_clock::now();



std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "sort time for nearly Sorted array: " << elapsed_seconds.count() << "s"
              << std::endl;
}


//reverseres sorted
void reversed(int n, int re[])
{
//time start
auto start = std::chrono::system_clock::now();

//selection sort call
selectionSort(n, re);

//time end
auto end = std::chrono::system_clock::now();



std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "sort time for reversed: " << elapsed_seconds.count() << "s"
              << std::endl;

}

void fewUnique(int n, int fe[])
{

//time start
auto start = std::chrono::system_clock::now();

//selection sort call
selectionSort(n, fe);

//time end
auto end = std::chrono::system_clock::now();


std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "sort time for few unique: " << elapsed_seconds.count() << "s"
              << std::endl;
}


}
