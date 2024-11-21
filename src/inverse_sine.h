#ifndef INVERSE_SINE_H

#define INVERSE_SINE_H

/**
 * Calculates the angle of a given sine.
 * @param sine The sine to calculate the angle of.  Behavior is undefined
 *             if NaN, less then -1 or greater than 1.
 * @return The angle of the given sine, in radians.
 */
float inverse_sine(const float sine);

#endif
