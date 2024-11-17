#include <stdbool.h>
#include "is_nan.h"

bool is_nan(const float value)
{
  return value != value;
}
