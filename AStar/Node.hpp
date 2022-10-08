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
  Node() {
    x = -1;
    y = -1;
    coordinate = std::make_pair(x, y);
    parent_ptr = nullptr;
  };
  Node(int a, int b) : x(a), y(b), is_open(true) {
    coordinate = std::make_pair(a, b);
    parent_ptr = nullptr;
  };

  int x;
  int y;
  std::pair<float, float> coordinate;

  float f; // g + h
  float g;
  float h;

  bool is_open;
  Node *parent_ptr;

  bool operator==(const Node &node) { return coordinate == node.coordinate; }
  void set_coordinate(int a, int b);
};
}

Node::Node find_position(char target, std::vector<std::string> map);
#endif
