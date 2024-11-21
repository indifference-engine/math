#include <stdio.h>
#include "../../src/inverse_sine.h"

static int exit_code = 0;

static void given(const float sine, const float expected)
{
  const float actual = inverse_sine(sine);

  if (actual != actual || actual > expected + 0.0025f || actual < expected - 0.0025f)
  {
    printf("FAIL inverse_sine(%f) = %f (expected %f)\n", sine, actual, expected);
    exit_code = 1;
  }
}

int main(const int argc, const char *const *const argv)
{
  (void)(argc);
  (void)(argv);

  given(-1.0f, -1.5707963267948966192313216916398f);
  given(-0.94898461935558621434849084703605f, -1.25f);
  given(-0.24740395925452292959684870484939f, -0.25f);
  given(0.0f, 0.0f);
  given(0.24740395925452292959684870484939f, 0.25f);
  given(0.94898461935558621434849084703605f, 1.25f);
  given(1.0f, 1.5707963267948966192313216916398f);

  printf("Verifying that values interpolate smoothly...\n");

  float previous_sine = -1.0f;
  float previous = inverse_sine(previous_sine);
  float sine, next;

  for (sine = previous_sine + 0.0001f; sine <= 1.0f; sine += 0.0001f)
  {
    next = inverse_sine(sine);

    if (next != next || next <= previous)
    {
      printf("FAIL A %f -> %f = %f -> %f\n", previous_sine, sine, previous, next);
      exit_code = 1;
    }

    previous_sine = sine;
    previous = next;
  }

  return exit_code;
}
