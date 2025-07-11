#include "inverse_cosine.h"
#include "half_pi.h"
#include "inverse_sine.h"

float inverse_cosine(const float sine) { return HALF_PI - inverse_sine(sine); }
