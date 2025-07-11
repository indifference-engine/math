#include "square_root.h"
#include <stdint.h>

float square_root(const float value) {
  // This implementation is derived from
  // https://bits.stephan-brumme.com/squareRoot.html, which is labelled as
  // public domain.

  union {
    float as_float;
    uint32_t as_uint32_t;
  } conversion = {value};

  conversion.as_uint32_t += 1065353216;
  conversion.as_uint32_t >>= 1;

  return conversion.as_float;
}
