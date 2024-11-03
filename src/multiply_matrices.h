#ifndef MULTIPLY_MATRICES_H

#define MULTIPLY_MATRICES_H

/**
 * Calculates the product of two matrices.
 * @param multiplier The first 4x4 matrix to multiply.  Behavior is undefined if
 *                   any are NaN, infinity or negative infinity.
 * @param multiplicand The second 4x4 matrix to multiply.  Behavior is undefined
 *                     if any are NaN, infinity or negative infinity.
 * @param product The 4x4 matrix to which to write the result.  May be
 *                "multiplier", "multiplicand" or both.
 */
void multiply_matrices(
    const float *const multiplier,
    const float *const multiplicand,
    float *const product);

#endif
