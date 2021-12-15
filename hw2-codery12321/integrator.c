#include "hw2.h"
double integrate1(Range rng)
{

  /* Fill in for Part 1 */
  double sum = 0;

  for (int i = 0; i < rng.intervals; i++)
  {
    sum += func(rng.lowerlimit + (i * ((rng.upperlimit - rng.lowerlimit) / rng.intervals)));
  }

  sum = ((rng.upperlimit - rng.lowerlimit) / rng.intervals) * sum ;

  return sum;

}

void integrate2(RangeAnswer * rngans)
{
    /* Fill in for Part 2 */
    rngans -> answer = integrate1(rngans -> rng);
}
