#include "multiply_3_1.h"

void multiply_3_1(const float *const multiplier, const float multiplicand,
                  float *const output) {
  output[0] = multiplier[0] * multiplicand;
  output[1] = multiplier[1] * multiplicand;
  output[2] = multiplier[2] * multiplicand;
}
