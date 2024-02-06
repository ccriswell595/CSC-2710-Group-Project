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
    copy S[1] through S[h] to U[1] through U[h];
    copy S[ h + 1] through S[n] to V[1] through V[m];
    mergesort(h, U);
    mergesort(m, V);
    merge( h, m, U, V, S );
  }
}
