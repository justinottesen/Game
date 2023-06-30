#ifndef ENGINE_H
#define ENGINE_H

#include <memory>

#include "Map.h"
#include "Renderer.h"
#include "Vecs.h"

namespace defaults {
  constexpr unsigned int       seed = 69420;

  constexpr Vec2<unsigned int> renderer_dimensions{160, 100};
};  // namespace defaults

class Engine {
public:
  Engine() :
      m_Map(std::make_unique<Map>(defaults::seed)),
      m_Renderer(std::make_unique<Renderer>(m_Map.get(),
                                            defaults::renderer_dimensions)) {}

  void run() { m_Renderer->render(); }

private:
  std::unique_ptr<Map>      m_Map;
  std::unique_ptr<Renderer> m_Renderer;
};

#endif
