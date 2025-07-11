#include "../../src/square_root.h"
#include <stdio.h>

static int exit_code = 0;

static void given(const float value, const float expected) {
  const float actual = square_root(value);

  if (actual != actual || actual > expected + 0.1f ||
      actual < expected - 0.1f) {
    printf("FAIL square_root(%f) = %f (expected %f)\n", value, actual,
           expected);
    exit_code = 1;
  }
}

int main(const int argc, const char *const *const argv) {
  (void)(argc);
  (void)(argv);

  given(0.1f, 0.3162277660168379f);
  given(1.0f, 1.0f);
  given(0.0f, 0.0f);
  given(47.3f, 6.87749954561976f);

  return exit_code;
}
