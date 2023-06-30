#ifndef MAP_H
#define MAP_H

class Map {
public:
  explicit Map(unsigned int seed) : m_Seed(seed) {}

private:
  unsigned int m_Seed;
};

#endif
