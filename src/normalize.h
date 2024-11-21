#ifndef NORMALIZE_H

#define NORMALIZE_H

/**
 * Approximately normalizes the length of a 3D vector (producing a unit vector).
 * @param vector The 3D vector to normalize.  Behavior is undefined if
 *               zero-length or if any component is NaN, infinity or negative
 *               infinity.
 * @param normal The 3D vector to write the resulting approximate unit vector
 *               to.  May overlap with the input vector.
 */
void normalize(const float *const vector, float *const normal);

#endif
