#include "dot_product_3.h"

float dot_product_3(const float *const multiplier,
                    const float *const multiplicand) {
  return multiplier[0] * multiplicand[0] + multiplier[1] * multiplicand[1] +
         multiplier[2] * multiplicand[2];
}
