#ifndef MAP_H
#define MAP_H

#include <array>
#include <cstddef>
#include <unordered_map>

#include "Defaults.h"
#include "Vecs.h"

struct Tile
{
  enum Type { LAND };

  Type type;
};

class Map
{
 public:
  explicit Map(unsigned int seed) : m_Seed(seed) {}

  const Tile& getTile(const Vec2<int>& coords) const;

 private:
  class Chunk
  {
   public:
    explicit Chunk(unsigned int seed, const Vec2<int>& chunk_coords);

    [[nodiscard]] const Tile& getTile(const Vec2<int>& local_coords) const;

    static Vec2<int> chunkCoords(const Vec2<int>& global_coords);
    static Vec2<int> localCoords(const Vec2<int>& global_coords);

   private:
    std::array<Tile, static_cast<std::size_t>(defaults::chunk_size* defaults::chunk_size)> m_Tiles;
  };

  unsigned int m_Seed;

  mutable std::unordered_map<Vec2<int>, Chunk> m_Chunks;
};

#endif
