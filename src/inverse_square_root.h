#ifndef INVERSE_SQUARE_ROOT_H

#define INVERSE_SQUARE_ROOT_H

/**
 * Calculates the approximate inverse square root of a float.
 * @param value The float of which to calculate an approximate inverse square
 *              root.  Behavior is undefined if NaN, infinity or less than or
 *              equal to zero.
 * @return The calculated approximate inverse square root.
 */
float inverse_square_root(const float value);

#endif
