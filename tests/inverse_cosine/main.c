#include "../../src/inverse_cosine.h"
#include <stdio.h>

static int exit_code = 0;

static void given(const float cosine, const float expected) {
  const float actual = inverse_cosine(cosine);

  if (actual != actual || actual > expected + 0.0025f ||
      actual < expected - 0.0025f) {
    printf("FAIL inverse_cosine(%f) = %f (expected %f)\n", cosine, actual,
           expected);
    exit_code = 1;
  }
}

int main(const int argc, const char *const *const argv) {
  (void)(argc);
  (void)(argv);

  given(-1.0f, 3.141592653589793f);
  given(-0.94898461935558621434849084703605f, 2.8207963267948966f);
  given(-0.24740395925452292959684870484939f, 1.8207963267948966f);
  given(0.0f, 1.5707963267948966f);
  given(0.24740395925452292959684870484939f, 1.3207963267948966f);
  given(0.94898461935558621434849084703605f, 0.32079632679489667f);
  given(1.0f, 0.0f);

  printf("Verifying that values interpolate smoothly...\n");

  float previous_cosine = -1.0f;
  float previous = inverse_cosine(previous_cosine);
  float cosine, next;

  for (cosine = previous_cosine + 0.0001f; cosine <= 1.0f; cosine += 0.0001f) {
    next = inverse_cosine(cosine);

    if (next != next || next >= previous) {
      printf("FAIL A %f -> %f = %f -> %f\n", previous_cosine, cosine, previous,
             next);
      exit_code = 1;
    }

    previous_cosine = cosine;
    previous = next;
  }

  return exit_code;
}
