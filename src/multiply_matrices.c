#include "multiply_matrices.h"

void multiply_matrices(
    const float *const multiplier,
    const float *const multiplicand,
    float *const product)
{
  const float multiplier_0 = multiplier[0];
  const float multiplier_1 = multiplier[1];
  const float multiplier_2 = multiplier[2];
  const float multiplier_3 = multiplier[3];
  const float multiplier_4 = multiplier[4];
  const float multiplier_5 = multiplier[5];
  const float multiplier_6 = multiplier[6];
  const float multiplier_7 = multiplier[7];
  const float multiplier_8 = multiplier[8];
  const float multiplier_9 = multiplier[9];
  const float multiplier_10 = multiplier[10];
  const float multiplier_11 = multiplier[11];
  const float multiplier_12 = multiplier[12];
  const float multiplier_13 = multiplier[13];
  const float multiplier_14 = multiplier[14];
  const float multiplier_15 = multiplier[15];

  const float multiplicand_0 = multiplicand[0];
  const float multiplicand_1 = multiplicand[1];
  const float multiplicand_2 = multiplicand[2];
  const float multiplicand_3 = multiplicand[3];
  const float multiplicand_4 = multiplicand[4];
  const float multiplicand_5 = multiplicand[5];
  const float multiplicand_6 = multiplicand[6];
  const float multiplicand_7 = multiplicand[7];
  const float multiplicand_8 = multiplicand[8];
  const float multiplicand_9 = multiplicand[9];
  const float multiplicand_10 = multiplicand[10];
  const float multiplicand_11 = multiplicand[11];
  const float multiplicand_12 = multiplicand[12];
  const float multiplicand_13 = multiplicand[13];
  const float multiplicand_14 = multiplicand[14];
  const float multiplicand_15 = multiplicand[15];

  product[0] = multiplicand_0 * multiplier_0 + multiplicand_4 * multiplier_1 + multiplicand_8 * multiplier_2 + multiplicand_12 * multiplier_3;
  product[1] = multiplicand_1 * multiplier_0 + multiplicand_5 * multiplier_1 + multiplicand_9 * multiplier_2 + multiplicand_13 * multiplier_3;
  product[2] = multiplicand_2 * multiplier_0 + multiplicand_6 * multiplier_1 + multiplicand_10 * multiplier_2 + multiplicand_14 * multiplier_3;
  product[3] = multiplicand_3 * multiplier_0 + multiplicand_7 * multiplier_1 + multiplicand_11 * multiplier_2 + multiplicand_15 * multiplier_3;
  product[4] = multiplicand_0 * multiplier_4 + multiplicand_4 * multiplier_5 + multiplicand_8 * multiplier_6 + multiplicand_12 * multiplier_7;
  product[5] = multiplicand_1 * multiplier_4 + multiplicand_5 * multiplier_5 + multiplicand_9 * multiplier_6 + multiplicand_13 * multiplier_7;
  product[6] = multiplicand_2 * multiplier_4 + multiplicand_6 * multiplier_5 + multiplicand_10 * multiplier_6 + multiplicand_14 * multiplier_7;
  product[7] = multiplicand_3 * multiplier_4 + multiplicand_7 * multiplier_5 + multiplicand_11 * multiplier_6 + multiplicand_15 * multiplier_7;
  product[8] = multiplicand_0 * multiplier_8 + multiplicand_4 * multiplier_9 + multiplicand_8 * multiplier_10 + multiplicand_12 * multiplier_11;
  product[9] = multiplicand_1 * multiplier_8 + multiplicand_5 * multiplier_9 + multiplicand_9 * multiplier_10 + multiplicand_13 * multiplier_11;
  product[10] = multiplicand_2 * multiplier_8 + multiplicand_6 * multiplier_9 + multiplicand_10 * multiplier_10 + multiplicand_14 * multiplier_11;
  product[11] = multiplicand_3 * multiplier_8 + multiplicand_7 * multiplier_9 + multiplicand_11 * multiplier_10 + multiplicand_15 * multiplier_11;
  product[12] = multiplicand_0 * multiplier_12 + multiplicand_4 * multiplier_13 + multiplicand_8 * multiplier_14 + multiplicand_12 * multiplier_15;
  product[13] = multiplicand_1 * multiplier_12 + multiplicand_5 * multiplier_13 + multiplicand_9 * multiplier_14 + multiplicand_13 * multiplier_15;
  product[14] = multiplicand_2 * multiplier_12 + multiplicand_6 * multiplier_13 + multiplicand_10 * multiplier_14 + multiplicand_14 * multiplier_15;
  product[15] = multiplicand_3 * multiplier_12 + multiplicand_7 * multiplier_13 + multiplicand_11 * multiplier_14 + multiplicand_15 * multiplier_15;
}
