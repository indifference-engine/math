#include <stdio.h>
#include "../../src/absolute.h"
#include "../../src/negative_infinity.h"
#include "../../src/positive_infinity.h"

static int exit_code = 0;

static void given(const float value, const float expected)
{
  const float actual = absolute(value);

  if (actual != expected)
  {
    printf("FAIL absolute(%f) = %f (expected %f)\n", value, actual, expected);
    exit_code = 1;
  }
}

int main(const int argc, const char *const *const argv)
{
  (void)(argc);
  (void)(argv);

  given(-0.1f, 0.1f);
  given(-0.0f, 0.0f);
  given(0.0f, 0.0f);
  given(0.1f, 0.1f);
  given(NEGATIVE_INFINITY, POSITIVE_INFINITY);
  given(POSITIVE_INFINITY, POSITIVE_INFINITY);

  return exit_code;
}
