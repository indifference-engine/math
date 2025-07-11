#include "clamp.h"

float clamp(const float value, const float lower, const float upper) {
  return value < lower ? lower : (value > upper ? upper : value);
}
