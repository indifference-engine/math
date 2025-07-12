#include "add_3_3.h"

void add_3_3(const float *const augend, const float *const addend,
             float *const output) {
  output[0] = augend[0] + addend[0];
  output[1] = augend[1] + addend[1];
  output[2] = augend[2] + addend[2];
}
