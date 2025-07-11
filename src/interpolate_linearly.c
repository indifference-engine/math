#include "interpolate_linearly.h"

float interpolate_linearly(const float from, const float to,
                           const float unit_interval) {
  return from + (to - from) * unit_interval;
}
