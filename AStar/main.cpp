#include <iostream>
#include <vector>
#include "util.hpp"
#include "astar_search.hpp"
#include <queue>

int main(){
  std::vector<std::string> map;
  map = util::load_map("./map.txt");

  Node::Node goal = astar_search(map);
  std::vector<std::pair<int, int>> path = trace_path(goal);
  
  for(std::vector<std::pair<int, int>>::iterator itr = path.begin(); itr != path.end(); ++itr){
    if(map[(*itr).first][(*itr).second] == 'S' || map[(*itr).first][(*itr).second] == 'G')
      continue;
    map[(*itr).first][(*itr).second] = '.';
  }

  for(std::vector<std::string>::iterator itr = map.begin();itr != map.end(); ++itr){
    std::cout << *itr << std::endl;
  }
 return 0;
}
