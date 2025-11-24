#include<iostream>
using namespace std;
class Node{
  public : 
  int data;
  Node* next;
  Node(int data){
    this->data = data;
    this->next = NULL;
  }
};
  void insertAtHead(Node * &head, int d){
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;

  }
  void insertAtTail(Node * tail, int d){
    Node * temp = new Node(d);
    tail->next = temp;
    temp = tail;
  }
  void insertAtMidPosition(Node * &head , int position , int d){
    Node * temp = head ;
    int cnt =1;
    while(cnt<position -1){
          temp = temp->next;
          cnt ++;
    }
    Node * toinsert = new Node(d);
     toinsert->next = temp->next;
    temp->next = toinsert;
  }
  void print (Node * head){
    Node * temp = head;
    while(temp!=NULL){
      cout<<temp->data<< " ";
      temp = temp->next;
    }
    cout<<endl;
  } 
  int main(){
    Node* node1 = new Node(1);
    Node* head = node1; 
    Node * tail = node1;
    insertAtHead(head, 10);
    print(head);
    insertAtTail(tail,20);
    print(head);
    insertAtMidPosition(head,2, 80);
    print(head);
  }