#include "sine_table.h"
#include "cosine.h"
#include "pi.h"

float cosine(const float radians)
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
    return sine_table[255 - rounded] * (1.0f - blend) + sine_table[254 - rounded] * blend;
  }
  else if (rounded < 510)
  {
    return -(sine_table[rounded - 255] * (1.0f - blend) + sine_table[rounded - 254] * blend);
  }
  else if (rounded < 765)
  {
    return -(sine_table[765 - rounded] * (1.0f - blend) + sine_table[764 - rounded] * blend);
  }
  else
  {
    return sine_table[rounded - 765] * (1.0f - blend) + sine_table[rounded - 764] * blend;
  }
}
