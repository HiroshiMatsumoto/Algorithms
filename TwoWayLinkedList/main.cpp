#include <iostream>

using namespace std;

typedef struct node{
  node* next;
  node* prev;
  int value;
} Node, *NodePtr;

NodePtr create_list(void);
void add_value(NodePtr &head, int value);
void add_head(NodePtr &head, int value);
void add_tail(NodePtr &head, int value);
void add_after(NodePtr &head, int target, int value);
void view_list(NodePtr &head);
void remove_last_node(NodePtr &head);
void remove_all(NodePtr &head);


int main(){
  NodePtr head = NULL;
  for(int i=0; i< 10; i++){
    // add_value(head, i);
    add_tail(head, i);
    add_after(head, i, i+10);
    view_list(head);
  }
  // remove_all(head);
  // view_list(head);
  // std::cout << head->value << endl;
  return 0;
}

void remove_all(NodePtr &head){
  while(head!=NULL){
    remove_last_node(head);
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

void add_head(NodePtr &head, int value){
  NodePtr curr = head;
  NodePtr temp = new Node;

  temp->prev = NULL;
  temp->value = value;

  if(head==NULL){
    temp->next = NULL;
    head = temp;
  }
  else{
    temp->next = curr;
    curr->prev = temp;
    while(curr->next != NULL){
      curr = curr->next;
    }
    head = temp;
  }  
}

void add_tail(NodePtr &head, int value){
  NodePtr curr = head;
  NodePtr temp = new Node;

  temp->next = NULL;
  temp->prev = NULL;
  temp->value = value;

  if(head==NULL){
    head = temp;
  }
  else{
    while(curr->next != NULL){
      curr = curr->next;
    }
    curr->next = temp;
    temp->prev = curr;
  }  
}

void add_after(NodePtr &head, int target, int value){
  NodePtr curr = head;
  NodePtr temp = new Node;
  temp->value = value;
  while(curr->value != target)
    curr = curr->next;

  if(curr->next==NULL){
    add_tail(head, value);
  }else{
    temp->next = curr->next;
    temp->next->prev = temp;
    temp->prev = curr;
    curr->next = temp;
  }
}

NodePtr create_list(void){
  NodePtr head = new Node;
  head->next = NULL;
  return head;
}

