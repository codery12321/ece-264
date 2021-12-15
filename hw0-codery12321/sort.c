#include "sort.h"

#ifdef ASCENDING
void ssort(int * arr, int size)
{
  int i, j, swap;

  for(i = 0;i < size; i++)
  {

    for(j = 0; j < size; j++)
    {

      if( *(arr + j) > *(arr + i))
      {
         swap = *(arr + i);
         *(arr + i) = *(arr + j);
         *(arr + j) = swap;
      }
    }
  }
}
#else
void ssort(int * arr, int size)
{
        /* For step 3, fill this in to perform a selection sort
 *            For step 4, add conditional compilation flags to perform an ascending selection sort instead */
  int i, j, swap;

  for(i = 0; i < size; i++)
  {

    for(j = 0; j < size; j++)
    {

      if( *(arr + i) > *(arr + j))
      {
         swap = *(arr + i);
         *(arr + i) = *(arr + j);
         *(arr + j) = swap;
      }
    }
  }
}

#endif

