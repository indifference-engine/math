#include "../../src/is_nan.h"
#include "../../src/nan.h"
#include "../../src/negative_infinity.h"
#include "../../src/positive_infinity.h"
#include <stdbool.h>
#include <stdio.h>

static int exit_code = 0;

static void given(const float value, const bool expected) {
  const float actual = is_nan(value);

  if (actual != expected) {
    printf("FAIL is_nan(%f) = %s (expected %s)\n", value,
           actual ? "true" : "false", expected ? "true" : "false");
    exit_code = 1;
  }
}

int main(const int argc, const char *const *const argv) {
  (void)(argc);
  (void)(argv);

  given(0.0f, false);
  given(1.0f, false);
  given(-1.0f, false);
  given(POSITIVE_INFINITY, false);
  given(NEGATIVE_INFINITY, false);
  given(NAN, true);

  return exit_code;
}
