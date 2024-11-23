#include <stdio.h>
#include "../../src/look_at.h"

static int exit_code = 0;

static void check(
    const char *const description_a,
    const char *const description_b,
    const int index,
    const float expected,
    const float actual[16])
{
  const float actual_value = actual[index];

  if (actual_value != actual_value || expected < actual_value - 0.05f || expected > actual_value + 0.05f)
  {
    printf("FAIL %s %s %d expected %f actual %f\n", description_a, description_b, index, expected, actual[index]);
    exit_code = 1;
  }
}

static void scenario(
    const char *const description,
    const float from_x,
    const float from_y,
    const float from_z,
    const float to_x,
    const float to_y,
    const float to_z,
    const float z_x,
    const float z_y,
    const float z_z,
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

  look_at(from_x, from_y, from_z, to_x, to_y, to_z, z_x, z_y, z_z, forward, inverse);

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

int main(const int argc, const char *const *const argv)
{
  (void)(argc);
  (void)(argv);

  scenario(
      "A",
      -1.37302f,
      0.834995f,
      0.166667f,
      1.34548f,
      -0.34848f,
      1.47851f,
      -0.28273314237594604f,
      0.5710055232048035f,
      0.7707234621047974f,
      0.8384768962860107f,
      0.5170085430145264f,
      -0.17221705615520477f,
      -1.373020052909851f,
      -0.36502352356910706f,
      0.7675178050994873f,
      0.526948094367981f,
      0.8349949717521667f,
      0.4046162962913513f,
      -0.37897050380706787f,
      0.8322662115097046f,
      0.16666699945926666f,
      0.0f,
      0.0f,
      0.0f,
      1.0f,
      0.8384769558906555f,
      -0.36502352356910706f,
      0.4046163260936737f,
      1.3886022567749023f,
      0.5170086026191711f,
      0.7675179243087769f,
      -0.37897059321403503f,
      0.1321515291929245f,
      -0.17221707105636597f,
      0.526948094367981f,
      0.8322662711143494f,
      -0.8151677846908569f,
      -0.0f,
      0.0f,
      -0.0f,
      1.0f);

  return exit_code;
}
