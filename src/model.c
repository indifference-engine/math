#include "model.h"
#include "cosine.h"
#include "sine.h"

void model(const float location_x, const float location_y,
           const float location_z, const float rotation_x,
           const float rotation_y, const float rotation_z, const float scale_x,
           const float scale_y, const float scale_z, float *const forward,
           float *const inverse) {
  const float scale_x_reciprocal = 1 / scale_x;
  const float scale_y_reciprocal = 1 / scale_y;
  const float scale_z_reciprocal = 1 / scale_z;
  const float sin_x = sine(rotation_x);
  const float cos_x = cosine(rotation_x);
  const float sin_y = sine(rotation_y);
  const float cos_y = cosine(rotation_y);
  const float sin_z = sine(rotation_z);
  const float cos_z = cosine(rotation_z);
  const float a = scale_y * cos_x;
  const float b = -scale_z * sin_x;
  const float c = scale_y * sin_x;
  const float d = scale_z * cos_x;
  const float e = scale_x * cos_y;
  const float f = c * sin_y;
  const float g = d * sin_y;
  const float h = sin_x * sin_y;
  const float i = cos_x * sin_y;
  const float xx = cos_y * cos_z * scale_x_reciprocal;
  const float xy = cos_y * sin_z * scale_x_reciprocal;
  const float xz = -sin_y * scale_x_reciprocal;
  const float yx = (h * cos_z - cos_x * sin_z) * scale_y_reciprocal;
  const float yy = (cos_x * cos_z + h * sin_z) * scale_y_reciprocal;
  const float yz = sin_x * cos_y * scale_y_reciprocal;
  const float zx = (i * cos_z + sin_x * sin_z) * scale_z_reciprocal;
  const float zy = (-sin_x * cos_z + i * sin_z) * scale_z_reciprocal;
  const float zz = cos_x * cos_y * scale_z_reciprocal;
  forward[0] = e * cos_z;
  forward[1] = f * cos_z - a * sin_z;
  forward[2] = g * cos_z - b * sin_z;
  forward[3] = location_x;
  forward[4] = e * sin_z;
  forward[5] = a * cos_z + f * sin_z;
  forward[6] = b * cos_z + g * sin_z;
  forward[7] = location_y;
  forward[8] = -scale_x * sin_y;
  forward[9] = c * cos_y;
  forward[10] = d * cos_y;
  forward[11] = location_z;
  forward[12] = 0;
  forward[13] = 0;
  forward[14] = 0;
  forward[15] = 1;
  inverse[0] = xx;
  inverse[1] = xy;
  inverse[2] = xz;
  inverse[3] = -(location_x * xx + location_y * xy + location_z * xz);
  inverse[4] = yx;
  inverse[5] = yy;
  inverse[6] = yz;
  inverse[7] = -(location_x * yx + location_y * yy + location_z * yz);
  inverse[8] = zx;
  inverse[9] = zy;
  inverse[10] = zz;
  inverse[11] = -(location_x * zx + location_y * zy + location_z * zz);
  inverse[12] = 0;
  inverse[13] = 0;
  inverse[14] = 0;
  inverse[15] = 1;
}
