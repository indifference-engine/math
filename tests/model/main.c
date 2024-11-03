#include "stdio.h"
#include "../../src/model.h"

static int exit_code = 0;

static void check(
    const char *const description_a,
    const char *const description_b,
    const int index,
    const float expected,
    const float actual[16])
{
  const float actual_value = actual[index];

  if (actual_value != actual_value || expected < actual_value - 0.0001f || expected > actual_value + 0.0001f)
  {
    printf("FAIL %s %s %d expected %f actual %f\n", description_a, description_b, index, expected, actual[index]);
  }
}

static void scenario(
    const char *const description,
    const float location_x,
    const float location_y,
    const float location_z,
    const float rotation_x,
    const float rotation_y,
    const float rotation_z,
    const float scale_x,
    const float scale_y,
    const float scale_z,
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

  model(location_x, location_y, location_z, rotation_x, rotation_y, rotation_z, scale_x, scale_y, scale_z, forward, inverse);

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
      "A",
      -1.059999942779541f,
      1.3399999141693115f,
      -3.0899999141693115f,
      0.5218533873558044f,
      -11.999137878417969f,
      3.607595205307007f,
      -1.9700000286102295f,
      0.23000001907348633f,
      2.440000057220459f,
      1.4843193292617798f,
      0.03455393388867378f,
      -1.5618388652801514f,
      -1.059999942779541f,
      0.7465341687202454f,
      -0.205805242061615f,
      0.5759603977203369f,
      1.3399999141693115f,
      1.0584814548492432f,
      0.09669662266969681f,
      1.7839645147323608f,
      -3.0899999141693115f,
      0.0f,
      0.0f,
      0.0f,
      1.0f,
      0.3824677876772831981f,
      0.19236109963022724601f,
      0.27274123226388674651f,
      0.99042236034476123775f,
      0.6531932744549315428f,
      -3.8904576382115192825f,
      1.8279131363164850871f,
      11.553849169155882536f,
      -0.26233517542482372209f,
      0.096741530583341103176f,
      0.29964465797727217539f,
      0.51819305381340482488f,
      0.0f,
      0.0f,
      0.0f,
      1.0f);

  scenario(
      "B",
      -1.059999942779541f,
      1.3399999141693115f,
      -3.0899999141693115f,
      -0.5218533873558044f,
      11.999137878417969f,
      -3.607595205307007f,
      -1.9700000286102295f,
      0.23000001907348633f,
      2.440000057220459f,
      1.484320044517517f,
      -0.14462198317050934f,
      0.4688152074813843f,
      -1.059999942779541f,
      -0.7465350031852722f,
      -0.150446817278862f,
      -1.597272515296936f,
      1.3399999141693115f,
      -1.0584797859191895f,
      -0.09669668972492218f,
      1.7839655876159668f,
      -3.0899999141693115f,
      0.0f,
      0.0f,
      0.0f,
      1.0f,
      0.38246799526235942171f,
      -0.19236130237573116501f,
      -0.27274081810939744285f,
      -0.1795889227824224152f,
      -2.7338742724112944886f,
      -2.843984457883862945f,
      -1.8279143930230401724f,
      -4.7352229604092424596f,
      0.078744820222497525711f,
      -0.2682868078772203031f,
      0.29964484182939608778f,
      1.3688763399923772223f,
      0.0f,
      0.0f,
      0.0f,
      1.0f);

  scenario(
      "C",
      -1.059999942779541,
      1.3399999141693115,
      -3.0899999141693115,
      0.5218533873558044,
      11.999137878417969,
      3.607595205307007,
      -1.9700000286102295,
      0.23000001907348633,
      2.440000057220459,
      1.484320044517517f,
      0.14462198317050934f,
      0.4688152074813843f,
      -1.059999942779541f,
      0.7465350031852722f,
      -0.150446817278862f,
      1.597272515296936f,
      1.3399999141693115f,
      -1.0584797859191895f,
      0.09669668972492218f,
      1.7839655876159668f,
      -3.0899999141693115f,
      0.0f,
      0.0f,
      0.0f,
      1.0f,
      0.38246799526235942171f,
      0.19236130237573116501f,
      -0.27274081810939744285f,
      -0.69511718012837589021f,
      2.7338742724112944886f,
      -2.843984457883862945f,
      1.8279143930230401724f,
      12.357100819335706945f,
      0.078744820222497525711f,
      0.2682868078772203031f,
      0.29964484182939608778f,
      0.64986774093590968125f,
      0.0f,
      0.0f,
      0.0f,
      1.0f);
}
