#ifndef NODE_H
#define NODE_H

#include <cmath>
#include <tuple>
#include <vector>

#ifndef UTIL_H
#include "util.hpp"
#endif

namespace Node {

class Node {
public:
  // constructor
  Node(int pos_x, int pos_y) {
    x = pos_x;
    y = pos_y;
    coordinate = {x, y};
  };

  // members
  // cordinate
  int x;
  int y;
  std::tuple<int, int> coordinate;

  int f; // g + h
  int g;
  int h;
  
  bool operator==(const Node &node){
    return coordinate == node.coordinate;
  }

  bool operator=(const Node &node){
    return this; 
  }


};
} // namespace Node

Node::Node find_position(char target, std::vector<std::string> map);
#endif
