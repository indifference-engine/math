#ifndef SUBTRACT_3_3_H

#define SUBTRACT_3_3_H

/**
 * Subtracts a 3D vector from another 3D vector.
 * @param minuend The 3D vector to subtract from.  Behavior is undefined if any
 * component is NaN, infinity or negative infinity.
 * @param subtrahend The 3D vector to subtract by.  Behavior is undefined if any
 * component is NaN, infinity or negative infinity.
 * @param output The 3D vector to write the resulting difference 3D vector to.
 * May overlap with the input vectors.
 */
void subtract_3_3(const float *const minuend, const float *const subtrahend,
                  float *const output);

#endif
