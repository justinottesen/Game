#ifndef DEFAULTS_H
#define DEFAULTS_H

#include "Vecs.h"

namespace defaults {
  // MAP GENERATION INFO
  constexpr unsigned int seed       = 69420;
  constexpr unsigned int chunk_size = 32;

  // RENDERING
  constexpr Vec2<unsigned int> renderer_dimensions{160, 100};
};  // namespace defaults

#endif