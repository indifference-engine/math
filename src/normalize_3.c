#include "normalize_3.h"
#include "inverse_square_root.h"
#include <stdint.h>

void normalize_3(const float *const vector, float *const normal) {
  const float inverse_magnitude = inverse_square_root(
      vector[0] * vector[0] + vector[1] * vector[1] + vector[2] * vector[2]);
  normal[0] = vector[0] * inverse_magnitude;
  normal[1] = vector[1] * inverse_magnitude;
  normal[2] = vector[2] * inverse_magnitude;
}
