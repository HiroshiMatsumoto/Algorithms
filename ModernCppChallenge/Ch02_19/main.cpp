#include <iostream>
#include <vector>

/*
任意個数の要素をコンテナに追加
*/

int main(){
  std::vector<int> vec;
  vec.push_back(1);

  // task
  // vec.push_back(1,2,3,4);

  std::vector<int>::iterator itr = vec.begin();
  while(itr != vec.end()){
    std::cout << *itr << std::endl;
    itr++;
  }
  return 0;
}