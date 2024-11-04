#include "model_to_clip.h"
#include "culled_by.h"

int model_to_clip(
    const float *const model,
    const float *const model_view_projection,
    float *const clip)
{
  const float model_x = model[0];
  const float model_y = model[1];
  const float model_z = model[2];

  const float w = model_view_projection[12] * model_x + model_view_projection[13] * model_y + model_view_projection[14] * model_z + model_view_projection[15];

  if (w == 0.0f)
  {
    return CULLED_BY_W_ZERO;
  }
  else
  {
    const float w_reciprocal = 1.0f / w;

    const float z = (model_view_projection[8] * model_x + model_view_projection[9] * model_y + model_view_projection[10] * model_z + model_view_projection[11]) * w_reciprocal;

    if (z < -1.0f)
    {
      return CULLED_BY_Z_FAR_PLANE;
    }
    else if (z > 1.0f)
    {
      return CULLED_BY_Z_NEAR_PLANE;
    }
    else
    {
      clip[0] = (model_view_projection[0] * model_x + model_view_projection[1] * model_y + model_view_projection[2] * model_z + model_view_projection[3]) * w_reciprocal;
      clip[1] = (model_view_projection[4] * model_x + model_view_projection[5] * model_y + model_view_projection[6] * model_z + model_view_projection[7]) * w_reciprocal;
      clip[2] = z;

      return CULLED_BY_NOTHING;
    }
  }
}
