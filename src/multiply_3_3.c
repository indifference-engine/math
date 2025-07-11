#include "multiply_3_3.h"

void multiply_3_3(const float *const multiplier,
                  const float *const multiplicand, float *const output) {
  output[0] = multiplier[0] * multiplicand[0];
  output[1] = multiplier[1] * multiplicand[1];
  output[2] = multiplier[2] * multiplicand[2];
}
