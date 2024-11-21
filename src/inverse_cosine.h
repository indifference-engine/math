#ifndef INVERSE_COSINE_H

#define INVERSE_COSINE_H

/**
 * Calculates the angle of a given cosine.
 * @param cosine The cosine to calculate the angle of.  Behavior is undefined
 *             if NaN, less then -1 or greater than 1.
 * @return The angle of the given cosine, in radians.
 */
float inverse_cosine(const float cosine);

#endif
