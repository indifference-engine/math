#include "subtract_3_3.h"

void subtract_3_3(const float *const minuend, const float *const subtrahend,
                  float *const output) {
  output[0] = minuend[0] - subtrahend[0];
  output[1] = minuend[1] - subtrahend[1];
  output[2] = minuend[2] - subtrahend[2];
}
