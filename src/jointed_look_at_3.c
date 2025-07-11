#include "jointed_look_at_3.h"
#include "inverse_square_root.h"
#include "lesser.h"
#include "square_root.h"

void jointed_look_at_3(const float from_x, const float from_y,
                       const float from_z, const float length, const float to_x,
                       const float to_y, const float to_z, const float y_x,
                       const float y_y, const float y_z,
                       float *const proximal_forward,
                       float *const proximal_inverse,
                       float *const distal_forward,
                       float *const distal_inverse) {
  float half_delta_x = (to_x - from_x) * 0.5f;
  float half_delta_y = (to_y - from_y) * 0.5f;
  float half_delta_z = (to_z - from_z) * 0.5f;

  const float half_delta_magnitude_squared = half_delta_x * half_delta_x +
                                             half_delta_y * half_delta_y +
                                             half_delta_z * half_delta_z;
  const float length_squared = length * length * 0.25f;
  const float capped_half_delta_magnitude_squared =
      lesser(half_delta_magnitude_squared, length_squared);
  const float bend =
      square_root(length_squared - capped_half_delta_magnitude_squared);

  const float half_delta_inverse_magnitude =
      inverse_square_root(half_delta_magnitude_squared);

  const float delta_x = half_delta_x * half_delta_inverse_magnitude;
  const float delta_y = half_delta_y * half_delta_inverse_magnitude;
  const float delta_z = half_delta_z * half_delta_inverse_magnitude;

  float bend_x = delta_y * y_z - y_y * delta_z;
  float bend_y = delta_z * y_x - y_z * delta_x;
  float bend_z = delta_x * y_y - y_x * delta_y;

  const float bend_inverse_magnitude =
      inverse_square_root(bend_x * bend_x + bend_y * bend_y + bend_z * bend_z);

  bend_x *= bend_inverse_magnitude;
  bend_y *= bend_inverse_magnitude;
  bend_z *= bend_inverse_magnitude;

  float adjusted_y_x = bend_y * delta_z - delta_y * bend_z;
  float adjusted_y_y = bend_z * delta_x - delta_z * bend_x;
  float adjusted_y_z = bend_x * delta_y - delta_x * bend_y;

  const float joint_x = from_x + half_delta_x + bend_x * bend;
  const float joint_y = from_y + half_delta_y + bend_y * bend;
  const float joint_z = from_z + half_delta_z + bend_z * bend;

  float from_joint_x_x = joint_x - from_x;
  float from_joint_x_y = joint_y - from_y;
  float from_joint_x_z = joint_z - from_z;

  const float from_joint_x_inverse_magnitude = inverse_square_root(
      from_joint_x_x * from_joint_x_x + from_joint_x_y * from_joint_x_y +
      from_joint_x_z * from_joint_x_z);

  from_joint_x_x *= from_joint_x_inverse_magnitude;
  from_joint_x_y *= from_joint_x_inverse_magnitude;
  from_joint_x_z *= from_joint_x_inverse_magnitude;

  float from_joint_z_x =
      from_joint_x_y * adjusted_y_z - adjusted_y_y * from_joint_x_z;
  float from_joint_z_y =
      from_joint_x_z * adjusted_y_x - adjusted_y_z * from_joint_x_x;
  float from_joint_z_z =
      from_joint_x_x * adjusted_y_y - adjusted_y_x * from_joint_x_y;

  const float from_joint_z_magnitude = inverse_square_root(
      from_joint_z_x * from_joint_z_x + from_joint_z_y * from_joint_z_y +
      from_joint_z_z * from_joint_z_z);

  from_joint_z_x *= from_joint_z_magnitude;
  from_joint_z_y *= from_joint_z_magnitude;
  from_joint_z_z *= from_joint_z_magnitude;

  float joint_to_x_x = to_x - joint_x;
  float joint_to_x_y = to_y - joint_y;
  float joint_to_x_z = to_z - joint_z;

  joint_to_x_x *= from_joint_x_inverse_magnitude;
  joint_to_x_y *= from_joint_x_inverse_magnitude;
  joint_to_x_z *= from_joint_x_inverse_magnitude;

  float joint_to_z_x =
      joint_to_x_y * adjusted_y_z - adjusted_y_y * joint_to_x_z;
  float joint_to_z_y =
      joint_to_x_z * adjusted_y_x - adjusted_y_z * joint_to_x_x;
  float joint_to_z_z =
      joint_to_x_x * adjusted_y_y - adjusted_y_x * joint_to_x_y;

  const float joint_to_z_magnitude = inverse_square_root(
      joint_to_z_x * joint_to_z_x + joint_to_z_y * joint_to_z_y +
      joint_to_z_z * joint_to_z_z);

  joint_to_z_x *= joint_to_z_magnitude;
  joint_to_z_y *= joint_to_z_magnitude;
  joint_to_z_z *= joint_to_z_magnitude;

  proximal_forward[0] = from_joint_x_x;
  proximal_forward[1] = adjusted_y_x;
  proximal_forward[2] = from_joint_z_x;
  proximal_forward[3] = from_x;
  proximal_forward[4] = from_joint_x_y;
  proximal_forward[5] = adjusted_y_y;
  proximal_forward[6] = from_joint_z_y;
  proximal_forward[7] = from_y;
  proximal_forward[8] = from_joint_x_z;
  proximal_forward[9] = adjusted_y_z;
  proximal_forward[10] = from_joint_z_z;
  proximal_forward[11] = from_z;
  proximal_forward[12] = 0.0f;
  proximal_forward[13] = 0.0f;
  proximal_forward[14] = 0.0f;
  proximal_forward[15] = 1.0f;

  proximal_inverse[0] = from_joint_x_x;
  proximal_inverse[1] = from_joint_x_y;
  proximal_inverse[2] = from_joint_x_z;
  proximal_inverse[3] = -(from_x * from_joint_x_x + from_y * from_joint_x_y +
                          from_z * from_joint_x_z);
  proximal_inverse[4] = adjusted_y_x;
  proximal_inverse[5] = adjusted_y_y;
  proximal_inverse[6] = adjusted_y_z;
  proximal_inverse[7] =
      -(from_x * adjusted_y_x + from_y * adjusted_y_y + from_z * adjusted_y_z);
  proximal_inverse[8] = from_joint_z_x;
  proximal_inverse[9] = from_joint_z_y;
  proximal_inverse[10] = from_joint_z_z;
  proximal_inverse[11] = -(from_x * from_joint_z_x + from_y * from_joint_z_y +
                           from_z * from_joint_z_z);
  proximal_inverse[12] = 0.0f;
  proximal_inverse[13] = 0.0f;
  proximal_inverse[14] = 0.0f;
  proximal_inverse[15] = 1.0f;

  distal_forward[0] = joint_to_x_x;
  distal_forward[1] = adjusted_y_x;
  distal_forward[2] = joint_to_z_x;
  distal_forward[3] = joint_x;
  distal_forward[4] = joint_to_x_y;
  distal_forward[5] = adjusted_y_y;
  distal_forward[6] = joint_to_z_y;
  distal_forward[7] = joint_y;
  distal_forward[8] = joint_to_x_z;
  distal_forward[9] = adjusted_y_z;
  distal_forward[10] = joint_to_z_z;
  distal_forward[11] = joint_z;
  distal_forward[12] = 0.0f;
  distal_forward[13] = 0.0f;
  distal_forward[14] = 0.0f;
  distal_forward[15] = 1.0f;

  distal_inverse[0] = joint_to_x_x;
  distal_inverse[1] = joint_to_x_y;
  distal_inverse[2] = joint_to_x_z;
  distal_inverse[3] = -(joint_x * joint_to_x_x + joint_y * joint_to_x_y +
                        joint_z * joint_to_x_z);
  distal_inverse[4] = adjusted_y_x;
  distal_inverse[5] = adjusted_y_y;
  distal_inverse[6] = adjusted_y_z;
  distal_inverse[7] = -(joint_x * adjusted_y_x + joint_y * adjusted_y_y +
                        joint_z * adjusted_y_z);
  distal_inverse[8] = joint_to_z_x;
  distal_inverse[9] = joint_to_z_y;
  distal_inverse[10] = joint_to_z_z;
  distal_inverse[11] = -(joint_x * joint_to_z_x + joint_y * joint_to_z_y +
                         joint_z * joint_to_z_z);
  distal_inverse[12] = 0.0f;
  distal_inverse[13] = 0.0f;
  distal_inverse[14] = 0.0f;
  distal_inverse[15] = 1.0f;
}
