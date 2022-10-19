#include <iostream>
#include <vector>

/*
任意個数の要素をコンテナに追加
*/

template<typename C, typename... Args>
void push_back(C& c, Args&&... args){
  (c.push_back(args), ...); // 畳み込み式
}

int main(){
  std::vector<int> vec;
  vec.push_back(1);

  // task
  // push_back(vec,1,2,3,4);
  push_back(vec,2,3,4,5);

  std::vector<int>::iterator itr = vec.begin();
  while(itr != vec.end()){
    std::cout << *itr << std::endl;
    itr++;
  }
  return 0;
}