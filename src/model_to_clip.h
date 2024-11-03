#ifndef MODEL_TO_CLIP_H

#define MODEL_TO_CLIP_H

/**
 * Transforms a 3-dimensional vector from model space into clip space using a
 * 4x4 model-view-projection matrix.
 * @remark Coordinates are only culled when W is zero or Z is not within the -1
 *         to 1 range; X and Y may be any values.
 * @param model The 3-dimensional vector in model space to transform.  Behavior
 *              is undefined if any are NaN, infinity or negative infinity.
 * @param model_view_projection The 4x4 model-view-projection matrix to apply.
 *                              Behavior is undefined if any are NaN, infinity,
 *                              or negative infinity.
 * @param clip Overwritten with the corresponding 3-dimensional vector in clip
 *             space when not culled, otherwise unmodified.  May be "model".
 * @return The culling which occurred, if any (see CULLED_BY_*).
 */
int model_to_clip(
    const float *const model,
    const float *const model_view_projection,
    float *const clip);

#endif
