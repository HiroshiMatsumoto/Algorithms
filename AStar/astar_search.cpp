#include "astar_search.hpp"
#include "spdlog/spdlog.h"

#ifndef UTIL_H
#include "util.hpp"
#endif

#ifndef NODE_H
#include "Node.hpp"
#endif

typedef std::vector<Node::Node> List;
typedef std::pair<float, float> Coordinate;

auto node_compare = [](Node::Node a, Node::Node b) { return a.f < b.f; };

std::ostream &operator<<(std::ostream &stream, const Node::Node node) {
  stream << "(x:" << node.coordinate.first
    << ", y:" << node.coordinate.second
    << ", f:" << node.f
    << ", state:" << node.is_open
    << ")";
  return stream;
}
auto filterOpenList = [](const Node::Node &node) {
  return node.is_open == true;
};

std::pair<int, Node::Node> find_min_node(List list) {
  Node::Node min_node(-1, -1);
  min_node.f = 999;
  int min_node_idx = 0;
  List::iterator open_list_itr =
      std::find_if(list.begin(), list.end(), filterOpenList);
  while (open_list_itr != list.end()) {
    Node::Node tmp = *open_list_itr;
    // get min node
    if (tmp.f < min_node.f) {
      min_node = tmp;
      min_node_idx = std::distance(list.begin(), open_list_itr);
    }
    open_list_itr = std::find_if(++open_list_itr, list.end(), filterOpenList);
  }
  return std::make_pair(min_node_idx, min_node);
}

List::iterator find_node_in_list(List list, Node::Node target) {
  return std::find_if(list.begin(), list.end(),
                      [&target](const Node::Node &node) {
                      std::cout << "node: " << node << std::endl;
                      std::cout << "target: " << target << std::endl;
                        return node.coordinate == target.coordinate;
                      });
}
int find_node_in_list(void) { return 0; }
#include <queue>
#include <tuple>
// std::vector<Node::Node> astar_search(std::vector<std::string> map){
Node::Node astar_search(std::vector<std::string> map) {

  std::pair<float, float> up = {-1, 0};
  std::pair<float, float> down = {1, 0};
  std::pair<float, float> left = {0, -1};
  std::pair<float, float> right = {0, 1};
  std::vector<Coordinate> directions = {up, down, left, right};
  // create two lists: open-list, close-list
  List list;
  // Start Node
  Node::Node start = find_position('S', map);
  // std::cout << "S: " << start << std::endl;
  // Goal Node
  Node::Node goal = find_position('G', map);
  // std::cout << "G: " << goal << std::endl;

  start.g = 0;
  start.h = util::manhattan_distance(start.coordinate, goal.coordinate);
  start.f = start.g + 0 + start.h;
  start.is_open = true;
  list.push_back(start);

  // get node with minimum f from open list, move it to close list
  std::pair<int, Node::Node> min_node_pair = find_min_node(list);
  int min_node_idx = min_node_pair.first;
  Node::Node min_node = min_node_pair.second;
  list[min_node_idx].is_open = false;

  Node::Node NotFound(-1, -1);
  while(min_node.coordinate != NotFound.coordinate && min_node.coordinate != goal.coordinate) {
    // get available directions at min_node
    std::vector<Coordinate>::iterator dir_itr;
    for (dir_itr = directions.begin(); dir_itr != directions.end(); ++dir_itr) {
      Coordinate direction = (*dir_itr);

      // neighbor node
      Node::Node neighbor_node(min_node.coordinate.first + direction.first,
                               min_node.coordinate.second + direction.second);
      // std::cout << neighbor_node << std::endl; 
      // check if neighbor_node is wall
      if (
          neighbor_node.x < 0  ||
          (int)map.size() < neighbor_node.x ||
          neighbor_node.y < 0  ||
          (int)map[0].length() < neighbor_node.y ||
          map[neighbor_node.x][neighbor_node.y] == '|' ||
          map[neighbor_node.x][neighbor_node.y] == '+' ||
          map[neighbor_node.x][neighbor_node.y] == '-')
        continue;

      // calc f, g, h for neighbor node
      neighbor_node.g = (min_node.f - min_node.h);
      neighbor_node.h =
          util::manhattan_distance(neighbor_node.coordinate, goal.coordinate);
      neighbor_node.f = neighbor_node.g + 1 + neighbor_node.h;
      neighbor_node.parent_ptr = &list[min_node_idx];
      // insert neighbor node in open list
      // List::iterator list_node = find_node_in_list(list, neighbor_node); // find_node_in_list function returns rubbish result
      List::iterator list_node = std::find_if(list.begin(), list.end(),[&neighbor_node](const Node::Node &node){ return node.coordinate == neighbor_node.coordinate;}); 
      if(list_node == list.end()) { // not in list
        neighbor_node.is_open = true;
        list.push_back(neighbor_node);
      } 
      else if (neighbor_node.f <
            (*list_node).f) { // if f value is lower than exisiting one, update
          (*list_node).f = neighbor_node.f;
          (*list_node).parent_ptr = neighbor_node.parent_ptr;
          if ((*list_node).is_open ==
              false){ // if node is in close, change it to open
            (*list_node).is_open = true;
          }
      } // update node in list
    } // all directions process 
  
    // update min_node from open-list
    min_node_pair = find_min_node(list);
    min_node_idx = min_node_pair.first; 
    min_node = min_node_pair.second;
    min_node.is_open = list[min_node_idx].is_open = false;
  }
  return min_node;
}


std::vector<std::pair<int, int>> trace_path(Node::Node node){
  std::vector<std::pair<int, int>> path;
  int i = 0;
  while(node.parent_ptr != nullptr){
    // std::cout << node << std::endl;
    path.push_back(node.coordinate);
    node = *(node.parent_ptr); 
    i++;
  }
  std::reverse(path.begin(), path.end());
  return path;
}




