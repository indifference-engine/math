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
    const float y_x,
    const float y_y,
    const float y_z,
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

  jointed_look_at(from_x, from_y, from_z, length, to_x, to_y, to_z, y_x, y_y, y_z, proximal_forward, proximal_inverse, distal_forward, distal_inverse);

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
      -0.26188310980796814f,
      0.959513783454895f,
      0.10368593037128448f,
      0.8384767770767212,
      0.2127905637025833f,
      -0.5016739964485168f,
      -1.373020052909851f,
      -0.3650234043598175f,
      0.9028694033622742f,
      -0.22712282836437225f,
      0.8349949717521667f,
      0.40461647510528564f,
      0.37356001138687134f,
      0.834708571434021f,
      0.16666699945926666f,
      0.0f,
      0.0f,
      0.0f,
      1.0f,
      0.838476836681366f,
      -0.3650234341621399f,
      0.40461650490760803f,
      1.3886020183563232f,
      0.21279051899909973f,
      0.9028693437576294f,
      0.37355995178222656f,
      -0.5239858627319336f,
      -0.5016739368438721f,
      -0.22712282836437225f,
      0.834708571434021f,
      -0.6382803320884705f,
      -0.0f,
      0.0f,
      -0.0f,
      1.0f,
      0.838476836681366f,
      0.2127905637025833f,
      -0.5016739964485168f,
      -0.013770043849945068f,
      -0.3650234341621399f,
      0.9028694033622742f,
      -0.22712282836437225f,
      0.24325749278068542f,
      0.40461650490760803f,
      0.37356001138687134f,
      0.834708571434021f,
      0.8225885033607483f,
      0.0f,
      0.0f,
      0.0f,
      1.0f,
      0.838476836681366f,
      -0.3650234341621399f,
      0.40461650490760803f,
      -0.2324923276901245f,
      0.21279054880142212f,
      0.9028694033622742f,
      0.37356001138687134f,
      -0.523985743522644f,
      -0.5016739964485168f,
      -0.22712284326553345f,
      0.8347086310386658f,
      -0.63828045129776f,
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
      -0.26188310980796814f,
      0.959513783454895f,
      0.10368593037128448f,
      0.04706372693181038f,
      0.21279051899909973f,
      -0.9759636521339417f,
      -1.373020052909851f,
      -0.3913429081439972f,
      0.9028694033622742f,
      0.17798200249671936f,
      0.8349949717521667f,
      0.9190406203269958f,
      0.37355998158454895f,
      0.12576642632484436f,
      0.16666699945926666f,
      0.0f,
      0.0f,
      0.0f,
      1.0f,
      0.04706370830535889f,
      -0.3913429081439972f,
      0.9190407395362854f,
      0.23821502923965454f,
      0.21279051899909973f,
      0.9028694033622742f,
      0.37355998158454895f,
      -0.5239858627319336f,
      -0.975963830947876f,
      0.17798203229904175f,
      0.12576647102832794f,
      -1.5095932483673096f,
      -0.0f,
      0.0f,
      -0.0f,
      1.0f,
      0.8822539448738098f,
      0.2256011962890625f,
      0.4131973087787628f,
      -1.2353461980819702f,
      -0.013227325864136219f,
      0.8892309665679932f,
      -0.4572674334049225f,
      -0.3097865581512451f,
      -0.4705878496170044f,
      0.3979605436325073f,
      0.7875115275382996f,
      2.8551039695739746f,
      0.0f,
      0.0f,
      0.0f,
      1.0f,
      0.8822540640830994f,
      -0.013227328658103943f,
      -0.47058793902397156f,
      2.4293692111968994f,
      0.2256011664867401f,
      0.8892308473587036f,
      0.39796048402786255f,
      -0.5820512771606445f,
      0.4131973385810852f,
      -0.4572674334049225f,
      0.7875116467475891f,
      -1.8796412944793701f,
      -0.0f,
      0.0f,
      -0.0f,
      1.0f);

  return exit_code;
}
