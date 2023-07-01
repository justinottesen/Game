#ifndef UTILITY_H
#define UTILITY_H

#include <cstddef>
#include <functional>

template <class T>
struct Vec2
{
 public:
  T x, y;

  bool operator==(const Vec2& other) const { return x == other.x && y == other.y; }
};

template <>
struct std::hash<Vec2<int>>
{
  std::size_t operator()(const Vec2<int>& vec) const noexcept
  {
    return std::hash<int>{}(vec.x) ^ (std::hash<int>{}(vec.y) << 1U);
  }
};

template <class T>
struct Vec3
{
 public:
  T x, y, z;
};

template <class T>
struct Vec4
{
 public:
  T x, y, z, w;
};

#endif
