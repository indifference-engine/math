#ifndef CLIP_TO_MODEL_H

#define CLIP_TO_MODEL_H

/**
 * Transforms a 3-dimensional vector from clip space into world space using a
 * 4x4 inverse model-view-projection matrix.
 * @remark Coordinates are only culled when W is 0; X, Y and Z may be any
 *         values.
 * @param clip The 3-dimensional vector in clip space to transform.  Behavior is
 *             undefined if any are NaN, infinity or negative infinity.
 * @param inverse_model_view_projection The 4x4 inverse model-view-projection
 *                                      matrix to apply.  Behavior is undefined
 *                                      if any are NaN, infinity or negative
 *                                      infinity.
 * @param model Overwritten with the corresponding 3-dimensional vector in model
 *              space when not culled, otherwise unmodified.  May be "clip".
 * @return The culling which occurred, if any (see CULLED_BY_*).
 */
int clip_to_model(
    const float *const clip,
    const float *const inverse_model_view_projection,
    float *const model);

#endif
