#include "is_nan.h"
#include <stdbool.h>

bool is_nan(const float value) { return value != value; }
