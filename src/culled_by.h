#ifndef CULLED_BY_H

#define CULLED_BY_H

/**
 * No culling has occurred.
 */
#define CULLED_BY_NOTHING 0

/**
 * Culling occurred as W was zero.
 */
#define CULLED_BY_W_ZERO 1

/**
 * Culling occurred as Z was closer than the Z near plane.
 */
#define CULLED_BY_Z_NEAR_PLANE 2

/**
 * Culling occurred as Z was further than the Z far plane.
 */
#define CULLED_BY_Z_FAR_PLANE 3

#endif
