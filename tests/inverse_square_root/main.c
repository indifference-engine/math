#include "../../src/inverse_square_root.h"
#include <stdio.h>

static int exit_code = 0;

static void given(const float value, const float expected) {
  const float actual = inverse_square_root(value);

  if (actual != actual || actual > expected + 0.0075f ||
      actual < expected - 0.0075f) {
    printf("FAIL inverse_square_root(%f) = %f (expected %f)\n", value, actual,
           expected);
    exit_code = 1;
  }
}

int main(const int argc, const char *const *const argv) {
  (void)(argc);
  (void)(argv);

  given(0.1f, 3.1622776601683796639977870888655f);
  given(1.0f, 1.0f);
  given(47.3f, 0.14540168172557630517934942722007f);

  return exit_code;
}
