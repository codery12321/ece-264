// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#ifdef TEST_ELIMINATE
// 100% of the score
void eliminate(int n, int k)
{
  // allocate an arry of n elements
  int * arr = malloc(sizeof(* arr) * n);
  // check whether memory allocation succeeds.
  // if allocation fails, stop
  if (arr == NULL)
    {
      fprintf(stderr, "malloc fail\n");
      return;
    }

  // Note that from here on, you can access elements of the arr with
  // expressions like a[i]

  // initialize all elements
  int count = 1;
  int ind = 0;
  int eliminated = 0;

  for(int i = 0; i < n; i++)
  {
    arr[i] = 0;
  }

  // counting to k,
  // mark the eliminated element
  // print the index of the marked element
  // repeat until only one element is unmarked
  while (eliminated < n - 1)
  {
    if(arr[ind] == 0)
    {
      if(count == k)
      {
        count = 1;
        printf("%d\n", ind);
        arr[ind] = -1;
        eliminated++;
      }
      else
      {
        count++;
      }
    }
    if (ind < n - 1)
    {
      ind++;
    }
    else
    {
      ind = 0;
    }
  }
  // print the last one
  for(int j = 0; j < n; j++)
  {
    if(arr[j] == 0)
    {
      printf("%d\n", j);
    }
  }



  // release the memory of the array
  free (arr);
}
#endif
