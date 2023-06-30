#ifndef RENDERER_H
#define RENDERER_H

#include "Map.h"
#include "Vecs.h"

class Renderer {
public:
  Renderer(const Map* map, const Vec2<unsigned int>& dimensions) :
      m_Map(map), m_ViewDimensions{dimensions}, m_Coordinates{0, 0} {}

  void render() const;

private:
  const Map*         m_Map;

  Vec2<unsigned int> m_ViewDimensions;
  Vec2<int>          m_Coordinates;
};

#endif
