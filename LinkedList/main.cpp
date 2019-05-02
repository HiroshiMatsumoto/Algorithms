#include <iostream>

using namespace std;

typedef struct node{
  node* next;
  int value;
} Node, *NodePtr;

NodePtr create_list(void){
  NodePtr head = new Node;
  head->next = NULL;
  return head;
}

void add_value(NodePtr &head, int value){
  NodePtr curr = head;
  NodePtr temp = new Node;

  temp->next = NULL;
  temp->value = value;

  if(head==NULL){
    head = temp;
  }
  else{
    while(curr->next != NULL){
      curr = curr->next;
    }
    curr->next = temp;
  }
}

void view_list(NodePtr &head){
  int count = 0;
  NodePtr curr = head;
  if(head==NULL){
    std::cout << "NONE" << endl;
    return;
  }
  while(curr != NULL){
    // std::cout << curr->value << ", ";    
    std::cout << curr->value;
    // std::cout << "(" << count << ")";
    if(curr->next != NULL){
      std::cout << ", ";
      count++;
    }
    curr = curr->next;
  }
  cout << endl;
}


void remove_last_node(NodePtr &head){
  NodePtr curr = head;
  NodePtr prev = head;
  if(head->next == NULL){
    delete head->next;
    head = NULL;
  }
  else{
    while(curr->next != NULL){
      prev = curr;
      curr = curr->next;
    }
    prev->next = NULL;
    delete curr;
  }
}


void remove_all(NodePtr &head){
  while(head!=NULL){
    remove_last_node(head);
  }
}


int main(){
  NodePtr head = NULL;
  for(int i=0; i< 10; i++){
    add_value(head, i);
    view_list(head);
  }
  remove_all(head);
  view_list(head);
  // std::cout << head->value << endl;
  return 0;
}
