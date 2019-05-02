#include <iostream>

using namespace std;

typedef struct node{
  node* left;
  node* right;
  int value;
} Node, *NodePtr;


bool has_num(NodePtr &root, int num);
void add_num(NodePtr &root, int num);
void del_num(NodePtr &root, int num);
void dfs(NodePtr &root);
void delete_all(NodePtr &root);
  
int main(){
  NodePtr root = NULL;
  NodePtr target = NULL;

  add_num(root, 10);
  add_num(root, 1);
  add_num(root, 5);
  add_num(root, 110);
  add_num(root, 20);
  del_num(root, 20);
  dfs(root);
  std::cout << endl;
  delete_all(root);
  std::cout << endl;
  dfs(root);
  target = root;       
  delete target;
  std::cout << root->value << endl;
	       
  return 0;
}

void add_num(NodePtr &root, int num){
  NodePtr curr;
  NodePtr prev;
  curr = root;

  // Prep new node
  NodePtr newNode = new Node;
  newNode->left = NULL;
  newNode->right = NULL;
  newNode->value = num;
  
  // New tree
  if(root==NULL){
    root = newNode;
  }
  // adding to existing tree
  else{
    // search terminal node
    while( curr != NULL ){
      prev = curr;
      if(curr->value < num){
	curr = curr->right;
      }else{
	curr = curr->left;
      }      
    }
    // attaching new node to tree
    curr = prev;
    if(curr->value < num){
      curr->right = newNode;
    }else{
      curr->left = newNode;
    }
  }
}

bool has_num(NodePtr &root, int num){
  NodePtr curr;
  curr = root;
  while( curr->value!=num ){
    if(curr->left != NULL && num < curr->left->value){
      curr = curr->left;
    }
    else if(curr->right != NULL && curr->right->value < num){
      curr = curr->right;
    }
    else if(curr->right == NULL && curr->left == NULL){
      return false;
    }
  }
  return true;
}


void del_num(NodePtr &root, int num){
  NodePtr curr;
  NodePtr target;
  NodePtr terminal;
  NodePtr prev_terminal;
  
  curr = root;
  target = root;
  terminal = NULL;
  prev_terminal = NULL;
  
  // finding target node
  while(curr->value != num){
    if(curr->value < num){
      curr = curr->right;
    }
    else{
      curr = curr->left;
    }
  }  
  target = curr;
  
  // finding terminal node
  prev_terminal = curr; // init.
  while(curr->left != NULL || curr->right != NULL){
    prev_terminal = curr;
    if(curr->left){
      curr = curr->left;
    }
    else if(curr->right){
      curr = curr->right;
    }
  }
  terminal = curr;
  // removing terminal  
  target->value = terminal->value;
  if(prev_terminal->left != NULL && prev_terminal->left->value == terminal->value){
    prev_terminal->left = NULL;
    delete terminal;
  }else if(prev_terminal->right != NULL && prev_terminal->right->value == terminal->value){
    prev_terminal->right = NULL;    
    delete terminal;
  }  
}


void dfs(NodePtr &root){
  NodePtr curr;
  curr = root;
  if(curr->left != NULL){
    std::cout << curr->value << " --> left:" << curr->left->value << endl;
    dfs(curr->left);
  }
  if(curr->right != NULL){
    std::cout << curr->value << " --> right:" << curr->right->value << endl;
    dfs(curr->right);
  }  
}


void delete_all(NodePtr &root){
  NodePtr curr;
  NodePtr target;
  curr = root;
  std::cout << curr->value << endl;
  if(curr->left != NULL){
    delete_all(curr->left);
  }
  if(curr->right != NULL){
    delete_all(curr->right);
  }
  
  if(curr->left != NULL && curr->left->left == NULL && curr->left->right == NULL){      
    target = curr->left;
    curr->left = NULL;
    delete target;
  }
  if(curr->right != NULL && curr->right->left == NULL && curr->right->right == NULL){
    target = curr->right;
    curr->right = NULL;
    delete target;
  }  
}
    
