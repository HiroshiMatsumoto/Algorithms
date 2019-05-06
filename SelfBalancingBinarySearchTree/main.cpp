/******************************************************
 * 平衡二分探索木: 二分探索木のうち木の高さ（根からの階層の数）を自動的にできるだけ小さく維持しようとするもの
 * https://ja.wikipedia.org/wiki/平衡二分探索木
 *
 * 木の高さをできるだけ小さく維持: 左部分技, 右部分技の高さの差(平衡係数, k)
 * 
 * AVL木: 「どのノードの左右部分木の高さの差も1以下」という条件を満たす2分探索木のこと(k<=1)
 * https://ja.wikipedia.org/wiki/AVL木
 *******************************************************/
#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main(){
  NodePtr head = nullptr;
  int max_height = 0;
  int height = 0;

  int *ptr_max_height = &max_height;
  int *ptr_height = &height;

  for(int i=0; i<10; i++){
      add_value(head, i);
    if(0<i)
      add_value(head, -1*i);
    max_height = 0;
    terminal_search(head->right, 0, ptr_max_height);
    
    // cout << "h(right): " << max_height << ", ";
    max_height = 0;
    terminal_search(head->left, 0, ptr_max_height);
    // cout << "h(left): " << max_height << endl;
    if(2 < i){
      std::exit(1);
    }
  }
  
  print_all(head);
  // terminal_search(head, height, ptr_max_height);
  // std::cout << max_height << endl;
  remove_terminal(head);
  print_all(head);
  return 0;
}
  

