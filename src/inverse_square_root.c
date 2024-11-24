#include <stdint.h>
#include "inverse_square_root.h"

float inverse_square_root(const float value)
{
  // This implementation is derived from
  // https://bits.stephan-brumme.com/invSquareRoot.html, which is labelled as
  // public domain.

  union
  {
    float as_float;
    uint32_t as_uint32_t;
  } conversion = {value};

  conversion.as_uint32_t = 1597463174 - (conversion.as_uint32_t >> 1);

  return conversion.as_float;
}
