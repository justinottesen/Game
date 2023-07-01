#include "Map.h"

#include <utility>

#include "Defaults.h"
#include "Vecs.h"

const Tile& Map::getTile(const Vec2<int>& coords) const
{
  const Vec2<int> chunk_coords = Chunk::chunkCoords(coords);
  if (!m_Chunks.contains(chunk_coords)) {
    m_Chunks.insert(std::make_pair(chunk_coords, Chunk(m_Seed, chunk_coords)));
  }
  return m_Chunks.at(chunk_coords).getTile(Chunk::localCoords(coords));
}

Map::Chunk::Chunk(unsigned int seed, const Vec2<int>& chunk_coords) : m_Tiles()
{
  (void)seed;
  (void)chunk_coords;
  for (Tile& tile : m_Tiles) { tile.type = Tile::LAND; }
}

const Tile& Map::Chunk::getTile(const Vec2<int>& local_coords) const
{
  return m_Tiles.at(local_coords.x * defaults::chunk_size + local_coords.y);
}

Vec2<int> Map::Chunk::chunkCoords(const Vec2<int>& global_coords)
{
  Vec2<int> chunk_coords = global_coords;
  if (global_coords.x < 0) {
    chunk_coords.x++;
    chunk_coords.x *= -1;
  }
  if (global_coords.y < 0) {
    chunk_coords.y++;
    chunk_coords.y *= -1;
  }
  chunk_coords.x /= static_cast<int>(defaults::chunk_size);
  chunk_coords.y /= static_cast<int>(defaults::chunk_size);
  if (global_coords.x < 0) {
    chunk_coords.x++;
    chunk_coords.x *= -1;
  }
  if (global_coords.y < 0) {
    chunk_coords.y++;
    chunk_coords.y *= -1;
  }
  return chunk_coords;
}

Vec2<int> Map::Chunk::localCoords(const Vec2<int>& global_coords)
{
  Vec2<int> local_coords = global_coords;
  local_coords.x %= 5;
  local_coords.y %= 5;
  if (local_coords.x < 0) { local_coords.x += defaults::chunk_size; }
  if (local_coords.y < 0) { local_coords.y += defaults::chunk_size; }
  return local_coords;
}