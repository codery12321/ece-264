// Do not remove #ifdef ... #endif before and after each function.
//
// They are used to test different functions in your program and give
// partial credits, in case your program does not work completely.

#include "student.h"
#include "msort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void StudentPrint(Student * stu, int num)
{
  printf("There are %d students\n", num);
  for (int ind = 0; ind < num; ind ++)
    {
      printf("ID = %d, First Name = %s, Last Name = %s\n", stu[ind].ID,  stu[ind].firstname, stu[ind].lastname);
    }
}

// return false if anything is wrong
// return true if reading the file successfully and the data is save in
// the allocated memory
// input: filename, the name of the input file
// output: number of students
// output: address of the allocated memory
// count the number of '\n' to determine the number of elements
int countNewLine(FILE * fptr)
{
  int numline = 0;
  while (! feof(fptr))
    {
      int onechar = fgetc(fptr);
      if (onechar == '\n')
	{
	  numline ++;
	}
    }
  return numline;
}

bool StudentRead(char * filename, Student * * stu, int * numelem)
{
  // open the file to read
  FILE * fptr;
  fptr = fopen(filename, "r");
  // if fopen fails, return false
  // do not use fclose since fopen already fails
  if (fptr == NULL)
    {
      return false;
    }
  int numline = countNewLine(fptr);

  // return to the beginning of the file
  // you can use fseek or
  // fclose followed by fopen
  // You need to check whether fseek or fopen fails
  // Do not use rewind because it does not report whether it fails
  int rtv; // return value
  rtv = fseek(fptr, 0, SEEK_SET);
  if (rtv == -1) // fseek fails
    {
      fclose (fptr);
      return false;
    }

  // allocate memory for the data
  printf("There are %d students\n", numline);
  Student * stuptr = malloc(sizeof(* stuptr) * numline);

  // check whether memory allocation fails
  if (stuptr == NULL)
    {
      fclose (fptr);
      return false;
    }
  char oneline[LINE_LENGTH];
  // read the data from the file
  for (int ind = 0; ind < numline; ind ++)
    {
      if (fgets(oneline, LINE_LENGTH, fptr) == NULL) // read fails
	{
	  fclose (fptr);
	  free (stuptr);
	  return false;
	}
      printf("index = %d\n", ind);
      printf("%s\n", oneline);
      rtv = sscanf(oneline, "%d %s %s", & stuptr[ind].ID,
		   stuptr[ind].firstname,
		   stuptr[ind].lastname);
      if (rtv != 3) // read fails
	{
	  fclose (fptr);
	  free (stuptr);
	  return false;
	}
    }
  fclose (fptr);
  * numelem = numline;
  * stu = stuptr;
  return true;
}

bool StudentWrite(char * filename, Student * stu, int numelem)
{
  // open the file to write
  FILE * fptr;
  fptr = fopen(filename, "w");
  // if fopen fails, return false
  // do not use fclose since fopen already fails
  if (fptr == NULL)
    {
      return false;
    }
  int rtv;
  for (int ind = 0; ind < numelem; ind ++)
    {
      rtv = fprintf(fptr, "%d %s %s\n",
		    stu[ind].ID, stu[ind].firstname, stu[ind].lastname);
      if (rtv < 3) // write fails
	{
	  fclose (fptr);
	  return false;
	}
    }
  fclose (fptr);
  return true;
}

/*void sortStudents(Student * stu, int numelem, int (*compar)(const void *, const void *)) {
  //void msort(Student * base, int nel, int (*compar)(const void *, const void *))
    msort(stu, numelem, sizeof(Student), compar);
}*/

#ifdef TEST_SORTID
int compareID(const void * p1, const void * p2)
{
    /* Fill in to compare p1 and p2 by id */
    const Student * n1 = (const Student *) p1;
    const Student * n2 = (const Student *) p2;
    int ans;

    if (n1-> ID > n2-> ID)
    {
      ans = 1;
    }
    else if(n1->ID == n2->ID)
    {
      ans = 0;
    }
    else
    {
      ans = -1;
    }
    return ans;
}
#endif

#ifdef TEST_SORTFIRSTNAME
int compareFirstName(const void * p1, const void * p2)
{
    /* Fill in to compare p1 and p2 by first name */
    const Student * n1 = (const Student *) p1;
    const Student * n2 = (const Student *) p2;
    int ans;

    if (strcmp(n1 -> firstname, n2 -> firstname) > 0)
    {
      ans = 1;
    }
    else if(strcmp(n1 -> firstname, n2 -> firstname) == 0)
    {
      ans = 0;
    }
    else
    {
      ans = -1;
    }
    return ans;
}
#endif

#ifdef TEST_SORTLASTNAME
int compareLastName(const void * p1, const void * p2)
{
    /* Fill in to compare p1 and p2 by last name */
    const Student * n1 = (const Student *) p1;
    const Student * n2 = (const Student *) p2;
    int ans;

    if (strcmp(n1 -> lastname, n2 -> lastname) > 0)
    {
      ans = 1;
    }
    else if(strcmp(n1 -> lastname, n2 -> lastname) == 0)
    {
      ans = 0;
    }
    else
    {
      ans = -1;
    }
    return ans;
}
#endif

#ifdef TEST_SORTED
bool areStudentsSorted(Student * stu, int numelem, int (*compar)(const void *, const void *)) {
    /* Fill in to return true if the stu array is sorted according to compar */
    const void * n1;
    const void * n2; //better not to declare stuff in for loop

    for (int i = 0; i < numelem - 1; i++)
    {
      n1 = (const void *) &stu[i];
      n2 = (const void *) &stu[i + 1];
      if (compar(n1, n2) > 0)
      {
        return false;
      }
    }
    return true;
}
#endif
