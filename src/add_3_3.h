#ifndef ADD_3_3_H

#define ADD_3_3_H

/**
 * Adds a 3D vector to another 3D vector.
 * @param augend The 3D vector to add to.  Behavior is undefined if any
 * component is NaN, infinity or negative infinity.
 * @param addend The 3D vector to add.  Behavior is undefined if any component
 * is NaN, infinity or negative infinity.
 * @param output The 3D vector to write the resulting sume 3D vector to. May
 * overlap with the input vectors.
 */
void add_3_3(const float *const augend, const float *const addend,
             float *const output);

#endif
