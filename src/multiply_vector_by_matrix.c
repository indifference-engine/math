#include "multiply_vector_by_matrix.h"

void multiply_vector_by_matrix(const float *const multiplier,
                               const float *const multiplicand,
                               float *const product) {
  const float multiplier_x = multiplier[0];
  const float multiplier_y = multiplier[1];
  const float multiplier_z = multiplier[2];

  product[0] = multiplicand[0] * multiplier_x + multiplicand[1] * multiplier_y +
               multiplicand[2] * multiplier_z + multiplicand[3];
  product[1] = multiplicand[4] * multiplier_x + multiplicand[5] * multiplier_y +
               multiplicand[6] * multiplier_z + multiplicand[7];
  product[2] = multiplicand[8] * multiplier_x + multiplicand[9] * multiplier_y +
               multiplicand[10] * multiplier_z + multiplicand[11];
}
