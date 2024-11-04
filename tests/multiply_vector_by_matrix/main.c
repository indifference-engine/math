#include <stdio.h>
#include "../../src/multiply_vector_by_matrix.h"

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

static void check_exact_matrix(
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
}

static void check_exact_vector(
    const char *const description,
    const float expected_0,
    const float expected_1,
    const float expected_2,
    const float *const actual)
{
  check_exact_item(description, 0, expected_0, actual);
  check_exact_item(description, 1, expected_1, actual);
  check_exact_item(description, 2, expected_2, actual);
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

static void check_loose_vector(
    const char *const description,
    const float expected_0,
    const float expected_1,
    const float expected_2,
    const float *const actual)
{
  check_loose_item(description, 0, expected_0, actual);
  check_loose_item(description, 1, expected_1, actual);
  check_loose_item(description, 2, expected_2, actual);
}

int main(const int argc, const char *const *const argv)
{
  (void)(argc);
  (void)(argv);

  const float different_multiplier[] = {
      0.8064f,
      0.3564f,
      0.1173f,
  };

  const float different_multiplicand[] = {
      0.2358f,
      0.3545f,
      0.1634f,
      0.3588f,
      0.3287f,
      0.0151f,
      0.9761f,
      0.9283f,
      0.9852f,
      0.2559f,
      0.1717f,
      0.7705f,
  };

  float different_product[3];

  multiply_vector_by_matrix(different_multiplier, different_multiplicand, different_product);

  check_exact_vector(
      "different multiplier",
      0.8064f,
      0.3564f,
      0.1173f,
      different_multiplier);

  check_exact_matrix(
      "different multiplicand",
      0.2358f,
      0.3545f,
      0.1634f,
      0.3588f,
      0.3287f,
      0.0151f,
      0.9761f,
      0.9283f,
      0.9852f,
      0.2559f,
      0.1717f,
      0.7705f,
      different_multiplicand);

  check_loose_vector(
      "different product",
      0.694460f,
      1.313242f,
      1.676308f,
      different_product);

  float same_multiplier[] = {
      0.8064f,
      0.3564f,
      0.1173f,
  };

  const float same_multiplicand[] = {
      0.2358f,
      0.3545f,
      0.1634f,
      0.3588f,
      0.3287f,
      0.0151f,
      0.9761f,
      0.9283f,
      0.9852f,
      0.2559f,
      0.1717f,
      0.7705f,
  };

  multiply_vector_by_matrix(same_multiplier, same_multiplicand, same_multiplier);

  check_exact_matrix(
      "different multiplicand",
      0.2358f,
      0.3545f,
      0.1634f,
      0.3588f,
      0.3287f,
      0.0151f,
      0.9761f,
      0.9283f,
      0.9852f,
      0.2559f,
      0.1717f,
      0.7705f,
      same_multiplicand);

  check_loose_vector(
      "same product",
      0.694460f,
      1.313242f,
      1.676308f,
      same_multiplier);

  return exit_code;
}
