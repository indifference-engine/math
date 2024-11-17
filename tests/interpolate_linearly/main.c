#include <stdio.h>
#include "../../src/interpolate_linearly.h"

static int exit_code = 0;

static void given(const float value, const float lower, const float upper, const float expected)
{
  const float actual = interpolate_linearly(value, lower, upper);

  if (actual != expected)
  {
    printf("FAIL interpolate_linearly(%f, %f, %f) = %f (expected %f)\n", value, lower, upper, actual, expected);
    exit_code = 1;
  }
}

int main(const int argc, const char *const *const argv)
{
  (void)(argc);
  (void)(argv);

  given(12.3f, 16.9f, -0.2f, 11.38f);
  given(12.3f, 16.9f, 0.0f, 12.3f);
  given(12.3f, 16.9f, 0.25f, 13.45f);
  given(12.3f, 16.9f, 1.0f, 16.9f);
  given(12.3f, 16.9f, 1.25f, 18.05f);

  given(16.9f, 12.3f, -0.25f, 18.05f);
  given(16.9f, 12.3f, 0.0f, 16.9f);
  given(16.9f, 12.3f, 0.25f, 15.75f);
  given(16.9f, 12.3f, 1.0f, 12.3f);
  given(16.9f, 12.3f, 1.2f, 11.38f);

  return exit_code;
}
