#include "cross_product.h"

void cross_product(
    const float *const multiplier,
    const float *const multiplicand,
    float *const product)
{
  const float x = multiplier[1] * multiplicand[2] - multiplicand[1] * multiplier[2];
  const float y = multiplier[2] * multiplicand[0] - multiplicand[2] * multiplier[0];
  const float z = multiplier[0] * multiplicand[1] - multiplicand[0] * multiplier[1];
  product[0] = x;
  product[1] = y;
  product[2] = z;
}
