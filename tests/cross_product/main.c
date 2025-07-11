#include "../../src/cross_product.h"
#include <stdio.h>

static int exit_code = 0;

static void given(const float multiplier_x, const float multiplier_y,
                  const float multiplier_z, const float multiplicand_x,
                  const float multiplicand_y, const float multiplicand_z,
                  const float product_x, const float product_y,
                  const float product_z) {
  const float unshared_multiplier[3] = {multiplier_x, multiplier_y,
                                        multiplier_z};
  const float unshared_multiplicand[3] = {multiplicand_x, multiplicand_y,
                                          multiplicand_z};
  float unshared_product[3] = {1.2f, -3.4f, -5.6f};
  cross_product(unshared_multiplier, unshared_multiplicand, unshared_product);

  if (unshared_multiplier[0] != multiplier_x) {
    printf("Multiplier X changed unexpectedly.\n");
    exit_code = 1;
  }

  if (unshared_multiplier[1] != multiplier_y) {
    printf("Multiplier Y changed unexpectedly.\n");
    exit_code = 1;
  }

  if (unshared_multiplier[2] != multiplier_z) {
    printf("Multiplier Z changed unexpectedly.\n");
    exit_code = 1;
  }

  if (unshared_multiplicand[0] != multiplicand_x) {
    printf("Multiplicand X changed unexpectedly.\n");
    exit_code = 1;
  }

  if (unshared_multiplicand[1] != multiplicand_y) {
    printf("Multiplicand Y changed unexpectedly.\n");
    exit_code = 1;
  }

  if (unshared_multiplicand[2] != multiplicand_z) {
    printf("Multiplicand Z changed unexpectedly.\n");
    exit_code = 1;
  }

  if (unshared_product[0] != unshared_product[0] ||
      product_x > unshared_product[0] + 0.001f ||
      product_x < unshared_product[0] - 0.001f) {
    printf("Expected product X %f, actual %f.\n", product_x,
           unshared_product[0]);
    exit_code = 1;
  }

  if (unshared_product[1] != unshared_product[1] ||
      product_y > unshared_product[1] + 0.001f ||
      product_y < unshared_product[1] - 0.001f) {
    printf("Expected product Y %f, actual %f.\n", product_y,
           unshared_product[1]);
    exit_code = 1;
  }

  if (unshared_product[2] != unshared_product[2] ||
      product_z > unshared_product[2] + 0.001f ||
      product_z < unshared_product[2] - 0.001f) {
    printf("Expected product Z %f, actual %f.\n", product_z,
           unshared_product[2]);
    exit_code = 1;
  }

  float shared_multiplier_product[3] = {multiplier_x, multiplier_y,
                                        multiplier_z};
  const float shared_multiplicand[3] = {multiplicand_x, multiplicand_y,
                                        multiplicand_z};
  cross_product(shared_multiplier_product, shared_multiplicand,
                shared_multiplier_product);

  if (shared_multiplicand[0] != multiplicand_x) {
    printf("Multiplicand X changed unexpectedly.\n");
    exit_code = 1;
  }

  if (shared_multiplicand[1] != multiplicand_y) {
    printf("Multiplicand Y changed unexpectedly.\n");
    exit_code = 1;
  }

  if (shared_multiplicand[2] != multiplicand_z) {
    printf("Multiplicand Z changed unexpectedly.\n");
    exit_code = 1;
  }

  if (shared_multiplier_product[0] != shared_multiplier_product[0] ||
      product_x > shared_multiplier_product[0] + 0.001f ||
      product_x < shared_multiplier_product[0] - 0.001f) {
    printf("Expected product X %f, actual %f.\n", product_x,
           shared_multiplier_product[0]);
    exit_code = 1;
  }

  if (shared_multiplier_product[1] != shared_multiplier_product[1] ||
      product_y > shared_multiplier_product[1] + 0.001f ||
      product_y < shared_multiplier_product[1] - 0.001f) {
    printf("Expected product Y %f, actual %f.\n", product_y,
           shared_multiplier_product[1]);
    exit_code = 1;
  }

  if (shared_multiplier_product[2] != shared_multiplier_product[2] ||
      product_z > shared_multiplier_product[2] + 0.001f ||
      product_z < shared_multiplier_product[2] - 0.001f) {
    printf("Expected product Z %f, actual %f.\n", product_z,
           shared_multiplier_product[2]);
    exit_code = 1;
  }

  const float shared_multiplier[3] = {multiplier_x, multiplier_y, multiplier_z};
  float shared_multiplicand_product[3] = {multiplicand_x, multiplicand_y,
                                          multiplicand_z};
  cross_product(shared_multiplier, shared_multiplicand_product,
                shared_multiplicand_product);

  if (shared_multiplier[0] != multiplier_x) {
    printf("Multiplier X changed unexpectedly.\n");
    exit_code = 1;
  }

  if (shared_multiplier[1] != multiplier_y) {
    printf("Multiplier Y changed unexpectedly.\n");
    exit_code = 1;
  }

  if (shared_multiplier[2] != multiplier_z) {
    printf("Multiplier Z changed unexpectedly.\n");
    exit_code = 1;
  }

  if (shared_multiplicand_product[0] != shared_multiplicand_product[0] ||
      product_x > shared_multiplicand_product[0] + 0.001f ||
      product_x < shared_multiplicand_product[0] - 0.001f) {
    printf("Expected product X %f, actual %f.\n", product_x,
           shared_multiplicand_product[0]);
    exit_code = 1;
  }

  if (shared_multiplicand_product[1] != shared_multiplicand_product[1] ||
      product_y > shared_multiplicand_product[1] + 0.001f ||
      product_y < shared_multiplicand_product[1] - 0.001f) {
    printf("Expected product Y %f, actual %f.\n", product_y,
           shared_multiplicand_product[1]);
    exit_code = 1;
  }

  if (shared_multiplicand_product[2] != shared_multiplicand_product[2] ||
      product_z > shared_multiplicand_product[2] + 0.001f ||
      product_z < shared_multiplicand_product[2] - 0.001f) {
    printf("Expected product Z %f, actual %f.\n", product_z,
           shared_multiplicand_product[2]);
    exit_code = 1;
  }
}

int main(const int argc, const char *const *const argv) {
  (void)(argc);
  (void)(argv);

  given(12.4f, -18.1f, 9.4f, 31.5f, 16.4f, 18.8f, -494.44f, 62.98f, 773.51f);

  return exit_code;
}
