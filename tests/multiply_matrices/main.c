#include <stdio.h>
#include "../../src/multiply_matrices.h"

static int exit_code = 0;

static void check_exact_item(
    const char *const description,
    const int index,
    const float expected,
    const float *const actual)
{
  const float actual_value = actual[index];

  if (expected != actual_value)
  {
    printf("FAIL %s %d expected %f actual %f\n", description, index, expected, actual_value);
    exit_code = 1;
  }
}

static void check_exact(
    const char *const description,
    const float expected_0,
    const float expected_1,
    const float expected_2,
    const float expected_3,
    const float expected_4,
    const float expected_5,
    const float expected_6,
    const float expected_7,
    const float expected_8,
    const float expected_9,
    const float expected_10,
    const float expected_11,
    const float expected_12,
    const float expected_13,
    const float expected_14,
    const float expected_15,
    const float *const actual)
{
  check_exact_item(description, 0, expected_0, actual);
  check_exact_item(description, 1, expected_1, actual);
  check_exact_item(description, 2, expected_2, actual);
  check_exact_item(description, 3, expected_3, actual);
  check_exact_item(description, 4, expected_4, actual);
  check_exact_item(description, 5, expected_5, actual);
  check_exact_item(description, 6, expected_6, actual);
  check_exact_item(description, 7, expected_7, actual);
  check_exact_item(description, 8, expected_8, actual);
  check_exact_item(description, 9, expected_9, actual);
  check_exact_item(description, 10, expected_10, actual);
  check_exact_item(description, 11, expected_11, actual);
  check_exact_item(description, 12, expected_12, actual);
  check_exact_item(description, 13, expected_13, actual);
  check_exact_item(description, 14, expected_14, actual);
  check_exact_item(description, 15, expected_15, actual);
}

static void check_loose_item(
    const char *const description,
    const int index,
    const float expected,
    const float *const actual)
{
  const float actual_value = actual[index];

  if (actual_value != actual_value || expected < actual_value - 0.005f || expected > actual_value + 0.005f)
  {
    printf("FAIL %s %d expected %f actual %f\n", description, index, expected, actual_value);
    exit_code = 1;
  }
}

static void check_loose(
    const char *const description,
    const float expected_0,
    const float expected_1,
    const float expected_2,
    const float expected_3,
    const float expected_4,
    const float expected_5,
    const float expected_6,
    const float expected_7,
    const float expected_8,
    const float expected_9,
    const float expected_10,
    const float expected_11,
    const float expected_12,
    const float expected_13,
    const float expected_14,
    const float expected_15,
    const float *const actual)
{
  check_loose_item(description, 0, expected_0, actual);
  check_loose_item(description, 1, expected_1, actual);
  check_loose_item(description, 2, expected_2, actual);
  check_loose_item(description, 3, expected_3, actual);
  check_loose_item(description, 4, expected_4, actual);
  check_loose_item(description, 5, expected_5, actual);
  check_loose_item(description, 6, expected_6, actual);
  check_loose_item(description, 7, expected_7, actual);
  check_loose_item(description, 8, expected_8, actual);
  check_loose_item(description, 9, expected_9, actual);
  check_loose_item(description, 10, expected_10, actual);
  check_loose_item(description, 11, expected_11, actual);
  check_loose_item(description, 12, expected_12, actual);
  check_loose_item(description, 13, expected_13, actual);
  check_loose_item(description, 14, expected_14, actual);
  check_loose_item(description, 15, expected_15, actual);
}

int main(const int argc, const char *const *const argv)
{
  (void)(argc);
  (void)(argv);

  const float different_a[16] = {
      1.3735369443893433f,
      -2.974452495574951f,
      1.6522530317306519f,
      -0.0720856785774231f,
      1.322471261024475f,
      6.1243109703063965f,
      -0.5224795341491699f,
      -0.7749859094619751f,
      0.8836144804954529f,
      -4.5423712730407715f,
      -1.7863743305206299f,
      -0.9022345542907715f,
      0.0f,
      0.0f,
      0.0f,
      1.0f,
  };

  const float different_b[16] = {
      -0.01299344003200531f,
      0.12425273656845093f,
      0.8930259346961975f,
      2.3591322898864746f,
      -0.06693699955940247f,
      0.18830831348896027f,
      -0.023741465061903f,
      0.44092345237731934f,
      -0.19957560300827026f,
      -0.6888105869293213f,
      0.0446627140045166f,
      -1.4445509910583496f,
      0.0f,
      0.0f,
      0.0f,
      1.0f,
  };

  float different_output[16];

  multiply_matrices(different_a, different_b, different_output);

  check_exact(
      "different a",
      1.3735369443893433f,
      -2.974452495574951f,
      1.6522530317306519f,
      -0.0720856785774231f,
      1.322471261024475f,
      6.1243109703063965f,
      -0.5224795341491699f,
      -0.7749859094619751f,
      0.8836144804954529f,
      -4.5423712730407715f,
      -1.7863743305206299f,
      -0.9022345542907715f,
      0.0f,
      0.0f,
      0.0f,
      1.0f,
      different_a);

  check_exact(
      "different b",
      -0.01299344003200531f,
      0.12425273656845093f,
      0.8930259346961975f,
      2.3591322898864746f,
      -0.06693699955940247f,
      0.18830831348896027f,
      -0.023741465061903f,
      0.44092345237731934f,
      -0.19957560300827026f,
      -0.6888105869293213f,
      0.0446627140045166f,
      -1.4445509910583496f,
      0.0f,
      0.0f,
      0.0f,
      1.0f,
      different_b);

  check_loose(
      "different output",
      -0.14849545061588287,
      -1.5275377035140991,
      1.371016025543213,
      -0.5300000309944153,
      -0.3228522539138794,
      1.6774687767028809,
      1.012265682220459,
      5.799999713897705,
      0.6490882635116577,
      0.48489871621131897,
      0.8171489834785461,
      1.7599998712539673,
      0.0,
      0.0,
      0.0,
      1.0,
      different_output);

  float same_a_a[16] = {
      1.3735369443893433f,
      -2.974452495574951f,
      1.6522530317306519f,
      -0.0720856785774231f,
      1.322471261024475f,
      6.1243109703063965f,
      -0.5224795341491699f,
      -0.7749859094619751f,
      0.8836144804954529f,
      -4.5423712730407715f,
      -1.7863743305206299f,
      -0.9022345542907715f,
      0.0f,
      0.0f,
      0.0f,
      1.0f,
  };

  const float same_a_b[16] = {
      -0.01299344003200531f,
      0.12425273656845093f,
      0.8930259346961975f,
      2.3591322898864746f,
      -0.06693699955940247f,
      0.18830831348896027f,
      -0.023741465061903f,
      0.44092345237731934f,
      -0.19957560300827026f,
      -0.6888105869293213f,
      0.0446627140045166f,
      -1.4445509910583496f,
      0.0f,
      0.0f,
      0.0f,
      1.0f,
  };

  multiply_matrices(same_a_a, same_a_b, same_a_a);

  check_exact(
      "same a b",
      -0.01299344003200531f,
      0.12425273656845093f,
      0.8930259346961975f,
      2.3591322898864746f,
      -0.06693699955940247f,
      0.18830831348896027f,
      -0.023741465061903f,
      0.44092345237731934f,
      -0.19957560300827026f,
      -0.6888105869293213f,
      0.0446627140045166f,
      -1.4445509910583496f,
      0.0f,
      0.0f,
      0.0f,
      1.0f,
      same_a_b);

  check_loose(
      "same a a",
      -0.14849545061588287,
      -1.5275377035140991,
      1.371016025543213,
      -0.5300000309944153,
      -0.3228522539138794,
      1.6774687767028809,
      1.012265682220459,
      5.799999713897705,
      0.6490882635116577,
      0.48489871621131897,
      0.8171489834785461,
      1.7599998712539673,
      0.0,
      0.0,
      0.0,
      1.0,
      same_a_a);

  const float same_b_a[16] = {
      1.3735369443893433f,
      -2.974452495574951f,
      1.6522530317306519f,
      -0.0720856785774231f,
      1.322471261024475f,
      6.1243109703063965f,
      -0.5224795341491699f,
      -0.7749859094619751f,
      0.8836144804954529f,
      -4.5423712730407715f,
      -1.7863743305206299f,
      -0.9022345542907715f,
      0.0f,
      0.0f,
      0.0f,
      1.0f,
  };

  float same_b_b[16] = {
      -0.01299344003200531f,
      0.12425273656845093f,
      0.8930259346961975f,
      2.3591322898864746f,
      -0.06693699955940247f,
      0.18830831348896027f,
      -0.023741465061903f,
      0.44092345237731934f,
      -0.19957560300827026f,
      -0.6888105869293213f,
      0.0446627140045166f,
      -1.4445509910583496f,
      0.0f,
      0.0f,
      0.0f,
      1.0f,
  };

  multiply_matrices(same_b_a, same_b_b, same_b_b);

  check_exact(
      "same b a",
      1.3735369443893433f,
      -2.974452495574951f,
      1.6522530317306519f,
      -0.0720856785774231f,
      1.322471261024475f,
      6.1243109703063965f,
      -0.5224795341491699f,
      -0.7749859094619751f,
      0.8836144804954529f,
      -4.5423712730407715f,
      -1.7863743305206299f,
      -0.9022345542907715f,
      0.0f,
      0.0f,
      0.0f,
      1.0f,
      same_b_a);

  check_loose(
      "same b b",
      -0.14849545061588287,
      -1.5275377035140991,
      1.371016025543213,
      -0.5300000309944153,
      -0.3228522539138794,
      1.6774687767028809,
      1.012265682220459,
      5.799999713897705,
      0.6490882635116577,
      0.48489871621131897,
      0.8171489834785461,
      1.7599998712539673,
      0.0,
      0.0,
      0.0,
      1.0,
      same_b_b);

  return exit_code;
}
