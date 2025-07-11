#include "../../src/clip_to_model.h"
#include "../../src/culled_by.h"
#include <stdio.h>

static int exit_code = 0;

static void check_exact_item(const char *const description, const int index,
                             const float expected, const float *const actual) {
  const float actual_value = actual[index];

  if (expected != actual_value) {
    printf("FAIL %s %d expected %f actual %f\n", description, index, expected,
           actual_value);
    exit_code = 1;
  }
}

static void check_exact_matrix(const char *const description,
                               const float expected_0, const float expected_1,
                               const float expected_2, const float expected_3,
                               const float expected_4, const float expected_5,
                               const float expected_6, const float expected_7,
                               const float expected_8, const float expected_9,
                               const float expected_10, const float expected_11,
                               const float expected_12, const float expected_13,
                               const float expected_14, const float expected_15,
                               const float *const actual) {
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

static void check_exact_vector(const char *const description,
                               const float expected_0, const float expected_1,
                               const float expected_2,
                               const float *const actual) {
  check_exact_item(description, 0, expected_0, actual);
  check_exact_item(description, 1, expected_1, actual);
  check_exact_item(description, 2, expected_2, actual);
}

static void check_loose_item(const char *const description, const int index,
                             const float expected, const float *const actual) {
  const float actual_value = actual[index];

  if (actual_value != actual_value || expected < actual_value - 0.005f ||
      expected > actual_value + 0.005f) {
    printf("FAIL %s %d expected %f actual %f\n", description, index, expected,
           actual_value);
    exit_code = 1;
  }
}

static void check_loose_vector(const char *const description,
                               const float expected_0, const float expected_1,
                               const float expected_2,
                               const float *const actual) {
  check_loose_item(description, 0, expected_0, actual);
  check_loose_item(description, 1, expected_1, actual);
  check_loose_item(description, 2, expected_2, actual);
}

int main(const int argc, const char *const *const argv) {
  (void)(argc);
  (void)(argv);

  const float different_unculled_multiplier[] = {
      0.8064f,
      0.3564f,
      0.1173f,
  };

  const float different_unculled_multiplicand[] = {
      -0.701645f, 0.879247f,  2.122090f,  4.635321f,  1.474376f,  -5.586166f,
      1.872331f,  14.833803f, 0.930089f,  -0.342990f, -1.062371f, -0.423478f,
      0.262333f,  -0.096741f, -0.299643f, -0.518191f,
  };

  float different_unculled_product[3];

  const int different_unculled_result = clip_to_model(
      different_unculled_multiplier, different_unculled_multiplicand,
      different_unculled_product);

  if (different_unculled_result != CULLED_BY_NOTHING) {
    printf("FAIL different unculled result %d\n", different_unculled_result);
    exit_code = 1;
  }

  check_exact_vector("different unculled multiplier", 0.8064f, 0.3564f, 0.1173f,
                     different_unculled_multiplier);

  check_exact_matrix("different unculled multiplicand", -0.701645f, 0.879247f,
                     2.122090f, 4.635321f, 1.474376f, -5.586166f, 1.872331f,
                     14.833803f, 0.930089f, -0.342990f, -1.062371f, -0.423478f,
                     0.262333f, -0.096741f, -0.299643f, -0.518191f,
                     different_unculled_multiplicand);

  check_loose_vector("different unculled product", -12.309701f, -37.875381f,
                     -0.211783f, different_unculled_product);

  float same_unculled_multiplier[] = {
      0.8064f,
      0.3564f,
      0.1173f,
  };

  const float same_unculled_multiplicand[] = {
      -0.701645f, 0.879247f,  2.122090f,  4.635321f,  1.474376f,  -5.586166f,
      1.872331f,  14.833803f, 0.930089f,  -0.342990f, -1.062371f, -0.423478f,
      0.262333f,  -0.096741f, -0.299643f, -0.518191f,
  };

  const int same_unculled_result =
      clip_to_model(same_unculled_multiplier, same_unculled_multiplicand,
                    same_unculled_multiplier);

  if (same_unculled_result != CULLED_BY_NOTHING) {
    printf("FAIL same unculled result %d\n", same_unculled_result);
    exit_code = 1;
  }

  check_exact_matrix("same unculled multiplicand", -0.701645f, 0.879247f,
                     2.122090f, 4.635321f, 1.474376f, -5.586166f, 1.872331f,
                     14.833803f, 0.930089f, -0.342990f, -1.062371f, -0.423478f,
                     0.262333f, -0.096741f, -0.299643f, -0.518191f,
                     same_unculled_multiplicand);

  check_loose_vector("same unculled product", -12.309701f, -37.875381f,
                     -0.211783f, same_unculled_multiplier);

  const float different_w_multiplier[] = {
      0.0f,
      0.3564f,
      0.0f,
  };

  const float different_w_multiplicand[] = {
      -0.701645f, 0.879247f,  2.122090f,  4.635321f,  1.474376f,  -5.586166f,
      1.872331f,  14.833803f, 0.930089f,  -0.342990f, -1.062371f, -0.423478f,
      0.262333f,  0.0f,       -0.299643f, 0.0f,
  };

  float different_w_product[] = {
      35925.328792f,
      78794.8724f,
      -348290348.42f,
  };

  const int different_w_result = clip_to_model(
      different_w_multiplier, different_w_multiplicand, different_w_product);

  if (different_w_result != CULLED_BY_W_ZERO) {
    printf("FAIL different w zero result %d\n", different_w_result);
    exit_code = 1;
  }

  check_exact_vector("different w zero multiplier", 0.0f, 0.3564f, 0.0f,
                     different_w_multiplier);

  check_exact_matrix("different w zero multiplicand", -0.701645f, 0.879247f,
                     2.122090f, 4.635321f, 1.474376f, -5.586166f, 1.872331f,
                     14.833803f, 0.930089f, -0.342990f, -1.062371f, -0.423478f,
                     0.262333f, 0.0f, -0.299643f, 0.0f,
                     different_w_multiplicand);

  check_loose_vector("different w zero product", 35925.328792f, 78794.8724f,
                     -348290348.42f, different_w_product);

  float same_w_multiplier[] = {
      0.0f,
      0.3564f,
      0.0f,
  };

  const float same_w_multiplicand[] = {
      -0.701645f, 0.879247f,  2.122090f,  4.635321f,  1.474376f,  -5.586166f,
      1.872331f,  14.833803f, 0.930089f,  -0.342990f, -1.062371f, -0.423478f,
      0.262333f,  0.0f,       -0.299643f, 0.0f,
  };

  const int same_w_result =
      clip_to_model(same_w_multiplier, same_w_multiplicand, same_w_multiplier);

  if (same_w_result != CULLED_BY_W_ZERO) {
    printf("FAIL same w zero result %d\n", same_w_result);
    exit_code = 1;
  }

  check_exact_matrix("same w zero multiplicand", -0.701645f, 0.879247f,
                     2.122090f, 4.635321f, 1.474376f, -5.586166f, 1.872331f,
                     14.833803f, 0.930089f, -0.342990f, -1.062371f, -0.423478f,
                     0.262333f, 0.0f, -0.299643f, 0.0f, same_w_multiplicand);

  check_loose_vector("same w zero product", 0.0f, 0.3564f, 0.0f,
                     same_w_multiplier);

  return exit_code;
}
