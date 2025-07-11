#include "../../src/interpolate_linearly_3_3_1.h"
#include <stdio.h>

static int exit_code = 0;

static void given(const float from_x, const float from_y, const float from_z,
                  const float to_x, const float to_y, const float to_z,
                  const float unit_interval, const float expected_x,
                  const float expected_y, const float expected_z) {
  const float unshared_from[] = {from_x, from_y, from_z};
  const float unshared_to[] = {to_x, to_y, to_z};
  float unshared[3];

  interpolate_linearly_3_3_1(unshared_from, unshared_to, unit_interval,
                             unshared);

  if (unshared_from[0] != from_x) {
    printf("From X changed unexpectedly.\n");
    exit_code = 1;
  }

  if (unshared_from[1] != from_y) {
    printf("From Y changed unexpectedly.\n");
    exit_code = 1;
  }

  if (unshared_from[2] != from_z) {
    printf("From Z changed unexpectedly.\n");
    exit_code = 1;
  }

  if (unshared_to[0] != to_x) {
    printf("To X changed unexpectedly.\n");
    exit_code = 1;
  }

  if (unshared_to[1] != to_y) {
    printf("To Y changed unexpectedly.\n");
    exit_code = 1;
  }

  if (unshared_to[2] != to_z) {
    printf("To Z changed unexpectedly.\n");
    exit_code = 1;
  }

  if (unshared[0] != expected_x) {
    printf(
        "FAIL interpolate_linearly_3_3_1([%f, x, x], [%f, x, x], %f) = [%f, x, "
        "x] (expected %f)\n",
        from_x, to_x, unit_interval, unshared[0], expected_x);
    exit_code = 1;
  }

  if (unshared[1] != expected_y) {
    printf(
        "FAIL interpolate_linearly_3_3_1([x, %f, x], [x, %f, x], %f) = [x, %f, "
        "x] (expected %f)\n",
        from_y, to_y, unit_interval, unshared[1], expected_y);
    exit_code = 1;
  }

  if (unshared[2] != expected_z) {
    printf(
        "FAIL interpolate_linearly_3_3_1([x, x, %f], [x, x, %f], %f) = [x, x, "
        "%f] (expected %f)\n",
        from_z, to_z, unit_interval, unshared[2], expected_z);
    exit_code = 1;
  }

  float shared_from_from[] = {from_x, from_y, from_z};
  const float shared_from_to[] = {to_x, to_y, to_z};

  interpolate_linearly_3_3_1(shared_from_from, shared_from_to, unit_interval,
                             shared_from_from);

  if (shared_from_to[0] != to_x) {
    printf("To X changed unexpectedly.\n");
    exit_code = 1;
  }

  if (shared_from_to[1] != to_y) {
    printf("To Y changed unexpectedly.\n");
    exit_code = 1;
  }

  if (shared_from_to[2] != to_z) {
    printf("To Z changed unexpectedly.\n");
    exit_code = 1;
  }

  if (shared_from_from[0] != expected_x) {
    printf(
        "FAIL interpolate_linearly_3_3_1([%f, x, x], [%f, x, x], %f) = [%f, x, "
        "x] (expected %f)\n",
        from_x, to_x, unit_interval, shared_from_from[0], expected_x);
    exit_code = 1;
  }

  if (shared_from_from[1] != expected_y) {
    printf(
        "FAIL interpolate_linearly_3_3_1([x, %f, x], [x, %f, x], %f) = [x, %f, "
        "x] (expected %f)\n",
        from_y, to_y, unit_interval, shared_from_from[1], expected_y);
    exit_code = 1;
  }

  if (shared_from_from[2] != expected_z) {
    printf(
        "FAIL interpolate_linearly_3_3_1([x, x, %f], [x, x, %f], %f) = [x, x, "
        "%f] (expected %f)\n",
        from_z, to_z, unit_interval, shared_from_from[2], expected_z);
    exit_code = 1;
  }

  const float shared_to_from[] = {from_x, from_y, from_z};
  float shared_to_to[] = {to_x, to_y, to_z};

  interpolate_linearly_3_3_1(shared_to_from, shared_to_to, unit_interval,
                             shared_to_to);

  if (shared_to_from[0] != from_x) {
    printf("From X changed unexpectedly.\n");
    exit_code = 1;
  }

  if (shared_to_from[1] != from_y) {
    printf("From Y changed unexpectedly.\n");
    exit_code = 1;
  }

  if (shared_to_from[2] != from_z) {
    printf("From Z changed unexpectedly.\n");
    exit_code = 1;
  }

  if (shared_to_to[0] != expected_x) {
    printf(
        "FAIL interpolate_linearly_3_3_1([%f, x, x], [%f, x, x], %f) = [%f, x, "
        "x] (expected %f)\n",
        from_x, to_x, unit_interval, shared_to_to[0], expected_x);
    exit_code = 1;
  }

  if (shared_to_to[1] != expected_y) {
    printf(
        "FAIL interpolate_linearly_3_3_1([x, %f, x], [x, %f, x], %f) = [x, %f, "
        "x] (expected %f)\n",
        from_y, to_y, unit_interval, shared_to_to[1], expected_y);
    exit_code = 1;
  }

  if (shared_to_to[2] != expected_z) {
    printf(
        "FAIL interpolate_linearly_3_3_1([x, x, %f], [x, x, %f], %f) = [x, x, "
        "%f] (expected %f)\n",
        from_z, to_z, unit_interval, shared_to_to[2], expected_z);
    exit_code = 1;
  }
}

int main(const int argc, const char *const *const argv) {
  (void)(argc);
  (void)(argv);

  given(0.2f, 0.8f, 0.3f, 0.9f, 0.4f, 0.5f, 0.7f, 0.69f, 0.52f, 0.44f);

  return exit_code;
}
