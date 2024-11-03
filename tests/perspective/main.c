#include "stdio.h"
#include "../../src/perspective.h"

static int exit_code = 0;

static void check(
    const char *const description_a,
    const char *const description_b,
    const int index,
    const float expected,
    const float actual[16])
{
  const float actual_value = actual[index];

  if (actual_value != actual_value || expected < actual_value - 0.005f || expected > actual_value + 0.005f)
  {
    printf("FAIL %s %s %d expected %f actual %f\n", description_a, description_b, index, expected, actual[index]);
  }
}

static void scenario(
    const char *const description,
    const float height,
    const float width,
    const float focal_length,
    const float shift_y,
    const float shift_x,
    const float clip_start,
    const float clip_end,
    const float sensor_size,
    const float forward_0,
    const float forward_1,
    const float forward_2,
    const float forward_3,
    const float forward_4,
    const float forward_5,
    const float forward_6,
    const float forward_7,
    const float forward_8,
    const float forward_9,
    const float forward_10,
    const float forward_11,
    const float forward_12,
    const float forward_13,
    const float forward_14,
    const float forward_15,
    const float inverse_0,
    const float inverse_1,
    const float inverse_2,
    const float inverse_3,
    const float inverse_4,
    const float inverse_5,
    const float inverse_6,
    const float inverse_7,
    const float inverse_8,
    const float inverse_9,
    const float inverse_10,
    const float inverse_11,
    const float inverse_12,
    const float inverse_13,
    const float inverse_14,
    const float inverse_15)
{
  float forward[16], inverse[16];

  perspective(
      height,
      width,
      focal_length,
      shift_y,
      shift_x,
      clip_start,
      clip_end,
      sensor_size,
      forward,
      inverse);

  check(description, "forward", 0, forward_0, forward);
  check(description, "forward", 1, forward_1, forward);
  check(description, "forward", 2, forward_2, forward);
  check(description, "forward", 3, forward_3, forward);
  check(description, "forward", 4, forward_4, forward);
  check(description, "forward", 5, forward_5, forward);
  check(description, "forward", 6, forward_6, forward);
  check(description, "forward", 7, forward_7, forward);
  check(description, "forward", 8, forward_8, forward);
  check(description, "forward", 9, forward_9, forward);
  check(description, "forward", 10, forward_10, forward);
  check(description, "forward", 11, forward_11, forward);
  check(description, "forward", 12, forward_12, forward);
  check(description, "forward", 13, forward_13, forward);
  check(description, "forward", 14, forward_14, forward);
  check(description, "forward", 15, forward_15, forward);

  check(description, "inverse", 0, inverse_0, inverse);
  check(description, "inverse", 1, inverse_1, inverse);
  check(description, "inverse", 2, inverse_2, inverse);
  check(description, "inverse", 3, inverse_3, inverse);
  check(description, "inverse", 4, inverse_4, inverse);
  check(description, "inverse", 5, inverse_5, inverse);
  check(description, "inverse", 6, inverse_6, inverse);
  check(description, "inverse", 7, inverse_7, inverse);
  check(description, "inverse", 8, inverse_8, inverse);
  check(description, "inverse", 9, inverse_9, inverse);
  check(description, "inverse", 10, inverse_10, inverse);
  check(description, "inverse", 11, inverse_11, inverse);
  check(description, "inverse", 12, inverse_12, inverse);
  check(description, "inverse", 13, inverse_13, inverse);
  check(description, "inverse", 14, inverse_14, inverse);
  check(description, "inverse", 15, inverse_15, inverse);
}

int main(const int argc, const char *const argv)
{
  scenario(
      "tall",
      1576.0f,
      1170.0f,
      24.87f,
      -1.09f,
      2.0f,
      2.8f,
      5.0f,
      36.0f,
      1.8589433431625366f,
      0.0f,
      5.388033866882324f,
      0.0f,
      0.0f,
      1.3800532817840576f,
      -2.179999828338623f,
      0.0f,
      0.0f,
      0.0f,
      -3.545455f,
      -12.727272f,
      0.0f,
      0.0f,
      -1.0f,
      0.0f,
      0.53794000967170146821f,
      0.0f,
      0.0f,
      2.8984389904621324336f,
      0.0f,
      0.72460970398712037448f,
      0.0f,
      -1.5796490303044228423f,
      0.0f,
      0.0f,
      0.0f, -1.0f,
      0.0f,
      0.0f,
      -0.078571f,
      0.278571f);

  scenario(
      "wide",
      1170.0f,
      1576.0f,
      24.87f,
      -1.09f,
      2.0f,
      2.8f,
      5.0f,
      36.0f,
      1.3800532817840576f,
      0.0f,
      4.0f,
      0.0f,
      0.0f,
      1.8589433431625366f,
      -2.93647837638855f,
      0.0f,
      0.0f,
      0.0f,
      -3.545455f,
      -12.727272f,
      0.0f,
      0.0f,
      -1.0f,
      0.0f,
      0.72460970398712037448f,
      0.0f,
      0.0f,
      2.8984388159484814979f,
      0.0f,
      0.53794000967170146821f,
      0.0f,
      -1.5796492061951988113f,
      0.0f,
      0.0f,
      0.0f,
      -1.0f,
      0.0f,
      0.0f,
      -0.078571f,
      0.278571f);

  return exit_code;
}
