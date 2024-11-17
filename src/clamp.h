#ifndef CLAMP_H

#define CLAMP_H

/**
 * Clamps a value to between an upper and lower bound.
 * @param value The value to clamp.  Behavior is undefined if NaN.
 * @param lower The lower bound to clamp to.  Behavior is undefined if NaN or
 *              greater than the upper bound.
 * @param upper The upper bound to clamp to.  Behavior is undefined if NaN or
 *              lesser than the lower bound.
 * @return The clamped value.
 */
float clamp(const float value, const float lower, const float upper);

#endif
