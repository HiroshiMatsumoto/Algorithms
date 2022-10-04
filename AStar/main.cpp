#include <iostream>
#include <vector>
#include "util.hpp"
#include "astar_search.hpp"
#include <queue>

int main(){
  std::vector<std::string> map;
  map = Util::load_map("./map.txt");
  start_search(map);
  return 0;
}
