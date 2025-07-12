#ifndef MULTIPLY_3_1_H

#define MULTIPLY_3_1_H

/**
 * Multiplies a 3D vector by a scalar.
 * @param multiplier The 3D vector to multiply.  Behavior is undefined if
 * any component is NaN, infinity or negative infinity.
 * @param multiplicand The scalar to multiply by.  Behavior is undefined if NaN,
 * infinity or negative infinity.
 * @param output The 3D vector to write the resulting product 3D vector to.
 * May overlap with the input vector.
 */
void multiply_3_1(const float *const multiplier, const float multiplicand,
                  float *const output);

#endif
