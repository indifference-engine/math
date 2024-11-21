#ifndef CROSS_PRODUCT_H

#define CROSS_PRODUCT_H

/**
 * Calculates the cross product of two 3D vectors.
 * @param multiplier The first 3D vector to multiply.  Behavior is undefined if
 *                   any component is NaN, infinity or negative infinity.
 * @param multiplicand The first 3D vector to multiply.  Behavior is undefined
 *                     if any component is NaN, infinity or negative infinity.
 * @param product The 3D vector to write the resulting cross product to.  May
 *                overlap with the multiplier and/or multiplicand.
 */
void cross_product(
    const float *const multiplier,
    const float *const multiplicand,
    float *const product);

#endif
