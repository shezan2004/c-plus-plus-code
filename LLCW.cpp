#include<iostream>
using namespace std;

class Node
{
    public : 
    int val;
    Node* next;

    Node( int data){
        val = data;
        next = NULL;
    }
};
void insertAtHead(Node* &head , int val){
    Node * new_Node = new Node(val);
    new_Node->next = head;
    head = new_Node;
}
void insertAtTail(Node* head, int val){
    Node* new_Node = new Node(val);
    Node* temp = head;
    while(temp->next !=NULL){
         temp =temp->next;  

    }
    temp->next =new_Node;
}
void insertAtPosition( Node* head , int val, int pos){
    if(pos==0){
        insertAtHead(head, val);
        return ;
    }
    Node* new_Node = new Node(val);
    Node* temp =head;
    int current_pos =0;
    while(current_pos!=pos - 1){
        temp= temp->next;
        current_pos++;
    }
    new_Node->next = temp->next;
    temp->next = new_Node;
}
void updateValue(Node*head , int val , int k){
    Node* temp = head;
    int curr_pos  = 0;
    while(curr_pos!= k){
        temp = temp->next;
        curr_pos++;
    }
    temp->val =val;
}
void display(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->val<< " ";
        temp= temp->next;
    }
    cout<<endl;
} 
int main(){
  Node* head =NULL;
  insertAtHead (head , 4);
  display(head);
  insertAtHead(head , 5);
   display(head);
   insertAtTail(head, 7);
   display(head);
   insertAtTail(head, 8 );
   display(head);
   insertAtPosition(head, 6, 2);
   display(head);  
   updateValue(head, 3 , 1);
   display(head); 
}   