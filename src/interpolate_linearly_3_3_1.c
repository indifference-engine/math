#include "interpolate_linearly_3_3_1.h"
#include "interpolate_linearly.h"

void interpolate_linearly_3_3_1(const float *const from, const float *const to,
                                const float unit_interval,
                                float *const output) {
  output[0] = interpolate_linearly(from[0], to[0], unit_interval);
  output[1] = interpolate_linearly(from[1], to[1], unit_interval);
  output[2] = interpolate_linearly(from[2], to[2], unit_interval);
}
