// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#ifdef TEST_COUNTINT
int countInt(char * filename)
{
  // count the number of integers in the file
  // Please notice that if a file contains
  // 124 378 -56
  // There are three integers: 124, 378, -56
  // DO NOT count individual character '1', '2', '4' ...
  FILE * fptr = fopen(filename, "r");
  // If fopen fails, return -1
  if(fptr == NULL)
  {
    fprintf(stderr, "file open fail\n");
    return -1;
  }
  int count = 0;

  for (int c = getc(fptr); c != EOF; c = getc(fptr))
  {
    if (c == '\n') // Increment count if this character is newline
    {
      count = count + 1;
    }
  }

  fclose(fptr);
  return count;
  // remember to fclose if fopen succeeds
}
#endif

#ifdef TEST_READINT
bool readInt(char* filename, int * intArr, int size)
{
  FILE * fptr = fopen(filename, "r");
  // if fopen fails, return false
  // read integers from the file
  if (fptr == NULL)
  {
    fprintf(stderr, "fopen input fail\n");
    return false;
  }
  // if the number of integers is different from size (too
  // few or too many) return false
  for (int i = 0; i < size; i++)
  {
    fscanf(fptr, "%d", &intArr[i]);
  }
  //fprintf(stderr, "%d %d\n",intArr[10], size);

  /*if(sizeof(intArr) != size)
  {
    fprintf(stderr, "fopen input fail\n");
    fclose(fptr);
    return false;
  }*/
  // if everything is fine, fclose and return true
  fclose(fptr);
  return true;
}
#endif

#ifdef TEST_COMPAREINT
int compareInt(const void *p1, const void *p2)
{
  // needed by qsort
  const int * n1 = (const int *) p1;
  const int * n2 = (const int *) p2;
  int ans;

  if (*n1 > *n2)
  {
    ans = 1;
  }
  else if(*n1 == *n2)
  {
    ans = 0;
  }
  else
  {
    ans = -1;
  }
  return ans;
  // return an integer less than, equal to, or greater than zero if
  // the first argument is considered to be respectively less than,
  // equal to, or greater than the second.
}
#endif

#ifdef TEST_WRITEINT
bool writeInt(char* filename, int * intArr, int size)
{
  // if fopen fails, return false
  // write integers to the file.
  // one integer per line
  FILE * fptr = fopen(filename, "w");
  if (fptr == NULL)
  {
    fprintf(stderr, "fopen input fail\n");
    return false;
  }
  for(int i = 0; i < size; i++)
  {
    fprintf(fptr, "%d\n", intArr[i]);
  }
  // fclose and return true
  fclose(fptr);
  return true;
}
#endif
