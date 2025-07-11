#ifndef DOT_PRODUCT_3_H

#define DOT_PRODUCT_3_H

/**
 * Calculates the dot product of two 3D vectors.
 * @param multiplier The first 3D vector to multiply.  Behavior is undefined if
 *                   any component is NaN, infinity or negative infinity.
 * @param multiplicand The first 3D vector to multiply.  Behavior is undefined
 *                     if any component is NaN, infinity or negative infinity.
 * @return product The resulting dot product.
 */
float dot_product_3(const float *const multiplier,
                    const float *const multiplicand);

#endif
