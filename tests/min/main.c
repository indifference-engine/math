#include <stdio.h>
#include "../../src/lesser.h"

static int exit_code = 0;

static void given(const float a, const float b, const float expected)
{
  const float actual = lesser(a, b);

  if (actual != expected)
  {
    printf("FAIL lesser(%f, %f) = %f (expected %f)\n", a, b, actual, expected);
    exit_code = 1;
  }
}

int main(const int argc, const char *const *const argv)
{
  (void)(argc);
  (void)(argv);

  given(12.3f, 18.4f, 12.3f);
  given(18.4f, 18.4f, 18.4f);
  given(18.4f, 12.3f, 12.3f);

  return exit_code;
}
