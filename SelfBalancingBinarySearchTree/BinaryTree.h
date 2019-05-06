#include <iostream>

typedef struct node{
  node* left;
  node* right;
  int value;
} Node, *NodePtr;


void add_value(NodePtr &head, int value);
void remove_terminal(NodePtr &root);
void print_all(NodePtr &head);
/* int height(NodePtr &root); */
void terminal_search(NodePtr &root, int ptr_curr_height, int* ptr_max_height);
void height(NodePtr &root, int ptr_curr_height, int* ptr_max_height);
NodePtr single_rotate_left(NodePtr head);
NodePtr single_rotate_right(NodePtr head);
NodePtr double_rotate_left(NodePtr head);
NodePtr double_rotate_right(NodePtr head);
int abs(int x);
