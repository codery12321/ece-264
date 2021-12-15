// ***
// *** You MUST modify this file.
// ***
#include <stdio.h>
#include <stdbool.h>
#include "hw3.h"

// must enclose the function by #ifdef TEST_INTEGRATE
// and #endif to enable particial credits
#ifdef TEST_INTEGRATE
void integrate(Integration * intrg)
{
  // integrate the function stored in intrg's func
  // store the result in intrg's answer
  intrg -> answer = 0;

  for (int i = 0; i < intrg -> intervals; i++)
  {
    intrg -> answer += intrg -> func(intrg -> lowerlimit + (i * ((intrg -> upperlimit - intrg -> lowerlimit) / intrg -> intervals)));
  }

  intrg -> answer = ((intrg -> upperlimit - intrg -> lowerlimit) / intrg -> intervals) * intrg -> answer ;


}
 #endif // TEST_INTEGRATE

// must enclose the function by #ifdef RUN_INTEGRATE
// and #endif to enable particial credits

#ifdef RUN_INTEGRATE
bool  runIntegrate(char * infilename, char * outfilename)
// return true if it can successfully open and read the input
// and open and write the output
// return false when encountering any problem
{
  // open the input file name for reading
  FILE * fptr = fopen(infilename, "r");

  // if fopen fails, return false
  if (fptr == NULL)
  {
    fprintf(stderr, "fopen input fail\n");
    return false;

  }

  // read one double from the input file and store it in
  // intrg's lowerlimit
  // use fscanf
  // check the return value. If the return value is not one
  // close the file and return false
  Integration intrg;
  int val;

  val = fscanf(fptr, "%lf\n", &intrg.lowerlimit);
  if (val != 1)
  {
    fprintf(stderr, "scanf fail");
    fclose(fptr);
    return false;

  }


  // read one double from the input file and store it in
  // intrg's upperlimit
  // use fscanf
  // check the return value. If the return value is not one
  // close the file and return false

  val = fscanf(fptr, "%lf\n", &intrg.upperlimit);
  if (val != 1)
  {
    fprintf(stderr, "scanf fail");
    fclose(fptr);
    return false;

  }

  // read one int from the input file and store it in
  // intrg's intervals
  // use fscanf
  // check the return value. If the return value is not one
  // close the file and return false

  val = fscanf(fptr, "%d\n", &intrg.intervals);
  if (val != 1)
  {
    fprintf(stderr, "scanf fail");
    fclose(fptr);
    return false;

  }

  // close the input file
  fclose(fptr);

  // open the output file for writing
  // if fopen fails, return false
  fptr = fopen(outfilename, "w");

  if (fptr == NULL)
  {
    fprintf(stderr, "fopen output fail\n");
    return false;

  }

  // create an array of funcptr called funcs with five elements:
  // func1, func2, ..., func5
  funcptr funcs[5] = {func1, func2, func3, func4, func5};

  // go through the elements in funcs
  // for each element, call integrate for that function
  // write the result (stored in intrg's answer to
  // the output file. each answer occupies one line (add "\n")
  // use fprintf

  for (int i = 0; i < 5; i++)
  {
    intrg.func = funcs[i];
    integrate(&intrg);
    val = fprintf(fptr, "%lf\n", intrg.answer);
  }

  // check the return value of fprintf.
  // If it is less one one, close the output
  // file and return false
  if (val < 1)
  {
    fclose(fptr);
    return false;

  }

  // after going through all functions in funcs
  // close the output file
  fclose(fptr);

  // if the function reaches here, return true
  return true;

}
#endif // RUN_INTEGRATE
