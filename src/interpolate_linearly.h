#ifndef INTERPOLATE_LINEARLY_H

#define INTERPOLATE_LINEARLY_H

/**
 * Linearly interpolates between two values.
 * @param from The value to linearly interpolate from.  Behavior is undefined if
 *             NaN, infinity or negative infinity.
 * @param to The value to linearly interpolate to.  Behavior is undefined if
 *           NaN, infinity or negative infinity.
 * @param unit_interval 0 = from, 1 = to.  Extrapolates linearly beyond this
 *                      range.  Behavior is undefined if NaN, infinity or
 *                      negative infinity.
 * @return The linearly interpolated value.
 */
float interpolate_linearly(const float from, const float to, const float unit_interval);

#endif
