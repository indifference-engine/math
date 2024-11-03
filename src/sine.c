#include "stdio.h" // todo
#include "sine_table.h"
#include "sine.h"
#include "pi.h"

float sine(const float radians)
{
  const int period = 510;
  const float unrounded = radians * (period / PI);
  int rounded = unrounded;

  if (rounded > unrounded)
  {
    rounded--;
  }

  const float blend = unrounded - rounded;

  rounded %= 1020;

  if (rounded < 0)
  {
    rounded += period * 2;
  }

  if (rounded < 255)
  {
    return sine_table[rounded] * (1.0f - blend) + sine_table[rounded + 1] * blend;
  }
  else if (rounded < 510)
  {
    return sine_table[510 - rounded] * (1.0f - blend) + sine_table[509 - rounded] * blend;
  }
  else if (rounded < 765)
  {
    return -(sine_table[rounded - 510] * (1.0f - blend) + sine_table[rounded - 509] * blend);
  }
  else
  {
    return -(sine_table[1020 - rounded] * (1.0f - blend) + sine_table[1019 - rounded] * blend);
  }
}
