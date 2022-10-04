#include <fstream>
#include <iostream>
#include <iterator>
#include <queue>
#include <vector>
#include "star_search.hpp"

#ifndef UTIL_H
#include "util.hpp"
#endif

#ifndef NODE_H
#include "Node.hpp"
#endif

#include <algorithm>


auto node_compare = [](Node::Node a, Node::Node b){
  return a.f < b.f;
};

void start_search(std::vector<std::string> map){
  // Initialize the open list
  std::cout << "star_search" << std::endl;
  // neither priority_queue<Node> with class operator< overload 
  // nor simple operator< overload with Node1, Node2 did work 
  // std::priority_queue<Node::Node, std::vector<Node::Node>, decltype(node_compare)> openList {node_compare};
  std::vector<Node::Node> openList;
  // Initialize the closed list
  std::vector<Node::Node> closedList;
  // std::priority_queue<Node::Node, std::vector<Node::Node>, decltype(node_compare)> closedList {node_compare};
  /// std::priority_queue<Node::Node> closedList;
  // Start Node
  Node::Node start = find_position('S', map); 
  // Goal Node
  Node::Node goal = find_position('G', map); 

  start.g = 0;
  start.h = Util::manhattan_distance(start.coordinate, goal.coordinate); 
  start.f = start.g + start.h;
  // openList.push(start);
  openList.push_back(start);
  

  std::tuple<int, int> up = {-1, 0};  
  std::tuple<int, int> down = {1, 0}; 
  std::tuple<int, int> right = {0, 1};
  std::tuple<int, int> left = {0, -1};

  std::vector<std::tuple<int, int>> directions = { up, down, right, left }; 
  std::tuple<int, int> next; 
  std::vector<Node::Node>::iterator listitr;
 
  bool skip_this = false;
  // while open list is not empty
  while(!openList.empty()){
    // get the node with smallest f
    int counter = 0;
    Node::Node q = openList[0];

    for(listitr = openList.begin(); listitr != openList.end(); ++listitr){
      Node::Node tmp = *listitr;
      if( tmp.f  < q.f ) 
        q = tmp; 
    }
    // remove q from openList
    
    // for each direction at q
    std::vector<std::tuple<int, int>>::iterator direction_itr;
    for(direction_itr = directions.begin(); direction_itr != directions.end(); ++direction_itr){
        
      std::tuple<int, int> direction = *direction_itr;
      int x = std::get<0>(q.coordinate) + std::get<0>(direction);
      int y = std::get<1>(q.coordinate) + std::get<1>(direction); 
      
      // get char at the coordinate on tha map

      Node::Node successor(x, y);

      if(successor.coordinate == goal.coordinate)
        return;
      
      successor.g = q.g + Util::manhattan_distance(successor.coordinate, q.coordinate);
      successor.h = Util::manhattan_distance(successor.coordinate, goal.coordinate);
      successor.f = successor.g + successor.h;

      // if successor.coordinate == node in openList and openList[node.coordinate == successor.coordinate].f < successor.f, continue;
      skip_this = false; 
      for(listitr = openList.begin(); listitr != openList.end(); ++listitr){
        if( skip_this )
          break;
        Node::Node tmp = *listitr;
        if(tmp.coordinate == successor.coordinate && tmp.f < successor.f)
         skip_this = true;
      }

      // if successor.coordinate == node in openList and openList[node.coordinate == successor.coordinate].f < successor.f, continue;
      skip_this = false; 
      for(listitr = closedList.begin(); listitr != closedList.end(); ++listitr){
        if( skip_this )
          break;
        Node::Node tmp = *listitr;
        if(tmp.coordinate == successor.coordinate && tmp.f < successor.f){
         closedList.push_back(tmp);
         skip_this = true;
        }

      }
    }
  // push q to closedList
  closedList.push_back(q);
  break;
  }
}
