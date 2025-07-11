#include "../../src/copy_3.h"
#include <stdio.h>

static int exit_code = 0;

static void given(const float x, const float y, const float z) {
  const float input[3] = {x, y, z};
  float output[3] = {1.2f, -3.4f, -5.6f};
  copy_3(input, output);

  if (input[0] != x) {
    printf("Input X changed unexpectedly.\n");
    exit_code = 1;
  }

  if (input[1] != y) {
    printf("Input Y changed unexpectedly.\n");
    exit_code = 1;
  }

  if (input[2] != z) {
    printf("Input Z changed unexpectedly.\n");
    exit_code = 1;
  }

  if (output[0] != x) {
    printf("Expected output X %f, actual %f.\n", x, output[0]);
    exit_code = 1;
  }

  if (output[1] != y) {
    printf("Expected output Y %f, actual %f.\n", y, output[1]);
    exit_code = 1;
  }

  if (output[2] != z) {
    printf("Expected output Z %f, actual %f.\n", z, output[2]);
    exit_code = 1;
  }
}

int main(const int argc, const char *const *const argv) {
  (void)(argc);
  (void)(argv);

  given(-12.4f, 18.1f, -9.4f);

  return exit_code;
}
