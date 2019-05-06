#define USE_DEBUG 1
#define MY_LOG( log ) printf( "File:%s Line:%d Func:%s Log:%s\n", __FILE__, __LINE__, __func__, log )
  
#include "BinaryTree.h"

using namespace std;

void add_value(NodePtr &head, int value){
  NodePtr curr;
  NodePtr prev;
  NodePtr prev_prev;
  NodePtr new_node;
  NodePtr terminal_node;

  NodePtr track_path = nullptr;

  int max_height = 0;
  int curr_height = 0;
  int *ptr_max_height = &max_height;
  int *ptr_height = &curr_height;

  int subleft_height = 0;
  int subright_height = 0;

  bool flag = false;
  
  new_node = new Node;
  new_node->value = value;
  new_node->left = nullptr;
  new_node->right = nullptr;

  #if USE_DEBUG
  std::cout << new_node << ": " << new_node->value << endl;
  #endif
  
  if(head == nullptr){
    head = new_node;
  }else{
    curr = head;
    max_height = 0;
    
    // descend tree to find target terminal node
    while(curr != nullptr){
      prev = curr;
      if(curr->value < value)
	curr = curr->right;
      else // value < curr->value
	curr = curr->left;
    }

    // self-explainatory variable name
    terminal_node = prev;
    if(terminal_node->value < value)
      terminal_node->right = new_node;    
    else
      terminal_node->left = new_node;

    curr = head;
    prev = nullptr;
    // descend tree to find target terminal node
    while(curr != nullptr){
      prev_prev = prev;
      prev = curr;
      
      if(curr->value < value){
	max_height = 0;
	subleft_height = 0;
	height(curr->left, curr_height+1, ptr_max_height);
	subleft_height = *ptr_max_height;
    
	max_height = 0;
	subright_height = 0;
	height(curr->right, curr_height+1, ptr_max_height);
	subright_height = *ptr_max_height;

	print_all(head);
	std::cout << curr->value << ": " << subleft_height << ", " << subright_height << " diff: " << abs(subleft_height - subright_height) << endl;
	
	if(curr->right != nullptr && abs(subleft_height - subright_height) == 2){
	  if(curr->right->value < value){
	    std::cout << "srr" << endl;
	    curr = single_rotate_right(curr);
	    if(prev_prev->right == prev)
	      prev_prev->right = curr;
	    else if(prev_prev->left == prev)
	      prev_prev->left = curr;
	    flag = true;
	  }else{
	    std::cout << "drr" << endl;
	    curr = double_rotate_right(curr);
	    if(prev_prev->right == prev)
	      prev_prev->right = curr;
	    else if(prev_prev->left == prev)
	      prev_prev->left = curr;
	  }
	}
	print_all(head);
	curr = curr->right;
      }
      else{ // value < curr->value
	max_height = 0;
	subleft_height = 0;
	height(curr->left, curr_height+1, ptr_max_height);
	subleft_height = *ptr_max_height;
    
	max_height = 0;
	subright_height = 0;
	height(curr->right, curr_height+1, ptr_max_height);
	subright_height = *ptr_max_height;

	print_all(head);
	std::cout << curr->value << ": " << subleft_height << ", " << subright_height << " diff: " << abs(subleft_height - subright_height) << endl;

	if(curr->left != nullptr && abs(subleft_height - subright_height) == 2){
	  if(curr->left->value > value){
	    curr = single_rotate_left(curr);
	    if(prev_prev->right == prev)
	      prev_prev->right = curr;
	    else if(prev_prev->left == prev)
	      prev_prev->left = curr;
	  }else{
	    std::cout << "drl" << endl;
	    curr = double_rotate_left(curr);
	    if(prev_prev->right == prev)
	      prev_prev->right = curr;
	    else if(prev_prev->left == prev)
	      prev_prev->left = curr;
	  }
	}
	
	print_all(head);
	curr = curr->left;
      }
    }


    /*
      // #if USE_DEBUG
      // std::cout << "[add to right][begin]" << endl;
      // #endif
      
      // max_height = 0;
      // subleft_height = 0;
      // height(prev->left, curr_height, ptr_max_height);
      // subleft_height = *ptr_max_height;
      
      // max_height = 0;
      // subright_height = 0;
      // height(prev->right, curr_height, ptr_max_height);
      // subright_height = *ptr_max_height;

      // std::cout << "[add right]" << subleft_height << " : " << subright_height << endl;
      
      // if(subright_height - subleft_height == 2){
      // 	#if USE_DEBUG
      // 	std::cout << "h(right) - h(left) == 2" << endl;
      //   #endif	
      // 	if(prev->right->value < value){
      // 	  #if USE_DEBUG
      // 	  std::cout << "single_rotate_left" << endl;
      // 	  #endif
      // 	  prev = single_rotate_left(prev);
      // 	}else{
      // 	  #if USE_DEBUG
      // 	  std::cout << "double_rotate_left" << endl;
      // 	  #endif
      // 	  prev = double_rotate_left(prev);
      // 	}
      // }

      
      max_height = 0;
      subleft_height = 0;
      height(prev->left, curr_height, ptr_max_height);
      subleft_height = *ptr_max_height;
      
      max_height = 0;
      subright_height = 0;
      height(prev->right, curr_height, ptr_max_height);
      subright_height = *ptr_max_height;

      std::cout << "[add to left]" << subleft_height << " : " << subright_height << endl;
      
      if(subleft_height - subright_height  == 2){
	if(value < prev->right->value){
	  prev = single_rotate_right(prev);
	}else{
	  prev = double_rotate_right(prev);
	}
      }
      */
  }
}



void remove_terminal(NodePtr &root){
  NodePtr curr;
  curr = root;
  // descending tree from root
  if(curr!=nullptr){
    if(curr->left!=nullptr){
      remove_terminal(curr->left);
    }
    if(curr->right!=nullptr){
      remove_terminal(curr->right);
    }
    if(curr->right==nullptr && curr->left==nullptr){
      delete curr;
      root = nullptr;
    }
  }
}


void print_all(NodePtr &head){
  NodePtr curr;
  NodePtr prev;

  curr = head;
  if(head == nullptr){
    std::cout << "head --> nullptr " << endl;
  }else{
    // find terminal node
    if(curr->left != nullptr){
      std::cout << curr->value << "->left: " << curr->left->value << endl;
      print_all(curr->left);
    }
    if(curr->right != nullptr){
      std::cout << curr->value << "-->right: " << curr->right->value << endl;
      print_all(curr->right);
    }
  }
}

/*
 *
 */
void height(NodePtr &root, int curr_height, int* ptr_max_height){
  NodePtr curr;
  curr = root;
  if(curr!=nullptr){
    if(curr->left!=nullptr){      
      height(curr->left, curr_height+1, ptr_max_height);
    }
    if(curr->right!=nullptr){
      height(curr->right, curr_height+1, ptr_max_height);
    }
    if(curr->right==nullptr && curr->left==nullptr){
      if(*ptr_max_height < curr_height){
	*ptr_max_height = curr_height;
      }
    }
  }
}


void terminal_search(NodePtr &root, int curr_height, int* ptr_max_height){
  NodePtr curr;
  curr = root;
  if(curr!=nullptr){
    if(curr->left!=nullptr){      
      terminal_search(curr->left, curr_height+1, ptr_max_height);
    }
    if(curr->right!=nullptr){
      terminal_search(curr->right, curr_height+1, ptr_max_height);
    }
    if(curr->right==nullptr && curr->left==nullptr){
      if(*ptr_max_height < curr_height){
	*ptr_max_height = curr_height;	
      }
    }
  }
}


NodePtr single_rotate_left(NodePtr head){
  NodePtr temp = head->left;
  head->left = temp->right;
  temp->right = head;
  return temp;
}


NodePtr single_rotate_right(NodePtr head){
  NodePtr temp = head->right;
  head->right = temp->left;
  temp->left = head;
  return temp;
}

NodePtr double_rotate_left(NodePtr head){
  head->left = single_rotate_right(head->left);
  return single_rotate_left(head);
}

NodePtr double_rotate_right(NodePtr head){
  head->right = single_rotate_left(head->right);
  return single_rotate_right(head);
}


int abs(int x){
  if(x < 0)
    x *= -1;
  return x;  
}
