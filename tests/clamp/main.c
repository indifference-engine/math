#include "../../src/clamp.h"
#include <stdio.h>

static int exit_code = 0;

static void given(const float value, const float lower, const float upper,
                  const float expected) {
  const float actual = clamp(value, lower, upper);

  if (actual != expected) {
    printf("FAIL clamp(%f, %f, %f) = %f (expected %f)\n", value, lower, upper,
           actual, expected);
    exit_code = 1;
  }
}

int main(const int argc, const char *const *const argv) {
  (void)(argc);
  (void)(argv);

  given(12.3f, 16.9f, 18.4f, 16.9f);
  given(16.9f, 16.9f, 18.4f, 16.9f);
  given(17.1f, 16.9f, 18.4f, 17.1f);
  given(18.4f, 16.9f, 18.4f, 18.4f);
  given(24.5f, 16.9f, 18.4f, 18.4f);

  given(12.3f, 16.9f, 16.9f, 16.9f);
  given(16.9f, 16.9f, 16.9f, 16.9f);
  given(18.4f, 16.9f, 16.9f, 16.9f);

  return exit_code;
}
