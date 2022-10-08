#include "Node.hpp"

void Node::Node::set_coordinate(int a, int b){
  x = a;
  y = b;
  coordinate = std::make_pair(a, b);
}

// std::tuple<int, int> 
Node::Node find_position(char target, std::vector<std::string> map){
  for(int i = 0; i < map.size(); i++){
    for(int j = 0; j < map[i].size(); j++){
      if(map[i][j] == target){
        Node::Node node(i, j);// std::forward_as_tuple(i, j); 
        return node; 
      }
    }
  }
  // return std::forward_as_tuple(-1, -1); 
}

