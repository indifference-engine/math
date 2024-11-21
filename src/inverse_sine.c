#include "inverse_sine.h"
#include "inverse_sine_table.h"

float inverse_sine(const float sine)
{
  if (sine >= 0.0f)
  {
    const float pre_multiplied = sine * 255.0f;
    int index = pre_multiplied;

    if (index < 0)
    {
      index = 0;
    }
    else if (index > 254)
    {
      index = 254;
    }

    const float remainder = pre_multiplied - index;

    const float previous = inverse_sine_table[index];
    const float next = inverse_sine_table[index + 1];

    return previous + (next - previous) * remainder;
  }
  else
  {
    const float pre_multiplied = sine * -255.0f;
    int index = pre_multiplied;

    if (index < 0)
    {
      index = 0;
    }
    else if (index > 254)
    {
      index = 254;
    }

    const float remainder = pre_multiplied - index;

    const float previous = inverse_sine_table[index];
    const float next = inverse_sine_table[index + 1];

    return -(previous + (next - previous) * remainder);
  }
}
