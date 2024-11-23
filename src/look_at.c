#include "look_at.h"
#include "inverse_square_root.h"

void look_at(
    const float from_x,
    const float from_y,
    const float from_z,
    const float to_x,
    const float to_y,
    const float to_z,
    const float z_x,
    const float z_y,
    const float z_z,
    float *const forward,
    float *const inverse)
{
  float x_x = to_x - from_x;
  float x_y = to_y - from_y;
  float x_z = to_z - from_z;

  const float x_inverse_magnitude = inverse_square_root(x_x * x_x + x_y * x_y + x_z * x_z);

  x_x *= x_inverse_magnitude;
  x_y *= x_inverse_magnitude;
  x_z *= x_inverse_magnitude;

  float y_x = z_y * x_z - x_y * z_z;
  float y_y = z_z * x_x - x_z * z_x;
  float y_z = z_x * x_y - x_x * z_y;

  const float y_inverse_magnitude = inverse_square_root(y_x * y_x + y_y * y_y + y_z * y_z);

  y_x *= y_inverse_magnitude;
  y_y *= y_inverse_magnitude;
  y_z *= y_inverse_magnitude;

  float recalculated_z_x = x_y * y_z - y_y * x_z;
  float recalculated_z_y = x_z * y_x - y_z * x_x;
  float recalculated_z_z = x_x * y_y - y_x * x_y;

  const float recalculated_z_inverse_magnitude = inverse_square_root(recalculated_z_x * recalculated_z_x + recalculated_z_y * recalculated_z_y + recalculated_z_z * recalculated_z_z);

  recalculated_z_x *= recalculated_z_inverse_magnitude;
  recalculated_z_y *= recalculated_z_inverse_magnitude;
  recalculated_z_z *= recalculated_z_inverse_magnitude;

  forward[0] = x_x;
  forward[1] = y_x;
  forward[2] = recalculated_z_x;
  forward[3] = from_x;
  forward[4] = x_y;
  forward[5] = y_y;
  forward[6] = recalculated_z_y;
  forward[7] = from_y;
  forward[8] = x_z;
  forward[9] = y_z;
  forward[10] = recalculated_z_z;
  forward[11] = from_z;
  forward[12] = 0.0f;
  forward[13] = 0.0f;
  forward[14] = 0.0f;
  forward[15] = 1.0f;

  inverse[0] = x_x;
  inverse[1] = x_y;
  inverse[2] = x_z;
  inverse[3] = -(from_x * x_x + from_y * x_y + from_z * x_z);
  inverse[4] = y_x;
  inverse[5] = y_y;
  inverse[6] = y_z;
  inverse[7] = -(from_x * y_x + from_y * y_y + from_z * y_z);
  inverse[8] = recalculated_z_x;
  inverse[9] = recalculated_z_y;
  inverse[10] = recalculated_z_z;
  inverse[11] = -(from_x * recalculated_z_x + from_y * recalculated_z_y + from_z * recalculated_z_z);
  inverse[12] = 0.0f;
  inverse[13] = 0.0f;
  inverse[14] = 0.0f;
  inverse[15] = 1.0f;
}
