#include <stdbool.h>
#include "is_nan.h"

bool is_nan(float value)
{
  return value != value;
}
