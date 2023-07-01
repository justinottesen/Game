#include "Renderer.h"

#include <iostream>

#include "Vecs.h"

void Renderer::render() const
{
  Vec2<unsigned int> screen_coords{0, 0};
  for (screen_coords.y = 0; screen_coords.y < m_ViewDimensions.y; screen_coords.y++) {
    for (screen_coords.x = 0; screen_coords.x < m_ViewDimensions.x; screen_coords.x++) {
      std::cout << (screen_coords.x + screen_coords.y) % 10;
    }
    std::cout << "\n";
  }
}
