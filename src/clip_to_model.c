#include "clip_to_model.h"
#include "culled_by.h"

int clip_to_model(const float *const clip,
                  const float *const inverse_model_view_projection,
                  float *const model) {
  const float clip_x = clip[0];
  const float clip_y = clip[1];
  const float clip_z = clip[2];

  const float w = inverse_model_view_projection[12] * clip_x +
                  inverse_model_view_projection[13] * clip_y +
                  inverse_model_view_projection[14] * clip_z +
                  inverse_model_view_projection[15];

  if (w == 0.0f) {
    return CULLED_BY_W_ZERO;
  } else {
    const float w_reciprocal = 1.0f / w;

    model[0] = (inverse_model_view_projection[0] * clip_x +
                inverse_model_view_projection[1] * clip_y +
                inverse_model_view_projection[2] * clip_z +
                inverse_model_view_projection[3]) *
               w_reciprocal;
    model[1] = (inverse_model_view_projection[4] * clip_x +
                inverse_model_view_projection[5] * clip_y +
                inverse_model_view_projection[6] * clip_z +
                inverse_model_view_projection[7]) *
               w_reciprocal;
    model[2] = (inverse_model_view_projection[8] * clip_x +
                inverse_model_view_projection[9] * clip_y +
                inverse_model_view_projection[10] * clip_z +
                inverse_model_view_projection[11]) *
               w_reciprocal;

    return CULLED_BY_NOTHING;
  }
}
