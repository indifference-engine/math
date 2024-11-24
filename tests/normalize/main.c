#include <stdio.h>
#include "../../src/normalize.h"

static int exit_code = 0;

static void given(const float vector_x, const float vector_y, const float vector_z, const float normal_x, const float normal_y, const float normal_z)
{
  const float unshared_vector[3] = {vector_x, vector_y, vector_z};
  float unshared_normal[3] = {1.2f, -3.4f, -5.6f};
  normalize(unshared_vector, unshared_normal);

  if (unshared_vector[0] != vector_x)
  {
    printf("Vector X changed unexpectedly.\n");
    exit_code = 1;
  }

  if (unshared_vector[1] != vector_y)
  {
    printf("Vector Y changed unexpectedly.\n");
    exit_code = 1;
  }

  if (unshared_vector[2] != vector_z)
  {
    printf("Vector Z changed unexpectedly.\n");
    exit_code = 1;
  }

  const float tolerance = 0.001f;

  if (unshared_normal[0] != unshared_normal[0] || normal_x > unshared_normal[0] + tolerance || normal_x < unshared_normal[0] - tolerance)
  {
    printf("Expected normal X %f, actual %f.\n", normal_x, unshared_normal[0]);
    exit_code = 1;
  }

  if (unshared_normal[1] != unshared_normal[1] || normal_y > unshared_normal[1] + tolerance || normal_y < unshared_normal[1] - tolerance)
  {
    printf("Expected normal Y %f, actual %f.\n", normal_y, unshared_normal[1]);
    exit_code = 1;
  }

  if (unshared_normal[2] != unshared_normal[2] || normal_z > unshared_normal[2] + tolerance || normal_z < unshared_normal[2] - tolerance)
  {
    printf("Expected normal Z %f, actual %f.\n", normal_z, unshared_normal[2]);
    exit_code = 1;
  }

  float shared[3] = {vector_x, vector_y, vector_z};

  normalize(shared, shared);

  if (shared[0] != shared[0] || normal_x > shared[0] + tolerance || normal_x < shared[0] - tolerance)
  {
    printf("Expected normal X %f, actual %f.\n", normal_x, shared[0]);
    exit_code = 1;
  }

  if (shared[1] != shared[1] || normal_y > shared[1] + tolerance || normal_y < shared[1] - tolerance)
  {
    printf("Expected normal Y %f, actual %f.\n", normal_y, shared[1]);
    exit_code = 1;
  }

  if (shared[2] != shared[2] || normal_z > shared[2] + tolerance || normal_z < shared[2] - tolerance)
  {
    printf("Expected normal Z %f, actual %f.\n", normal_z, shared[2]);
    exit_code = 1;
  }
}

int main(const int argc, const char *const *const argv)
{
  (void)(argc);
  (void)(argv);

  given(-12.4f, 18.1f, -9.4f, -0.5195019007795404f, 0.758305193879813f, -0.3938159570425548f);

  return exit_code;
}
