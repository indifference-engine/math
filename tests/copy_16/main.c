#include "../../src/copy_16.h"
#include <stdio.h>

static int exit_code = 0;

static void given(const float xx, const float xy, const float xz,
                  const float xw, const float yx, const float yy,
                  const float yz, const float yw, const float zx,
                  const float zy, const float zz, const float zw,
                  const float wx, const float wy, const float wz,
                  const float ww) {
  const float input[16] = {xx, xy, xz, xw, yx, yy, yz, yw,
                           zx, zy, zz, zw, wx, wy, wz, ww};
  float output[16];
  copy_16(input, output);

  if (input[0] != xx) {
    printf("Input XX changed unexpectedly.\n");
    exit_code = 1;
  }

  if (input[1] != xy) {
    printf("Input XY changed unexpectedly.\n");
    exit_code = 1;
  }

  if (input[2] != xz) {
    printf("Input XZ changed unexpectedly.\n");
    exit_code = 1;
  }

  if (input[3] != xw) {
    printf("Input XZ changed unexpectedly.\n");
    exit_code = 1;
  }

  if (input[4] != yx) {
    printf("Input YX changed unexpectedly.\n");
    exit_code = 1;
  }

  if (input[5] != yy) {
    printf("Input YY changed unexpectedly.\n");
    exit_code = 1;
  }

  if (input[6] != yz) {
    printf("Input YZ changed unexpectedly.\n");
    exit_code = 1;
  }

  if (input[7] != yw) {
    printf("Input YZ changed unexpectedly.\n");
    exit_code = 1;
  }

  if (input[8] != zx) {
    printf("Input ZX changed unexpectedly.\n");
    exit_code = 1;
  }

  if (input[9] != zy) {
    printf("Input ZY changed unexpectedly.\n");
    exit_code = 1;
  }

  if (input[10] != zz) {
    printf("Input ZZ changed unexpectedly.\n");
    exit_code = 1;
  }

  if (input[11] != zw) {
    printf("Input ZZ changed unexpectedly.\n");
    exit_code = 1;
  }

  if (input[12] != wx) {
    printf("Input WX changed unexpectedly.\n");
    exit_code = 1;
  }

  if (input[13] != wy) {
    printf("Input WY changed unexpectedly.\n");
    exit_code = 1;
  }

  if (input[14] != wz) {
    printf("Input WZ changed unexpectedly.\n");
    exit_code = 1;
  }

  if (input[15] != ww) {
    printf("Input WZ changed unexpectedly.\n");
    exit_code = 1;
  }

  if (output[0] != xx) {
    printf("Expected output XX %f, actual %f.\n", xx, output[0]);
    exit_code = 1;
  }

  if (output[1] != xy) {
    printf("Expected output XY %f, actual %f.\n", xy, output[1]);
    exit_code = 1;
  }

  if (output[2] != xz) {
    printf("Expected output XZ %f, actual %f.\n", xz, output[2]);
    exit_code = 1;
  }

  if (output[3] != xw) {
    printf("Expected output XW %f, actual %f.\n", xw, output[3]);
    exit_code = 1;
  }

  if (output[4] != yx) {
    printf("Expected output YX %f, actual %f.\n", yx, output[4]);
    exit_code = 1;
  }

  if (output[5] != yy) {
    printf("Expected output YY %f, actual %f.\n", yy, output[5]);
    exit_code = 1;
  }

  if (output[6] != yz) {
    printf("Expected output YZ %f, actual %f.\n", yz, output[6]);
    exit_code = 1;
  }

  if (output[7] != yw) {
    printf("Expected output YW %f, actual %f.\n", yw, output[7]);
    exit_code = 1;
  }

  if (output[8] != zx) {
    printf("Expected output ZX %f, actual %f.\n", zx, output[8]);
    exit_code = 1;
  }

  if (output[9] != zy) {
    printf("Expected output ZY %f, actual %f.\n", zy, output[9]);
    exit_code = 1;
  }

  if (output[10] != zz) {
    printf("Expected output ZZ %f, actual %f.\n", zz, output[10]);
    exit_code = 1;
  }

  if (output[11] != zw) {
    printf("Expected output ZW %f, actual %f.\n", zw, output[11]);
    exit_code = 1;
  }

  if (output[12] != wx) {
    printf("Expected output WX %f, actual %f.\n", wx, output[12]);
    exit_code = 1;
  }

  if (output[13] != wy) {
    printf("Expected output WY %f, actual %f.\n", wy, output[13]);
    exit_code = 1;
  }

  if (output[14] != wz) {
    printf("Expected output WZ %f, actual %f.\n", wz, output[14]);
    exit_code = 1;
  }

  if (output[15] != ww) {
    printf("Expected output WW %f, actual %f.\n", ww, output[15]);
    exit_code = 1;
  }
}

int main(const int argc, const char *const *const argv) {
  (void)(argc);
  (void)(argv);

  given(-12.4f, 18.1f, -9.4f, 22.4f, 8.7f, -10.4f, -12.7f, 1.1f, -8.4f, 7.6f,
        4.3f, 9.8f, 5.2f, -2.4f, 0.4f, -77.2f);

  return exit_code;
}
