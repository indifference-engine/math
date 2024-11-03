void perspective(
    const float height,
    const float width,
    const float focal_length,
    const float shift_y,
    const float shift_x,
    const float clip_start,
    const float clip_end,
    const float sensor_size,
    float *const forward,
    float *const inverse)
{
  const float greatest_dimension = width > height ? width : height;
  const float width_reciprocal = 1.0f / width;
  const float height_reciprocal = 1.0f / height;
  const float greatest_dimension_reciprocal = width_reciprocal > height_reciprocal ? height_reciprocal : width_reciprocal;
  const float double_greatest_dimension = greatest_dimension * 2.0f;
  const float focal_length_reciprocal = 1.0f / focal_length;
  const float b = sensor_size * focal_length_reciprocal * greatest_dimension_reciprocal;
  const float half_b = 0.5f * b;
  const float half_b_reciprocal = 1.0f / half_b;
  const float c = clip_start - clip_end;
  const float c_reciprocal = 1.0f / c;
  const float d = clip_start * clip_end * 2.0f;
  const float d_reciprocal = 1.0f / d;
  const float e = clip_end + clip_start;
  forward[0] = width_reciprocal * half_b_reciprocal;
  forward[1] = 0.0f;
  forward[2] = shift_x * double_greatest_dimension * width_reciprocal;
  forward[3] = 0.0f;
  forward[4] = 0.0f;
  forward[5] = height_reciprocal * half_b_reciprocal;
  forward[6] = shift_y * double_greatest_dimension * height_reciprocal;
  forward[7] = 0.0f;
  forward[8] = 0.0f;
  forward[9] = 0.0f;
  forward[10] = e * c_reciprocal;
  forward[11] = d * c_reciprocal;
  forward[12] = 0.0f;
  forward[13] = 0.0f;
  forward[14] = -1.0f;
  forward[15] = 0.0f;
  inverse[0] = width * half_b;
  inverse[1] = 0.0f;
  inverse[2] = 0.0f;
  inverse[3] = shift_x * sensor_size * focal_length_reciprocal;
  inverse[4] = 0.0f;
  inverse[5] = height * half_b;
  inverse[6] = 0.0f;
  inverse[7] = shift_y * sensor_size * focal_length_reciprocal;
  inverse[8] = 0.0f;
  inverse[9] = 0.0f;
  inverse[10] = 0.0f;
  inverse[11] = -1.0f;
  inverse[12] = 0.0f;
  inverse[13] = 0.0f;
  inverse[14] = c * d_reciprocal;
  inverse[15] = e * d_reciprocal;
}
