#include <stdio.h>
#include "../../src/dot_product.h"

static int exit_code = 0;

static void given_heterogenous(const float multiplier_x, const float multiplier_y, const float multiplier_z, const float multiplicand_x, const float multiplicand_y, const float multiplicand_z, const float product)
{
  const float unshared_multiplier[3] = {multiplier_x, multiplier_y, multiplier_z};
  const float unshared_multiplicand[3] = {multiplicand_x, multiplicand_y, multiplicand_z};
  const float unshared_product = dot_product(unshared_multiplier, unshared_multiplicand);

  if (unshared_multiplier[0] != multiplier_x)
  {
    printf("Multiplier X changed unexpectedly.\n");
    exit_code = 1;
  }

  if (unshared_multiplier[1] != multiplier_y)
  {
    printf("Multiplier Y changed unexpectedly.\n");
    exit_code = 1;
  }

  if (unshared_multiplier[2] != multiplier_z)
  {
    printf("Multiplier Z changed unexpectedly.\n");
    exit_code = 1;
  }

  if (unshared_multiplicand[0] != multiplicand_x)
  {
    printf("Multiplicand X changed unexpectedly.\n");
    exit_code = 1;
  }

  if (unshared_multiplicand[1] != multiplicand_y)
  {
    printf("Multiplicand Y changed unexpectedly.\n");
    exit_code = 1;
  }

  if (unshared_multiplicand[2] != multiplicand_z)
  {
    printf("Multiplicand Z changed unexpectedly.\n");
    exit_code = 1;
  }

  if (unshared_product != unshared_product || product > unshared_product + 0.001f || product < unshared_product - 0.001f)
  {
    printf("Expected product %f, actual %f.\n", product, unshared_product);
    exit_code = 1;
  }
}

static void given_homogenous(const float multiplier_multiplicand_x, const float multiplier_multiplicand_y, const float multiplier_multiplicand_z, const float product)
{
  const float unshared_multiplier[3] = {multiplier_multiplicand_x, multiplier_multiplicand_y, multiplier_multiplicand_z};
  const float unshared_multiplicand[3] = {multiplier_multiplicand_x, multiplier_multiplicand_y, multiplier_multiplicand_z};
  const float unshared_product = dot_product(unshared_multiplier, unshared_multiplicand);

  if (unshared_multiplier[0] != multiplier_multiplicand_x)
  {
    printf("Multiplier X changed unexpectedly.\n");
    exit_code = 1;
  }

  if (unshared_multiplier[1] != multiplier_multiplicand_y)
  {
    printf("Multiplier Y changed unexpectedly.\n");
    exit_code = 1;
  }

  if (unshared_multiplier[2] != multiplier_multiplicand_z)
  {
    printf("Multiplier Z changed unexpectedly.\n");
    exit_code = 1;
  }

  if (unshared_multiplicand[0] != multiplier_multiplicand_x)
  {
    printf("Multiplicand X changed unexpectedly.\n");
    exit_code = 1;
  }

  if (unshared_multiplicand[1] != multiplier_multiplicand_y)
  {
    printf("Multiplicand Y changed unexpectedly.\n");
    exit_code = 1;
  }

  if (unshared_multiplicand[2] != multiplier_multiplicand_z)
  {
    printf("Multiplicand Z changed unexpectedly.\n");
    exit_code = 1;
  }

  if (unshared_product != unshared_product || product > unshared_product + 0.001f || product < unshared_product - 0.001f)
  {
    printf("Expected product %f, actual %f.\n", product, unshared_product);
    exit_code = 1;
  }

  const float shared_multiplier_multiplicand[3] = {multiplier_multiplicand_x, multiplier_multiplicand_y, multiplier_multiplicand_z};
  const float shared_product = dot_product(shared_multiplier_multiplicand, shared_multiplier_multiplicand);

  if (shared_multiplier_multiplicand[0] != multiplier_multiplicand_x)
  {
    printf("Multiplier/multiplicand X changed unexpectedly.\n");
    exit_code = 1;
  }

  if (shared_multiplier_multiplicand[1] != multiplier_multiplicand_y)
  {
    printf("Multiplier/multiplicand Y changed unexpectedly.\n");
    exit_code = 1;
  }

  if (shared_multiplier_multiplicand[2] != multiplier_multiplicand_z)
  {
    printf("Multiplier/multiplicand Z changed unexpectedly.\n");
    exit_code = 1;
  }

  if (shared_product != shared_product || product > shared_product + 0.001f || product < shared_product - 0.001f)
  {
    printf("Expected product %f, actual %f.\n", product, shared_product);
    exit_code = 1;
  }
}

int main(const int argc, const char *const *const argv)
{
  (void)(argc);
  (void)(argv);

  given_heterogenous(12.4f, -18.1f, 9.4f, 31.5f, 16.4f, 18.8f, 270.48f);
  given_homogenous(12.4f, -18.1f, 9.4f, 569.73f);

  return exit_code;
}
