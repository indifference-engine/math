#include "stdio.h"
#include "../../src/cosine.h"

static int exit_code = 0;

static int given(const float radians, const float expected)
{
  const float actual = cosine(radians);

  if (actual != actual || actual > expected + 0.0025f || actual < expected - 0.0025f)
  {
    printf("FAIL cosine(%f) = %f (expected %f)\n", radians, actual, expected);
    exit_code = 1;
  }
}

int main(const int argc, const char *const argv)
{
  given(-14.137166941154069573081895224758f, 0.0f);
  given(-14.0f, 0.13673721820783359424892887667174f);
  given(-13.0f, 0.90744678145019621385268615547448f);
  given(-12.566370614359172953850573533118f, 1.0f);
  given(-12.0f, 0.84385395873249210465395529317362f);
  given(-11.5f, 0.48330475875300588891068118005552f);
  given(-10.995574287564276334619251841478f, 0.0f);
  given(-10.5f, -0.47553692799599253552381149014886f);
  given(-10.0f, -0.83907152907645245225886394782406f);
  given(-9.4247779607693797153879301498385f, -1.0f);
  given(-9.0f, -0.91113026188467698836829471118117f);
  given(-8.2f, -0.33915486098383520740048812451964f);
  given(-7.8539816339744830961566084581988f, 0.0f);
  given(-7.3f, 0.52607751738110518891540657673769f);
  given(-6.8f, 0.86939749034982517244162463984627f);
  given(-6.283185307179586476925286766559f, 1.0f);
  given(-7.8f, 0.05395542056264957303256791295247f);
  given(-5.2f, 0.46851667130037695863909392660865f);
  given(-4.7123889803846898576939650749193f, 0.0f);
  given(-4.2f, -0.49026082134069957765554488137713f);
  given(-3.7f, -0.8481000317104081588356701063544f);
  given(-3.1415926535897932384626433832795f, -1.0f);
  given(-1.9, -0.32328956686350342227883369508031f);
  given(-1.5707963267948966192313216916398f, 0.0f);
  given(-1.25f, 0.31532236239526866544753855243804f);
  given(-0.25f, 0.96891242171064478414459544949419f);
  given(0.0f, 1.0f);
  given(0.25f, 0.96891242171064478414459544949419f);
  given(1.25f, 0.31532236239526866544753855243804f);
  given(1.5707963267948966192313216916398f, 0.0f);
  given(1.9, -0.32328956686350342227883369508031f);
  given(3.1415926535897932384626433832795f, -1.0f);
  given(3.7f, -0.8481000317104081588356701063544f);
  given(4.2f, -0.49026082134069957765554488137713f);
  given(4.7123889803846898576939650749193f, 0.0f);
  given(5.2f, 0.46851667130037695863909392660865f);
  given(7.8f, 0.05395542056264957303256791295247f);
  given(6.283185307179586476925286766559f, 1.0f);
  given(6.8f, 0.86939749034982517244162463984627f);
  given(7.3f, 0.52607751738110518891540657673769f);
  given(7.8539816339744830961566084581988f, 0.0f);
  given(8.2f, -0.33915486098383520740048812451964f);
  given(9.0f, -0.91113026188467698836829471118117f);
  given(9.4247779607693797153879301498385f, -1.0f);
  given(10.0f, -0.83907152907645245225886394782406f);
  given(10.5f, -0.47553692799599253552381149014886f);
  given(10.995574287564276334619251841478f, 0.0f);
  given(11.5f, 0.48330475875300588891068118005552f);
  given(12.0f, 0.84385395873249210465395529317362f);
  given(12.566370614359172953850573533118f, 1.0f);
  given(13.0f, 0.90744678145019621385268615547448f);
  given(14.0f, 0.13673721820783359424892887667174f);
  given(14.137166941154069573081895224758f, 0.0f);

  printf("Verifying that values interpolate smoothly...\n");

  float previous_radians = -7.8539816339744830961566084581988f;
  float previous = cosine(previous_radians);
  float next_radians, next;

  for (next_radians = previous_radians + 0.0001f; next_radians <= -6.283185307179586476925286766559f; next_radians += 0.0001f)
  {
    next = cosine(next_radians);

    if (next != next || next <= previous)
    {
      printf("FAIL A %f -> %f = %f -> %f\n", previous_radians, next_radians, previous, next);
      exit_code = 1;
    }

    previous_radians = next_radians;
    previous = next;
  }

  next_radians = -6.283185307179586476925286766559f;
  next = cosine(next_radians);

  if (next != next || next < previous)
  {
    printf("FAIL B %f -> %f = %f -> %f\n", previous_radians, next_radians, previous, next);
    exit_code = 1;
  }

  previous_radians = next_radians;
  previous = next;

  for (next_radians = previous_radians + 0.0001f; next_radians <= -3.1415926535897932384626433832795f; next_radians += 0.0001f)
  {
    next = cosine(next_radians);

    if (next != next || next >= previous)
    {
      printf("FAIL C %f -> %f = %f -> %f\n", previous_radians, next_radians, previous, next);
      exit_code = 1;
    }

    previous_radians = next_radians;
    previous = next;
  }

  next_radians = -3.1415926535897932384626433832795f;
  next = cosine(next_radians);

  if (next != next || next > previous)
  {
    printf("FAIL D %f -> %f = %f -> %f\n", previous_radians, next_radians, previous, next);
    exit_code = 1;
  }

  previous_radians = next_radians;
  previous = next;

  for (next_radians = previous_radians + 0.0001f; next_radians <= 0.0f; next_radians += 0.0001f)
  {
    next = cosine(next_radians);

    if (next != next || next <= previous)
    {
      printf("FAIL E %f -> %f = %f -> %f\n", previous_radians, next_radians, previous, next);
      exit_code = 1;
    }

    previous_radians = next_radians;
    previous = next;
  }

  next_radians = 0.0f;
  next = cosine(next_radians);

  if (next != next || next < previous)
  {
    printf("FAIL F %f -> %f = %f -> %f\n", previous_radians, next_radians, previous, next);
    exit_code = 1;
  }

  previous_radians = next_radians;
  previous = next;

  for (next_radians = previous_radians + 0.0001f; next_radians <= 3.1415926535897932384626433832795f; next_radians += 0.0001f)
  {
    next = cosine(next_radians);

    if (next != next || next >= previous)
    {
      printf("FAIL G %f -> %f = %f -> %f\n", previous_radians, next_radians, previous, next);
      exit_code = 1;
    }

    previous_radians = next_radians;
    previous = next;
  }

  next_radians = 3.1415926535897932384626433832795f;
  next = cosine(next_radians);

  if (next != next || next > previous)
  {
    printf("FAIL H %f -> %f = %f -> %f\n", previous_radians, next_radians, previous, next);
    exit_code = 1;
  }

  previous_radians = next_radians;
  previous = next;

  for (next_radians = previous_radians + 0.0001f; next_radians <= 6.283185307179586476925286766559f; next_radians += 0.0001f)
  {
    next = cosine(next_radians);

    if (next != next || next <= previous)
    {
      printf("FAIL I %f -> %f = %f -> %f\n", previous_radians, next_radians, previous, next);
      exit_code = 1;
    }

    previous_radians = next_radians;
    previous = next;
  }

  next_radians = 6.283185307179586476925286766559f;
  next = cosine(next_radians);

  if (next != next || next < previous)
  {
    printf("FAIL J %f -> %f = %f -> %f\n", previous_radians, next_radians, previous, next);
    exit_code = 1;
  }

  previous_radians = next_radians;
  previous = next;

  for (next_radians = previous_radians + 0.0001f; next_radians <= 7.8539816339744830961566084581988f; next_radians += 0.0001f)
  {
    next = cosine(next_radians);

    if (next != next || next >= previous)
    {
      printf("FAIL K %f -> %f = %f -> %f\n", previous_radians, next_radians, previous, next);
      exit_code = 1;
    }

    previous_radians = next_radians;
    previous = next;
  }
}
