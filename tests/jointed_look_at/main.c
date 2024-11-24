#include <stdio.h>
#include "../../src/jointed_look_at.h"

static int exit_code = 0;

static void check(
    const char *const description_a,
    const char *const description_b,
    const int index,
    const float expected,
    const float actual[16])
{
  const float actual_value = actual[index];

  if (actual_value != actual_value || expected < actual_value - 0.07f || expected > actual_value + 0.07f)
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
    const float length,
    const float to_x,
    const float to_y,
    const float to_z,
    const float z_x,
    const float z_y,
    const float z_z,
    const float proximal_forward_0,
    const float proximal_forward_1,
    const float proximal_forward_2,
    const float proximal_forward_3,
    const float proximal_forward_4,
    const float proximal_forward_5,
    const float proximal_forward_6,
    const float proximal_forward_7,
    const float proximal_forward_8,
    const float proximal_forward_9,
    const float proximal_forward_10,
    const float proximal_forward_11,
    const float proximal_forward_12,
    const float proximal_forward_13,
    const float proximal_forward_14,
    const float proximal_forward_15,
    const float proximal_inverse_0,
    const float proximal_inverse_1,
    const float proximal_inverse_2,
    const float proximal_inverse_3,
    const float proximal_inverse_4,
    const float proximal_inverse_5,
    const float proximal_inverse_6,
    const float proximal_inverse_7,
    const float proximal_inverse_8,
    const float proximal_inverse_9,
    const float proximal_inverse_10,
    const float proximal_inverse_11,
    const float proximal_inverse_12,
    const float proximal_inverse_13,
    const float proximal_inverse_14,
    const float proximal_inverse_15,
    const float distal_forward_0,
    const float distal_forward_1,
    const float distal_forward_2,
    const float distal_forward_3,
    const float distal_forward_4,
    const float distal_forward_5,
    const float distal_forward_6,
    const float distal_forward_7,
    const float distal_forward_8,
    const float distal_forward_9,
    const float distal_forward_10,
    const float distal_forward_11,
    const float distal_forward_12,
    const float distal_forward_13,
    const float distal_forward_14,
    const float distal_forward_15,
    const float distal_inverse_0,
    const float distal_inverse_1,
    const float distal_inverse_2,
    const float distal_inverse_3,
    const float distal_inverse_4,
    const float distal_inverse_5,
    const float distal_inverse_6,
    const float distal_inverse_7,
    const float distal_inverse_8,
    const float distal_inverse_9,
    const float distal_inverse_10,
    const float distal_inverse_11,
    const float distal_inverse_12,
    const float distal_inverse_13,
    const float distal_inverse_14,
    const float distal_inverse_15)
{
  float proximal_forward[16], proximal_inverse[16], distal_forward[16], distal_inverse[16];

  jointed_look_at(from_x, from_y, from_z, length, to_x, to_y, to_z, z_x, z_y, z_z, proximal_forward, proximal_inverse, distal_forward, distal_inverse);

  check(description, "proximal forward", 0, proximal_forward_0, proximal_forward);
  check(description, "proximal forward", 1, proximal_forward_1, proximal_forward);
  check(description, "proximal forward", 2, proximal_forward_2, proximal_forward);
  check(description, "proximal forward", 3, proximal_forward_3, proximal_forward);
  check(description, "proximal forward", 4, proximal_forward_4, proximal_forward);
  check(description, "proximal forward", 5, proximal_forward_5, proximal_forward);
  check(description, "proximal forward", 6, proximal_forward_6, proximal_forward);
  check(description, "proximal forward", 7, proximal_forward_7, proximal_forward);
  check(description, "proximal forward", 8, proximal_forward_8, proximal_forward);
  check(description, "proximal forward", 9, proximal_forward_9, proximal_forward);
  check(description, "proximal forward", 10, proximal_forward_10, proximal_forward);
  check(description, "proximal forward", 11, proximal_forward_11, proximal_forward);
  check(description, "proximal forward", 12, proximal_forward_12, proximal_forward);
  check(description, "proximal forward", 13, proximal_forward_13, proximal_forward);
  check(description, "proximal forward", 14, proximal_forward_14, proximal_forward);
  check(description, "proximal forward", 15, proximal_forward_15, proximal_forward);

  check(description, "proximal inverse", 0, proximal_inverse_0, proximal_inverse);
  check(description, "proximal inverse", 1, proximal_inverse_1, proximal_inverse);
  check(description, "proximal inverse", 2, proximal_inverse_2, proximal_inverse);
  check(description, "proximal inverse", 3, proximal_inverse_3, proximal_inverse);
  check(description, "proximal inverse", 4, proximal_inverse_4, proximal_inverse);
  check(description, "proximal inverse", 5, proximal_inverse_5, proximal_inverse);
  check(description, "proximal inverse", 6, proximal_inverse_6, proximal_inverse);
  check(description, "proximal inverse", 7, proximal_inverse_7, proximal_inverse);
  check(description, "proximal inverse", 8, proximal_inverse_8, proximal_inverse);
  check(description, "proximal inverse", 9, proximal_inverse_9, proximal_inverse);
  check(description, "proximal inverse", 10, proximal_inverse_10, proximal_inverse);
  check(description, "proximal inverse", 11, proximal_inverse_11, proximal_inverse);
  check(description, "proximal inverse", 12, proximal_inverse_12, proximal_inverse);
  check(description, "proximal inverse", 13, proximal_inverse_13, proximal_inverse);
  check(description, "proximal inverse", 14, proximal_inverse_14, proximal_inverse);
  check(description, "proximal inverse", 15, proximal_inverse_15, proximal_inverse);

  check(description, "distal forward", 0, distal_forward_0, distal_forward);
  check(description, "distal forward", 1, distal_forward_1, distal_forward);
  check(description, "distal forward", 2, distal_forward_2, distal_forward);
  check(description, "distal forward", 3, distal_forward_3, distal_forward);
  check(description, "distal forward", 4, distal_forward_4, distal_forward);
  check(description, "distal forward", 5, distal_forward_5, distal_forward);
  check(description, "distal forward", 6, distal_forward_6, distal_forward);
  check(description, "distal forward", 7, distal_forward_7, distal_forward);
  check(description, "distal forward", 8, distal_forward_8, distal_forward);
  check(description, "distal forward", 9, distal_forward_9, distal_forward);
  check(description, "distal forward", 10, distal_forward_10, distal_forward);
  check(description, "distal forward", 11, distal_forward_11, distal_forward);
  check(description, "distal forward", 12, distal_forward_12, distal_forward);
  check(description, "distal forward", 13, distal_forward_13, distal_forward);
  check(description, "distal forward", 14, distal_forward_14, distal_forward);
  check(description, "distal forward", 15, distal_forward_15, distal_forward);

  check(description, "distal inverse", 0, distal_inverse_0, distal_inverse);
  check(description, "distal inverse", 1, distal_inverse_1, distal_inverse);
  check(description, "distal inverse", 2, distal_inverse_2, distal_inverse);
  check(description, "distal inverse", 3, distal_inverse_3, distal_inverse);
  check(description, "distal inverse", 4, distal_inverse_4, distal_inverse);
  check(description, "distal inverse", 5, distal_inverse_5, distal_inverse);
  check(description, "distal inverse", 6, distal_inverse_6, distal_inverse);
  check(description, "distal inverse", 7, distal_inverse_7, distal_inverse);
  check(description, "distal inverse", 8, distal_inverse_8, distal_inverse);
  check(description, "distal inverse", 9, distal_inverse_9, distal_inverse);
  check(description, "distal inverse", 10, distal_inverse_10, distal_inverse);
  check(description, "distal inverse", 11, distal_inverse_11, distal_inverse);
  check(description, "distal inverse", 12, distal_inverse_12, distal_inverse);
  check(description, "distal inverse", 13, distal_inverse_13, distal_inverse);
  check(description, "distal inverse", 14, distal_inverse_14, distal_inverse);
  check(description, "distal inverse", 15, distal_inverse_15, distal_inverse);
}

int main(const int argc, const char *const *const argv)
{
  (void)(argc);
  (void)(argv);

  scenario(
      "overextended",
      -1.37302f,
      0.834995f,
      0.166667f,
      2.7f,
      1.34548f,
      -0.34848f,
      1.47851f,
      -0.28273314237594604f,
      0.5710055232048035f,
      0.7707234621047974f,
      0.8384767770767212f,
      0.5170084238052368f,
      -0.17221704125404358f,
      -1.373020052909851f,
      -0.36502349376678467f,
      0.7675176858901978f,
      0.5269480347633362f,
      0.8349949717521667f,
      0.40461623668670654f,
      -0.3789704442024231f,
      0.832266092300415f,
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
      1.0f,
      0.8384767770767212f,
      0.5170084238052368f,
      -0.17221704125404358f,
      -0.013770103454589844f,
      -0.36502349376678467f,
      0.7675176858901978f,
      0.5269480347633362f,
      0.2432575225830078f,
      0.40461623668670654f,
      -0.3789704442024231f,
      0.832266092300415f,
      0.8225880861282349f,
      0.0f,
      0.0f,
      0.0f,
      1.0f,
      0.8384769558906555f,
      -0.36502352356910706f,
      0.4046163260936737f,
      -0.23249195516109467f,
      0.5170086026191711f,
      0.7675179243087769f,
      -0.37897059321403503f,
      0.13215145468711853f,
      -0.17221707105636597f,
      0.526948094367981f,
      0.8322662711143494f,
      -0.8151677846908569f,
      -0.0f,
      0.0f,
      -0.0f,
      1.0f);

  scenario(
      "partially extended",
      -1.37302f,
      0.834995f,
      0.166667f,
      5.85f,
      1.34548f,
      -0.34848f,
      1.47851f,
      -0.28273314237594604f,
      0.5710055232048035f,
      0.7707234621047974f,
      0.32135260105133057f,
      0.5170082449913025f,
      -0.7933691143989563f,
      -1.373020052909851f,
      0.23631244897842407f,
      0.7675178050994873f,
      0.5958796739578247f,
      0.8349949717521667f,
      0.916999876499176f,
      -0.37897056341171265f,
      0.12446830421686172f,
      0.16666699945926666f,
      0.0f,
      0.0f,
      0.0f,
      1.0f,
      0.32135260105133057f,
      0.23631249368190765f,
      0.9169999957084656f,
      0.09107024222612381f,
      0.5170084238052368f,
      0.7675179243087769f,
      -0.3789706230163574f,
      0.13215123116970062f,
      -0.7933695316314697f,
      0.5958799123764038f,
      0.12446840852499008f,
      -1.6076139211654663f,
      -0.0f,
      -0.0f,
      -0.0f,
      1.0f,
      0.6080491542816162f,
      0.5170085430145264f,
      0.6024764776229858f,
      -0.4330637753009796f,
      -0.6409192681312561f,
      0.7675176858901978f,
      -0.011789243668317795f,
      1.5262088775634766f,
      -0.4685068428516388f,
      -0.37897035479545593f,
      0.7980493903160095f,
      2.8488917350769043f,
      0.0f,
      0.0f,
      0.0f,
      1.0f,
      0.6080493927001953f,
      -0.6409192681312561f,
      -0.4685066342353821f,
      2.5762252807617188f,
      0.5170087218284607f,
      0.7675178050994873f,
      -0.3789704740047455f,
      0.1321510225534439f,
      0.6024768948554993f,
      -0.011789444833993912f,
      0.7980494499206543f,
      -1.9946523904800415f,
      -0.0f,
      0.0f,
      -0.0f,
      1.0f);

  return exit_code;
}
