#include "../../src/add_3_3.h"
#include <stdio.h>

static int exit_code = 0;

static void given(const float augend_x, const float augend_y,
                  const float augend_z, const float addend_x,
                  const float addend_y, const float addend_z,
                  const float expected_x, const float expected_y,
                  const float expected_z) {
  const float unshared_augend[] = {augend_x, augend_y, augend_z};
  const float unshared_addend[] = {addend_x, addend_y, addend_z};
  float unshared[3];

  add_3_3(unshared_augend, unshared_addend, unshared);

  if (unshared_augend[0] != augend_x) {
    printf("Augend X changed unexpectedly.\n");
    exit_code = 1;
  }

  if (unshared_augend[1] != augend_y) {
    printf("Augend Y changed unexpectedly.\n");
    exit_code = 1;
  }

  if (unshared_augend[2] != augend_z) {
    printf("Augend Z changed unexpectedly.\n");
    exit_code = 1;
  }

  if (unshared_addend[0] != addend_x) {
    printf("Addend X changed unexpectedly.\n");
    exit_code = 1;
  }

  if (unshared_addend[1] != addend_y) {
    printf("Addend Y changed unexpectedly.\n");
    exit_code = 1;
  }

  if (unshared_addend[2] != addend_z) {
    printf("Addend Z changed unexpectedly.\n");
    exit_code = 1;
  }

  if (unshared[0] != expected_x) {
    printf("FAIL add_3_3([%f, x, x], [%f, x, x]) = [%f, x, "
           "x] (expected %f)\n",
           augend_x, addend_x, unshared[0], expected_x);
    exit_code = 1;
  }

  if (unshared[1] != expected_y) {
    printf("FAIL add_3_3([x, %f, x], [x, %f, x]) = [x, %f, "
           "x] (expected %f)\n",
           augend_y, addend_y, unshared[1], expected_y);
    exit_code = 1;
  }

  if (unshared[2] != expected_z) {
    printf("FAIL add_3_3([x, x, %f], [x, x, %f]) = [x, x, "
           "%f] (expected %f)\n",
           augend_z, addend_z, unshared[2], expected_z);
    exit_code = 1;
  }

  float shared_augend_augend[] = {augend_x, augend_y, augend_z};
  const float shared_augend_addend[] = {addend_x, addend_y, addend_z};

  add_3_3(shared_augend_augend, shared_augend_addend, shared_augend_augend);

  if (shared_augend_addend[0] != addend_x) {
    printf("Addend X changed unexpectedly.\n");
    exit_code = 1;
  }

  if (shared_augend_addend[1] != addend_y) {
    printf("Addend Y changed unexpectedly.\n");
    exit_code = 1;
  }

  if (shared_augend_addend[2] != addend_z) {
    printf("Addend Z changed unexpectedly.\n");
    exit_code = 1;
  }

  if (shared_augend_augend[0] != expected_x) {
    printf("FAIL add_3_3([%f, x, x], [%f, x, x]) = [%f, x, "
           "x] (expected %f)\n",
           augend_x, addend_x, shared_augend_augend[0], expected_x);
    exit_code = 1;
  }

  if (shared_augend_augend[1] != expected_y) {
    printf("FAIL add_3_3([x, %f, x], [x, %f, x]) = [x, %f, "
           "x] (expected %f)\n",
           augend_y, addend_y, shared_augend_augend[1], expected_y);
    exit_code = 1;
  }

  if (shared_augend_augend[2] != expected_z) {
    printf("FAIL add_3_3([x, x, %f], [x, x, %f]) = [x, x, "
           "%f] (expected %f)\n",
           augend_z, addend_z, shared_augend_augend[2], expected_z);
    exit_code = 1;
  }

  const float shared_addend_augend[] = {augend_x, augend_y, augend_z};
  float shared_addend_addend[] = {addend_x, addend_y, addend_z};

  add_3_3(shared_addend_augend, shared_addend_addend, shared_addend_addend);

  if (shared_addend_augend[0] != augend_x) {
    printf("Augend X changed unexpectedly.\n");
    exit_code = 1;
  }

  if (shared_addend_augend[1] != augend_y) {
    printf("Augend Y changed unexpectedly.\n");
    exit_code = 1;
  }

  if (shared_addend_augend[2] != augend_z) {
    printf("Augend Z changed unexpectedly.\n");
    exit_code = 1;
  }

  if (shared_addend_addend[0] != expected_x) {
    printf("FAIL add_3_3([%f, x, x], [%f, x, x]) = [%f, x, "
           "x] (expected %f)\n",
           augend_x, addend_x, shared_addend_addend[0], expected_x);
    exit_code = 1;
  }

  if (shared_addend_addend[1] != expected_y) {
    printf("FAIL add_3_3([x, %f, x], [x, %f, x]) = [x, %f, "
           "x] (expected %f)\n",
           augend_y, addend_y, shared_addend_addend[1], expected_y);
    exit_code = 1;
  }

  if (shared_addend_addend[2] != expected_z) {
    printf("FAIL add_3_3([x, x, %f], [x, x, %f]) = [x, x, "
           "%f] (expected %f)\n",
           augend_z, addend_z, shared_addend_addend[2], expected_z);
    exit_code = 1;
  }
}

int main(const int argc, const char *const *const argv) {
  (void)(argc);
  (void)(argv);

  given(2.0f, -8.0f, -3.0f, 0.9f, 0.4f, 0.1f, 2.9f, -7.6f, -2.9f);

  return exit_code;
}
