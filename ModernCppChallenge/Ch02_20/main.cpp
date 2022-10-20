#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
/*
コンテナのany, all, none関数
*/

template<class C, class V>
bool contains(C c, V v){
  auto result = std::find(c.begin(), c.end(), v);
  return result != c.end();
}

template<typename C, typename... Args>
bool contains_any(C c, Args... args){  
  return (... || contains(c, args));
}

template<typename C, typename... Args>
bool contains_all(C c, Args... args){  
  return (... && contains(c, args));
}

template<typename C, typename... Args>
bool contains_none(C c, Args... args){  
  return (... && !contains(c, args));
}

int main(){
  // any
  std::vector<int> vec {1,2,3,4,5};
  assert(contains(vec, 5));
  assert(contains_any(vec, 1, 2, 3));

  // all
  assert(contains_all(vec, 1, 2, 3));

  // none
  assert(contains_none(vec, 6, 7, 8));
  return 0;
}