#include "util.hpp"

namespace Util {

std::vector<std::string>
load_map(std::string filepath) { // std::string filepath){
  std::ifstream read_file;
  read_file.open(filepath, std::ios::in);
  std::string line = "";

  std::vector<std::string> map = {};
  if (read_file.fail()) {
    std::cerr << "Failed to open file. " << std::endl;
    // return -1;
  }
  while (getline(read_file, line)) {

    map.push_back(line);
    // std::cout << line << std::endl;
  }
  return map;
}

float euclid_distance(std::tuple<int, int> pos1, std::tuple<int, int> pos2) {

  int pos1_x, pos1_y, pos2_x, pos2_y;
  float dist = 0;
  std::tie(pos1_x, pos1_y) = pos1;
  std::tie(pos2_x, pos2_y) = pos2;

  return std::sqrt((pos1_x - pos2_x) ^ 2 + (pos1_y - pos2_y) ^ 2);
}

int manhattan_distance(std::tuple<int, int> pos1, std::tuple<int, int> pos2) {

  int pos1_x, pos1_y, pos2_x, pos2_y;
  int distance = 0;
  std::tie(pos1_x, pos1_y) = pos1;
  std::tie(pos2_x, pos2_y) = pos2;
  return pos1_x + pos2_x + pos1_y + pos2_y;
}
} // namespace Util
