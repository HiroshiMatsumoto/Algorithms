#ifndef STARSEARCH_H
#define STARSEARCH_H

#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <cmath>
#include <algorithm>

std::vector<std::string> load_map(std::string filepath);
float euclid_distance(std::tuple<int, int> pos1, std::tuple<int, int> pos2);
int manhattan_distance(std::tuple<int, int> pos1, std::tuple<int, int> pos2);
void start_search(std::vector<std::string> map);

#endif
