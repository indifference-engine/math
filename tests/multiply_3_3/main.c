#include "../../src/multiply_3_3.h"
#include <stdio.h>

static int exit_code = 0;

static void given(const float multiplier_x, const float multiplier_y,
                  const float multiplier_z, const float multiplicand_x,
                  const float multiplicand_y, const float multiplicand_z,
                  const float expected_x, const float expected_y,
                  const float expected_z) {
  const float unshared_multiplier[] = {multiplier_x, multiplier_y,
                                       multiplier_z};
  const float unshared_multiplicand[] = {multiplicand_x, multiplicand_y,
                                         multiplicand_z};
  float unshared[3];

  multiply_3_3(unshared_multiplier, unshared_multiplicand, unshared);

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

  if (unshared_multiplicand[0] != multiplicand_x) {
    printf("Multiplicand X changed unexpectedly.\n");
    exit_code = 1;
  }

  if (unshared_multiplicand[1] != multiplicand_y) {
    printf("Multiplicand Y changed unexpectedly.\n");
    exit_code = 1;
  }

  if (unshared_multiplicand[2] != multiplicand_z) {
    printf("Multiplicand Z changed unexpectedly.\n");
    exit_code = 1;
  }

  if (unshared[0] != expected_x) {
    printf("FAIL multiply_3_3([%f, x, x], [%f, x, x]) = [%f, x, "
           "x] (expected %f)\n",
           multiplier_x, multiplicand_x, unshared[0], expected_x);
    exit_code = 1;
  }

  if (unshared[1] != expected_y) {
    printf("FAIL multiply_3_3([x, %f, x], [x, %f, x]) = [x, %f, "
           "x] (expected %f)\n",
           multiplier_y, multiplicand_y, unshared[1], expected_y);
    exit_code = 1;
  }

  if (unshared[2] != expected_z) {
    printf("FAIL multiply_3_3([x, x, %f], [x, x, %f]) = [x, x, "
           "%f] (expected %f)\n",
           multiplier_z, multiplicand_z, unshared[2], expected_z);
    exit_code = 1;
  }

  float shared_multiplier_multiplier[] = {multiplier_x, multiplier_y,
                                          multiplier_z};
  const float shared_multiplier_multiplicand[] = {
      multiplicand_x, multiplicand_y, multiplicand_z};

  multiply_3_3(shared_multiplier_multiplier, shared_multiplier_multiplicand,
               shared_multiplier_multiplier);

  if (shared_multiplier_multiplicand[0] != multiplicand_x) {
    printf("Multiplicand X changed unexpectedly.\n");
    exit_code = 1;
  }

  if (shared_multiplier_multiplicand[1] != multiplicand_y) {
    printf("Multiplicand Y changed unexpectedly.\n");
    exit_code = 1;
  }

  if (shared_multiplier_multiplicand[2] != multiplicand_z) {
    printf("Multiplicand Z changed unexpectedly.\n");
    exit_code = 1;
  }

  if (shared_multiplier_multiplier[0] != expected_x) {
    printf("FAIL multiply_3_3([%f, x, x], [%f, x, x]) = [%f, x, "
           "x] (expected %f)\n",
           multiplier_x, multiplicand_x, shared_multiplier_multiplier[0],
           expected_x);
    exit_code = 1;
  }

  if (shared_multiplier_multiplier[1] != expected_y) {
    printf("FAIL multiply_3_3([x, %f, x], [x, %f, x]) = [x, %f, "
           "x] (expected %f)\n",
           multiplier_y, multiplicand_y, shared_multiplier_multiplier[1],
           expected_y);
    exit_code = 1;
  }

  if (shared_multiplier_multiplier[2] != expected_z) {
    printf("FAIL multiply_3_3([x, x, %f], [x, x, %f]) = [x, x, "
           "%f] (expected %f)\n",
           multiplier_z, multiplicand_z, shared_multiplier_multiplier[2],
           expected_z);
    exit_code = 1;
  }

  const float shared_multiplicand_multiplier[] = {multiplier_x, multiplier_y,
                                                  multiplier_z};
  float shared_multiplicand_multiplicand[] = {multiplicand_x, multiplicand_y,
                                              multiplicand_z};

  multiply_3_3(shared_multiplicand_multiplier, shared_multiplicand_multiplicand,
               shared_multiplicand_multiplicand);

  if (shared_multiplicand_multiplier[0] != multiplier_x) {
    printf("Multiplier X changed unexpectedly.\n");
    exit_code = 1;
  }

  if (shared_multiplicand_multiplier[1] != multiplier_y) {
    printf("Multiplier Y changed unexpectedly.\n");
    exit_code = 1;
  }

  if (shared_multiplicand_multiplier[2] != multiplier_z) {
    printf("Multiplier Z changed unexpectedly.\n");
    exit_code = 1;
  }

  if (shared_multiplicand_multiplicand[0] != expected_x) {
    printf("FAIL multiply_3_3([%f, x, x], [%f, x, x]) = [%f, x, "
           "x] (expected %f)\n",
           multiplier_x, multiplicand_x, shared_multiplicand_multiplicand[0],
           expected_x);
    exit_code = 1;
  }

  if (shared_multiplicand_multiplicand[1] != expected_y) {
    printf("FAIL multiply_3_3([x, %f, x], [x, %f, x]) = [x, %f, "
           "x] (expected %f)\n",
           multiplier_y, multiplicand_y, shared_multiplicand_multiplicand[1],
           expected_y);
    exit_code = 1;
  }

  if (shared_multiplicand_multiplicand[2] != expected_z) {
    printf("FAIL multiply_3_3([x, x, %f], [x, x, %f]) = [x, x, "
           "%f] (expected %f)\n",
           multiplier_z, multiplicand_z, shared_multiplicand_multiplicand[2],
           expected_z);
    exit_code = 1;
  }
}

static void given_shared(const float shared_x, const float shared_y,
                         const float shared_z, const float expected_x,
                         const float expected_y, const float expected_z) {
  float shared[] = {shared_x, shared_y, shared_z};

  multiply_3_3(shared, shared, shared);

  if (shared[0] != expected_x) {
    printf("FAIL multiply_3_3([%f, x, x], [%f, x, x]) = [%f, x, "
           "x] (expected %f)\n",
           shared_x, shared_x, shared[0], expected_x);
    exit_code = 1;
  }

  if (shared[1] != expected_y) {
    printf("FAIL multiply_3_3([x, %f, x], [x, %f, x]) = [x, %f, "
           "x] (expected %f)\n",
           shared_y, shared_y, shared[1], expected_y);
    exit_code = 1;
  }

  if (shared[2] != expected_z) {
    printf("FAIL multiply_3_3([x, x, %f], [x, x, %f]) = [x, x, "
           "%f] (expected %f)\n",
           shared_z, shared_z, shared[2], expected_z);
    exit_code = 1;
  }
}

int main(const int argc, const char *const *const argv) {
  (void)(argc);
  (void)(argv);

  given(2.0f, -8.0f, -3.0f, 0.9f, 0.4f, 0.1f, 1.8f, -3.2f, -0.3f);
  given_shared(2.2f, -4.7, 0.5f, 4.84f, 22.089998f, 0.25f);

  return exit_code;
}
