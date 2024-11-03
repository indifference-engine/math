#ifndef MULTIPLY_VECTOR_BY_MATRIX_H

#define MULTIPLY_VECTOR_BY_MATRIX_H

/**
 * Multiplies a vector by a matrix.
 * @remark Do NOT use to convert to or from clip space - no W division is
 *         performed.
 * @param multiplier The 3-dimensional vector to multiply.  Behavior is
 *                   undefined if any are NaN, infinity or negative infinity.
 * @param multiplicand The 4x4 matrix to multiply by.  Behavior is undefined if
 *                     any are NaN, infinity or negative infinity.
 * @param product Overwritten with the multiplied 3-dimensional vector.  May be
 *                "multiplier".
 */
void multiply_vector_by_matrix(
    const float *const multiplier,
    const float *const multiplicand,
    float *const product);

#endif
