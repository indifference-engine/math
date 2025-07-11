#ifndef INTERPOLATE_LINEARLY_3_3_1_H

#define INTERPOLATE_LINEARLY_3_3_1_H

/**
 * Linearly interpolates between two 3D vectors.
 * @param from The 3D vector to linearly interpolate from.  Behavior is
               undefined if any component is NaN, infinity or negative infinity.
 * @param to The 3D vector to linearly interpolate to.  Behavior is undefined if
 *           any component is NaN, infinity or negative infinity.
 * @param unit_interval 0 = from, 1 = to.  Extrapolates linearly beyond this
 *                      range.  Behavior is undefined if NaN, infinity or
 *                      negative infinity.
 * @param output The 3D vector to write the resulting linearly interpolated 3D
 *               vector to.  May overlap with the input vectors.
 */
void interpolate_linearly_3_3_1(const float *const from, const float *const to,
                                const float unit_interval, float *const output);

#endif
