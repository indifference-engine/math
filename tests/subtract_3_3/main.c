#include "../../src/subtract_3_3.h"
#include <stdio.h>

static int exit_code = 0;

static void given(const float minuend_x, const float minuend_y,
                  const float minuend_z, const float subtrahend_x,
                  const float subtrahend_y, const float subtrahend_z,
                  const float expected_x, const float expected_y,
                  const float expected_z) {
  const float unshared_minuend[] = {minuend_x, minuend_y, minuend_z};
  const float unshared_subtrahend[] = {subtrahend_x, subtrahend_y,
                                       subtrahend_z};
  float unshared[3];

  subtract_3_3(unshared_minuend, unshared_subtrahend, unshared);

  if (unshared_minuend[0] != minuend_x) {
    printf("Minuend X changed unexpectedly.\n");
    exit_code = 1;
  }

  if (unshared_minuend[1] != minuend_y) {
    printf("Minuend Y changed unexpectedly.\n");
    exit_code = 1;
  }

  if (unshared_minuend[2] != minuend_z) {
    printf("Minuend Z changed unexpectedly.\n");
    exit_code = 1;
  }

  if (unshared_subtrahend[0] != subtrahend_x) {
    printf("Subtrahend X changed unexpectedly.\n");
    exit_code = 1;
  }

  if (unshared_subtrahend[1] != subtrahend_y) {
    printf("Subtrahend Y changed unexpectedly.\n");
    exit_code = 1;
  }

  if (unshared_subtrahend[2] != subtrahend_z) {
    printf("Subtrahend Z changed unexpectedly.\n");
    exit_code = 1;
  }

  if (unshared[0] != expected_x) {
    printf("FAIL interpolate_linearly_3([%f, x, x], [%f, x, x]) = [%f, x, "
           "x] (expected %f)\n",
           minuend_x, subtrahend_x, unshared[0], expected_x);
    exit_code = 1;
  }

  if (unshared[1] != expected_y) {
    printf("FAIL interpolate_linearly_3([x, %f, x], [x, %f, x]) = [x, %f, "
           "x] (expected %f)\n",
           minuend_y, subtrahend_y, unshared[1], expected_y);
    exit_code = 1;
  }

  if (unshared[2] != expected_z) {
    printf("FAIL interpolate_linearly_3([x, x, %f], [x, x, %f]) = [x, x, "
           "%f] (expected %f)\n",
           minuend_z, subtrahend_z, unshared[2], expected_z);
    exit_code = 1;
  }

  float shared_minuend_minuend[] = {minuend_x, minuend_y, minuend_z};
  const float shared_minuend_subtrahend[] = {subtrahend_x, subtrahend_y,
                                             subtrahend_z};

  subtract_3_3(shared_minuend_minuend, shared_minuend_subtrahend,
               shared_minuend_minuend);

  if (shared_minuend_subtrahend[0] != subtrahend_x) {
    printf("Subtrahend X changed unexpectedly.\n");
    exit_code = 1;
  }

  if (shared_minuend_subtrahend[1] != subtrahend_y) {
    printf("Subtrahend Y changed unexpectedly.\n");
    exit_code = 1;
  }

  if (shared_minuend_subtrahend[2] != subtrahend_z) {
    printf("Subtrahend Z changed unexpectedly.\n");
    exit_code = 1;
  }

  if (shared_minuend_minuend[0] != expected_x) {
    printf("FAIL interpolate_linearly_3([%f, x, x], [%f, x, x]) = [%f, x, "
           "x] (expected %f)\n",
           minuend_x, subtrahend_x, shared_minuend_minuend[0], expected_x);
    exit_code = 1;
  }

  if (shared_minuend_minuend[1] != expected_y) {
    printf("FAIL interpolate_linearly_3([x, %f, x], [x, %f, x]) = [x, %f, "
           "x] (expected %f)\n",
           minuend_y, subtrahend_y, shared_minuend_minuend[1], expected_y);
    exit_code = 1;
  }

  if (shared_minuend_minuend[2] != expected_z) {
    printf("FAIL interpolate_linearly_3([x, x, %f], [x, x, %f]) = [x, x, "
           "%f] (expected %f)\n",
           minuend_z, subtrahend_z, shared_minuend_minuend[2], expected_z);
    exit_code = 1;
  }

  const float shared_subtrahend_minuend[] = {minuend_x, minuend_y, minuend_z};
  float shared_subtrahend_subtrahend[] = {subtrahend_x, subtrahend_y,
                                          subtrahend_z};

  subtract_3_3(shared_subtrahend_minuend, shared_subtrahend_subtrahend,
               shared_subtrahend_subtrahend);

  if (shared_subtrahend_minuend[0] != minuend_x) {
    printf("Minuend X changed unexpectedly.\n");
    exit_code = 1;
  }

  if (shared_subtrahend_minuend[1] != minuend_y) {
    printf("Minuend Y changed unexpectedly.\n");
    exit_code = 1;
  }

  if (shared_subtrahend_minuend[2] != minuend_z) {
    printf("Minuend Z changed unexpectedly.\n");
    exit_code = 1;
  }

  if (shared_subtrahend_subtrahend[0] != expected_x) {
    printf("FAIL interpolate_linearly_3([%f, x, x], [%f, x, x]) = [%f, x, "
           "x] (expected %f)\n",
           minuend_x, subtrahend_x, shared_subtrahend_subtrahend[0],
           expected_x);
    exit_code = 1;
  }

  if (shared_subtrahend_subtrahend[1] != expected_y) {
    printf("FAIL interpolate_linearly_3([x, %f, x], [x, %f, x]) = [x, %f, "
           "x] (expected %f)\n",
           minuend_y, subtrahend_y, shared_subtrahend_subtrahend[1],
           expected_y);
    exit_code = 1;
  }

  if (shared_subtrahend_subtrahend[2] != expected_z) {
    printf("FAIL interpolate_linearly_3([x, x, %f], [x, x, %f]) = [x, x, "
           "%f] (expected %f)\n",
           minuend_z, subtrahend_z, shared_subtrahend_subtrahend[2],
           expected_z);
    exit_code = 1;
  }
}

int main(const int argc, const char *const *const argv) {
  (void)(argc);
  (void)(argv);

  given(0.2f, -0.8f, -0.3f, 0.9f, 0.4f, 0.1f, -0.7f, -1.2f, -0.4f);

  return exit_code;
}
