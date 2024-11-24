#ifndef LOOK_AT_H

#define LOOK_AT_H

/**
 * Calculates a 4x4 model matrix positioned at a location to "look" from,
 * orienting X+ towards a location to "look" at, and its inverse.
 * @param from_x The X axis of the location to "look" from, in world space.
 *               Behavior is undefined if NaN, infinity or negative infinity.
 * @param from_y The Y axis of the location to "look" from, in world space.
 *               Behavior is undefined if NaN, infinity or negative infinity.
 * @param from_z The Z axis of the location to "look" from, in world space.
 *               Behavior is undefined if NaN, infinity or negative infinity.
 * @param to_x The X axis of the location to "look" at, in world space.
 *             Behavior is undefined if NaN, infinity or negative infinity, or
 *             coincident with the location to "look" from.
 * @param to_y The Y axis of the location to "look" at, in world space.
 *             Behavior is undefined if NaN, infinity or negative infinity, or
 *             coincident with the location to "look" from.
 * @param to_z The Z axis of the location to "look" at, in world space.
 *             Behavior is undefined if NaN, infinity or negative infinity, or
 *             coincident with the location to "look" from.
 * @param y_x The X axis of the normal along which to align the Y+ axis.
 *            Behavior is undefined if NaN, aligned with from -> to or not unit
 *            length.
 * @param y_y The Y axis of the normal along which to align the Y+ axis.
 *            Behavior is undefined if NaN, aligned with from -> to or not unit
 *            length.
 * @param y_z The Z axis of the normal along which to align the Y+ axis.
 *            Behavior is undefined if NaN, aligned with from -> to or not unit
 *            length.
 * @param forward The 4x4 matrix to which to write the result.
 * @param inverse The 4x4 matrix to which to write the inverse of result.
 */
void look_at(
    const float from_x,
    const float from_y,
    const float from_z,
    const float to_x,
    const float to_y,
    const float to_z,
    const float y_x,
    const float y_y,
    const float y_z,
    float *const forward,
    float *const inverse);

#endif
