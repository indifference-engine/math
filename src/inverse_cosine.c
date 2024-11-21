#include "inverse_cosine.h"
#include "inverse_sine.h"
#include "half_pi.h"

float inverse_cosine(const float sine)
{
  return HALF_PI - inverse_sine(sine);
}
