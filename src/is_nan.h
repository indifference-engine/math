#ifndef IS_NAN_H

#define IS_NAN_H

#include <stdbool.h>

/**
 * Determines whether a given float is not a number.
 * @param value The float to check.
 * @return When the given float is not a number, true, otherwise, false.
 */
bool is_nan(float value);

#endif
