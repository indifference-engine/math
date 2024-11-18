#include "absolute.h"

float absolute(const float value)
{
  return value >= 0.0f ? value : -value;
}
