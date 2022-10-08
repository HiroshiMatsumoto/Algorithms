#ifndef STARSEARCH_H
#define STARSEARCH_H

#include <fstream>
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <iterator>

#ifndef NODE_H
#include "Node.hpp"
#endif

// std::vector<Node::Node> astar_search(std::vector<std::string> map);
Node::Node astar_search(std::vector<std::string> map);

std::vector<std::pair<int, int>> trace_path(Node::Node node); 
#endif
