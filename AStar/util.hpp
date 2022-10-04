#ifndef UTIL_H
#define UTIL_H
#include <fstream>
#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>


namespace Util
{
  std::vector<std::string> load_map(std::string filepath);
  float euclid_distance(std::tuple<int, int> pos1, std::tuple<int, int> pos2);
  int manhattan_distance(std::tuple<int, int> pos1, std::tuple<int, int> pos2);
}
#endif
