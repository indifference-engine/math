#include "stdio.h"
#include "../../src/sine.h"

static int exit_code = 0;

static int given(const float radians, const float expected)
{
  const float actual = sine(radians);

  if (actual != actual || actual > expected + 0.0025f || actual < expected - 0.0025f)
  {
    printf("FAIL sine(%f) = %f (expected %f)\n", radians, actual, expected);
    exit_code = 1;
  }
}

int main(const int argc, const char *const argv)
{
  given(-14.137166941154069573081895224758f, -1.0f);
  given(-14.0f, -0.99060735569487030787535480401459f);
  given(-13.0f, -0.42016703682664092186895503547688f);
  given(-12.566370614359172953850573533118f, 0.0f);
  given(-12.0f, 0.5365729180004349716653742282424f);
  given(-11.5f, 0.87545217468842852695568552660633f);
  given(-10.995574287564276334619251841478f, 1.0f);
  given(-10.5f, 0.879695759971670098018508684826f);
  given(-10.0f, 0.54402111088936981340474766185138f);
  given(-9.4247779607693797153879301498385f, 0.0f);
  given(-9.0f, -0.41211848524175656975627256635244f);
  given(-8.2f, -0.94073055667977290115364874994565f);
  given(-7.8539816339744830961566084581988f, -1.0f);
  given(-7.3f, -0.85043662062856451751736622796691f);
  given(-6.8f, -0.49411335113860832222207937762034f);
  given(-6.283185307179586476925286766559f, -0.0f);
  given(-7.8f, -0.99854334537460496343877332059609f);
  given(-5.2f, 0.8834546557201532646730844404218f);
  given(-4.7123889803846898576939650749193f, 1.0f);
  given(-4.2f, 0.87157577241358806001857709790882f);
  given(-3.7f, 0.52983614090849321321077762570121f);
  given(-3.1415926535897932384626433832795f, -0.0f);
  given(-1.9, -0.94630008768741448848970961163496f);
  given(-1.5707963267948966192313216916398f, -1.0f);
  given(-1.25f, -0.94898461935558621434849084703605f);
  given(-0.25f, -0.24740395925452292959684870484939f);
  given(0.0f, 0.0f);
  given(0.25f, 0.24740395925452292959684870484939f);
  given(1.25f, 0.94898461935558621434849084703605f);
  given(1.5707963267948966192313216916398f, 1.0f);
  given(1.9, 0.94630008768741448848970961163496f);
  given(3.1415926535897932384626433832795f, 0.0f);
  given(3.7f, -0.52983614090849321321077762570121f);
  given(4.2f, -0.87157577241358806001857709790882f);
  given(4.7123889803846898576939650749193f, -1.0f);
  given(5.2f, -0.8834546557201532646730844404218f);
  given(7.8f, 0.99854334537460496343877332059609f);
  given(6.283185307179586476925286766559f, 0.0f);
  given(6.8f, 0.49411335113860832222207937762034f);
  given(7.3f, 0.85043662062856451751736622796691f);
  given(7.8539816339744830961566084581988f, 1.0f);
  given(8.2f, 0.94073055667977290115364874994565f);
  given(9.0f, 0.41211848524175656975627256635244f);
  given(9.4247779607693797153879301498385f, 0.0f);
  given(10.0f, -0.54402111088936981340474766185138f);
  given(10.5f, -0.879695759971670098018508684826f);
  given(10.995574287564276334619251841478f, -1.0f);
  given(11.5f, -0.87545217468842852695568552660633f);
  given(12.0f, -0.5365729180004349716653742282424f);
  given(12.566370614359172953850573533118f, 0.0f);
  given(13.0f, 0.42016703682664092186895503547688f);
  given(14.0f, 0.99060735569487030787535480401459f);
  given(14.137166941154069573081895224758f, 1.0f);

  printf("Verifying that values interpolate smoothly...\n");

  float previous_radians = -7.8539816339744830961566084581988f;
  float previous = sine(previous_radians);
  float next_radians, next;

  for (next_radians = previous_radians + 0.0001f; next_radians <= -6.283185307179586476925286766559f; next_radians += 0.0001f)
  {
    next = sine(next_radians);

    if (next != next || next <= previous)
    {
      printf("FAIL A %f -> %f = %f -> %f\n", previous_radians, next_radians, previous, next);
      exit_code = 1;
    }

    previous_radians = next_radians;
    previous = next;
  }

  next_radians = -6.283185307179586476925286766559f;
  next = sine(next_radians);

  if (next != next || next < previous)
  {
    printf("FAIL B %f -> %f = %f -> %f\n", previous_radians, next_radians, previous, next);
    exit_code = 1;
  }

  previous_radians = next_radians;
  previous = next;

  for (next_radians = previous_radians + 0.0001f; next_radians <= -4.7123889803846898576939650749193f; next_radians += 0.0001f)
  {
    next = sine(next_radians);

    if (next != next || next <= previous)
    {
      printf("FAIL C %f -> %f = %f -> %f\n", previous_radians, next_radians, previous, next);
      exit_code = 1;
    }

    previous_radians = next_radians;
    previous = next;
  }

  next_radians = -1.5707963267948966192313216916398f;
  next = sine(next_radians);

  if (next != next || next > previous)
  {
    printf("FAIL D %f -> %f = %f -> %f\n", previous_radians, next_radians, previous, next);
    exit_code = 1;
  }

  previous_radians = next_radians;
  previous = next;

  for (next_radians = previous_radians + 0.0001f; next_radians <= -1.5707963267948966192313216916398f; next_radians += 0.0001f)
  {
    next = sine(next_radians);

    if (next != next || next >= previous)
    {
      printf("FAIL E %f -> %f = %f -> %f\n", previous_radians, next_radians, previous, next);
      exit_code = 1;
    }

    previous_radians = next_radians;
    previous = next;
  }

  next_radians = -1.5707963267948966192313216916398f;
  next = sine(next_radians);

  if (next != next || next < previous)
  {
    printf("FAIL F %f -> %f = %f -> %f\n", previous_radians, next_radians, previous, next);
    exit_code = 1;
  }

  previous_radians = next_radians;
  previous = next;

  for (next_radians = previous_radians + 0.0001f; next_radians <= 1.5707963267948966192313216916398f; next_radians += 0.0001f)
  {
    next = sine(next_radians);

    if (next != next || next <= previous)
    {
      printf("FAIL G %f -> %f = %f -> %f\n", previous_radians, next_radians, previous, next);
      exit_code = 1;
    }

    previous_radians = next_radians;
    previous = next;
  }

  next_radians = 1.5707963267948966192313216916398f;
  next = sine(next_radians);

  if (next != next || next < previous)
  {
    printf("FAIL H %f -> %f = %f -> %f\n", previous_radians, next_radians, previous, next);
    exit_code = 1;
  }

  previous_radians = next_radians;
  previous = next;

  for (next_radians = previous_radians + 0.0001f; next_radians <= 4.7123889803846898576939650749193f; next_radians += 0.0001f)
  {
    next = sine(next_radians);

    if (next != next || next >= previous)
    {
      printf("FAIL I %f -> %f = %f -> %f\n", previous_radians, next_radians, previous, next);
      exit_code = 1;
    }

    previous_radians = next_radians;
    previous = next;
  }

  next_radians = 4.7123889803846898576939650749193f;
  next = sine(next_radians);

  if (next != next || next > previous)
  {
    printf("FAIL J %f -> %f = %f -> %f\n", previous_radians, next_radians, previous, next);
    exit_code = 1;
    return exit_code;
  }

  previous_radians = next_radians;
  previous = next;

  for (next_radians = previous_radians + 0.0001f; next_radians <= 6.283185307179586476925286766559f; next_radians += 0.0001f)
  {
    next = sine(next_radians);

    if (next != next || next <= previous)
    {
      printf("FAIL K %f -> %f = %f -> %f\n", previous_radians, next_radians, previous, next);
      exit_code = 1;
    }

    previous_radians = next_radians;
    previous = next;
  }

  next_radians = 6.283185307179586476925286766559f;
  next = sine(next_radians);

  if (next != next || next < previous)
  {
    printf("FAIL L %f -> %f = %f -> %f\n", previous_radians, next_radians, previous, next);
    exit_code = 1;
  }

  previous_radians = next_radians;
  previous = next;

  for (next_radians = previous_radians + 0.0001f; next_radians <= 7.8539816339744830961566084581988f; next_radians += 0.0001f)
  {
    next = sine(next_radians);

    if (next != next || next <= previous)
    {
      printf("FAIL M %f -> %f = %f -> %f\n", previous_radians, next_radians, previous, next);
      exit_code = 1;
    }

    previous_radians = next_radians;
    previous = next;
  }
}
