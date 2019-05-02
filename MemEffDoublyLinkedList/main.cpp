#include <iostream>
#include <cstdint>

using namespace std;

typedef struct node{
  // The diff pointer field holds the difference between the pointer to the next node and the pointer to the previous node.
  // Pointer difference is captured by using exclusive OR. 
  node* link;
  // std::ptrdiff_t diff;
  int value;
} Node, *NodePtr;

// NodePtr create_list(void);
// void add_value(NodePtr &head, int value);

NodePtr get_next_node(NodePtr prev, NodePtr curr);
NodePtr XOR(NodePtr x, NodePtr y);
void add_head(NodePtr &head, int value);
void add_tail(NodePtr &head, int value);
// void add_after(NodePtr &head, int target, int value);

// void remove_head(NodePtr &head);
// void remove_tail(NodePtr &head);
// void remove_after(NodePtr &head, int target);


void view_list(NodePtr &head);
  // void remove_last_node(NodePtr &head);
// void remove_all(NodePtr &head);


int main(){
  NodePtr head = nullptr;
  for(int i=0; i< 5; i++){
    add_head(head, i);
    view_list(head);
  }
  // for(int i=10; i< 20; i++){
  //   add_tail(head, i);
  //   view_list(head);
  // }
  view_list(head);
  return 0;
}

NodePtr XOR(NodePtr x, NodePtr y){
  return ((NodePtr)((uintptr_t)(x) ^ (uintptr_t)(y)));
}



void view_list(NodePtr &head){
  NodePtr curr, next, prev;
  curr = head;
  prev = nullptr;
  next = XOR(prev, curr->link);  
  while(curr != nullptr){
    std::cout << curr->value;
    next = XOR(prev, curr->link);
    prev = curr;
    curr = next;
    if(next != nullptr)
      std::cout << ", ";
  }
  std::cout << endl;
}

void add_head(NodePtr &head, int value){
  NodePtr temp = new Node;
  temp->value = value;

  temp->link = XOR(head, nullptr);

  if(head){
    head->link = XOR(temp, XOR(head->link, nullptr));
  }

  head = temp;
}
  

void add_tail(NodePtr &head, int value){
  NodePtr prev, curr, next;
  NodePtr temp = new Node;
  temp->value = value;
  curr = head;
  while(curr != nullptr){
    next = XOR(curr->link, prev);
    if(next){
      next->link = XOR(next->link, XOR(curr, temp));
      curr->link = XOR(temp, XOR(next, curr->link));
      temp->link = XOR(curr, next);
      break;
    }
    std::cout << curr->value << endl;
    prev = curr;
    curr = next;
  }
  // std::cout << value << endl;
  // temp->value = value;

  // // temp->diff = XOR(last_node_ptr, nullptr);
  // curr = head;
  // prev = nullptr;
  // next = XOR(prev, curr->link);
  // std::cout << head << "-->" << next;
  
  // while(next != nullptr){
  //   next = XOR(prev, curr->link);
  //   std::cout << "-->" << next;
  //   prev = curr;
  //   curr = next;
  // }
  // next = temp;
  // next->link = XOR(prev, nullptr); 
  // std::cout << endl;
  // // std::cout << "Val:" << next->value << endl;
  // // std::cout << "Addr:" << next << endl;
  // // std::cout << "Link:" << next->link << endl;
}

// void remove_all(NodePtr &head){
//   while(head!=NULL){
//     remove_last_node(head);
//   }
// }

// void view_list(NodePtr &head){
//   int count = 0;
//   NodePtr curr = head;
//   if(head==NULL){
//     std::cout << "NONE" << endl;
//     return;
//   }
//   while(curr != NULL){
//     // std::cout << curr->value << ", ";    
//     std::cout << curr->value;
//     // std::cout << "(" << count << ")";
//     if(curr->next != NULL){
//       std::cout << ", ";
//       count++;
//     }
//     curr = curr->next;
//   }
//   cout << endl;
// }


// void remove_last_node(NodePtr &head){
//   NodePtr curr = head;
//   NodePtr prev = head;
//   if(head->next == NULL){
//     delete head->next;
//     head = NULL;
//   }
//   else{
//     while(curr->next != NULL){
//       prev = curr;
//       curr = curr->next;
//     }
//     prev->next = NULL;
//     delete curr;
//   }
// }

// void add_head(NodePtr &head, int value){
//   NodePtr curr = head;
//   NodePtr temp = new Node;

//   temp->prev = NULL;
//   temp->value = value;

//   if(head==NULL){
//     temp->next = NULL;
//     head = temp;
//   }
//   else{
//     temp->next = curr;
//     curr->prev = temp;
//     while(curr->next != NULL){
//       curr = curr->next;
//     }
//     head = temp;
//   }  
// }

// void add_tail(NodePtr &head, int value){
//   NodePtr curr = head;
//   NodePtr temp = new Node;

//   temp->next = NULL;
//   temp->prev = NULL;
//   temp->value = value;

//   if(head==NULL){
//     head = temp;
//   }
//   else{
//     while(curr->next != NULL){
//       curr = curr->next;
//     }
//     curr->next = temp;
//     temp->prev = curr;
//   }  
// }

// void add_after(NodePtr &head, int target, int value){
//   NodePtr curr = head;
//   NodePtr temp = new Node;
//   temp->value = value;
  
//   while(curr->value != target)
//     curr = curr->next;

//   if(curr->next==NULL){
//     add_tail(head, value);
//   }else{
//     temp->next = curr->next;
//     temp->next->prev = temp;
//     temp->prev = curr;
//     curr->next = temp;
//   }
// }

// void remove_head(NodePtr &head){
//   NodePtr temp = head;

//   head = head->next;
//   head->prev = NULL;

//   delete temp;
// }


// void remove_tail(NodePtr &head){
//   NodePtr curr;
//   NodePtr temp;
  
//   if(head->next == NULL){ // signleton
//     delete head->next;
//     head = NULL;
//   }else{
//     curr = head;
//     while(curr->next->next!=NULL)
//       curr = curr->next;

//     temp = curr->next;
//     curr->next = NULL;
    
//     delete temp;
//   }
// }


// void remove_after(NodePtr &head, int target){
//   NodePtr curr;
//   NodePtr temp;

//   curr = head;
//   if(curr->next != NULL && curr->next->next != NULL){ // need two nodes at least
//     while(curr->value != target)
//       curr = curr->next;
//     temp = curr;
    
//     curr = curr->prev;
//     curr->next = temp->next;
//     curr->next->prev = curr;
    
//     delete temp;
//   }
// }


// NodePtr create_list(void){
//   NodePtr head = new Node;
//   head->next = NULL;
//   return head;
// }

