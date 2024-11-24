#ifndef JOINTED_LOOK_AT_H

#define JOINTED_LOOK_AT_H

/**
 * Calculates 4x4 model matrices which place proximal and distal halves of a
 * limb to fill a span between a location to "look" from and a location to
 * "look" to, and its inverse.  The bend is aligned with the Z+ axis.
 * @param from_x The X axis of the location to "look" from, in world space.
 *               Behavior is undefined if NaN, infinity or negative infinity.
 * @param from_y The Y axis of the location to "look" from, in world space.
 *               Behavior is undefined if NaN, infinity or negative infinity.
 * @param from_z The Z axis of the location to "look" from, in world space.
 *               Behavior is undefined if NaN, infinity or negative infinity.
 * @param length The length of the limb when fully extended.  Behavior is
 *               undefined if NaN, infinity, less than or equal to zero.
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
 * @param proximal_forward The 4x4 matrix to which to write the result for the
 *                         proximal half.
 * @param proximal_inverse The 4x4 matrix to which to write the inverse of
 *                         result for the proximal half.
 * @param distal_forward The 4x4 matrix to which to write the result for the
 *                       distal half.
 * @param distal_inverse The 4x4 matrix to which to write the inverse of result
 *                       for the distal half.
 */
void jointed_look_at(
    const float from_x,
    const float from_y,
    const float from_z,
    const float length,
    const float to_x,
    const float to_y,
    const float to_z,
    const float z_x,
    const float z_y,
    const float z_z,
    float *const proximal_forward,
    float *const proximal_inverse,
    float *const distal_forward,
    float *const distal_inverse);

#endif
