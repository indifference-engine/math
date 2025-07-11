#ifndef MULTIPLY_3_3_H

#define MULTIPLY_3_3_H

/**
 * Multiplies a 3D vector by another 3D vector.
 * @param multiplier The 3D vector to multiply.  Behavior is undefined if
 * any component is NaN, infinity or negative infinity.
 * @param multiplicand The 3D vector to multiply.  Behavior is undefined if
 * any component is NaN, infinity or negative infinity.
 * @param output The 3D vector to write the resulting product 3D vector to.
 * May overlap with the input vectors.
 */
void multiply_3_3(const float *const multiplier,
                  const float *const multiplicand, float *const output);

#endif
