#include "../../src/multiply_3_1.h"
#include <stdio.h>

static int exit_code = 0;

static void given(const float multiplier_x, const float multiplier_y,
                  const float multiplier_z, const float multiplicand,
                  const float expected_x, const float expected_y,
                  const float expected_z) {
  const float unshared_multiplier[] = {multiplier_x, multiplier_y,
                                       multiplier_z};
  float unshared[3];

  multiply_3_1(unshared_multiplier, multiplicand, unshared);

  if (unshared_multiplier[0] != multiplier_x) {
    printf("Multiplier X changed unexpectedly.\n");
    exit_code = 1;
  }

  if (unshared_multiplier[1] != multiplier_y) {
    printf("Multiplier Y changed unexpectedly.\n");
    exit_code = 1;
  }

  if (unshared_multiplier[2] != multiplier_z) {
    printf("Multiplier Z changed unexpectedly.\n");
    exit_code = 1;
  }

  if (unshared[0] != expected_x) {
    printf("FAIL multiply_3_1([%f, x, x], %f) = [%f, x, "
           "x] (expected %f)\n",
           multiplier_x, multiplicand, unshared[0], expected_x);
    exit_code = 1;
  }

  if (unshared[1] != expected_y) {
    printf("FAIL multiply_3_1([x, %f, x], %f) = [x, %f, "
           "x] (expected %f)\n",
           multiplier_y, multiplicand, unshared[1], expected_y);
    exit_code = 1;
  }

  if (unshared[2] != expected_z) {
    printf("FAIL multiply_3_1([x, x, %f], %f) = [x, x, "
           "%f] (expected %f)\n",
           multiplier_z, multiplicand, unshared[2], expected_z);
    exit_code = 1;
  }

  float shared_multiplier_multiplier[] = {multiplier_x, multiplier_y,
                                          multiplier_z};

  multiply_3_1(shared_multiplier_multiplier, multiplicand,
               shared_multiplier_multiplier);

  if (shared_multiplier_multiplier[0] != expected_x) {
    printf("FAIL multiply_3_1([%f, x, x], %f) = [%f, x, "
           "x] (expected %f)\n",
           multiplier_x, multiplicand, shared_multiplier_multiplier[0],
           expected_x);
    exit_code = 1;
  }

  if (shared_multiplier_multiplier[1] != expected_y) {
    printf("FAIL multiply_3_1([x, %f, x], %f) = [x, %f, "
           "x] (expected %f)\n",
           multiplier_y, multiplicand, shared_multiplier_multiplier[1],
           expected_y);
    exit_code = 1;
  }

  if (shared_multiplier_multiplier[2] != expected_z) {
    printf("FAIL multiply_3_1([x, x, %f], %f) = [x, x, "
           "%f] (expected %f)\n",
           multiplier_z, multiplicand, shared_multiplier_multiplier[2],
           expected_z);
    exit_code = 1;
  }
}

int main(const int argc, const char *const *const argv) {
  (void)(argc);
  (void)(argv);

  given(2.0f, -8.0f, -4.0f, 0.9f, 1.8f, -7.2f, -3.6f);

  return exit_code;
}
