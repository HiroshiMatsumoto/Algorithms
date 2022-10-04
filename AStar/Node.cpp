#include "Node.hpp"


// std::tuple<int, int> 
Node::Node find_position(char target, std::vector<std::string> map){
  Node::Node node(0, 0);
  for(int i = 0; i < map.size(); i++){
    for(int j = 0; j < map[i].size(); j++){
      if(map[i][j] == target){
        node.x = i;
        node.y = j;
        return node;// std::forward_as_tuple(i, j); 
      }
    }
  }
  // return std::forward_as_tuple(-1, -1); 
}

