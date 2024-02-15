/*
Liz Doyle
*/
#include <iostream>

void mergesort (int n, S[])
{
  if (n>1)
  {
    const int h = [ n/2 ], m = n - h;
    U[ 1 .. h ], V[ 1 .. m ];
    
    for ( i = 0; i < h; i++)
    {

    }
    for ( j = h; j < m; j++)
    {

    }
    mergesort(h, U);
    mergesort(m, V);
    merge( h, m, U, V, S );
  }
}

void merge (L, R, S)
{
  nL = length(L);
  nR = length(R);
  index i, j, k = 1;
  while (i ≤ nL && j ≤ nR)
  {
    if (L[i] ≤ R[j])
    {
      S[k] = L[i];
      i++;
    }
    else
    {
      S[k] = R[j];
      j++;
    }
    k++;
  }
}