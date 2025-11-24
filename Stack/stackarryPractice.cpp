#include<iostream>
using namespace std;
   class Stack{
        int size;
        int* arry;
        int top;
    public:
        Stack(int s){
            this->size = s;
            arry = new int[s];
            this->top = -1;
        }
        bool isEmpty(){
            return top == -1;
        }
        bool isFull(){
            return top == size -1;
        }
        bool push(int data){
            if(isFull()){
                cout<< "Stack is full"<<endl;
                return false;
            }
            else{
                arry[++top]= data;
                return true;
            }
        }
        bool pop(){
            if(isEmpty()){
                cout<<" Stack is empty";
                return false;
            }
            else{
                top--;
                return true;
            }
        }
        int topElement(){
           if(!isEmpty()) {
                return arry[top];
        }
           else{
            cout<< " Stack is Empty"<<endl;
            return -1;
           }
        }
        void show(){
            if(isEmpty()){
                cout<< " Stack is empty";
            }
            else{
                cout<< " Elements are : ";
                for(int i = top; i>=0; i--){
                    cout<<arry[i]<< " ";
                }
                cout<< endl;
            }
        }

   };

   int main(){
     Stack s(5);
     s.push(10);
     s.push(20);
     s.push(30);
     s.push(40);
     s.push(50);
     s.show();
     cout<< " Top Element : "<< s.topElement()<< endl;
     s.pop();
     s.show();
     cout<< " Top Element : "<< s.topElement()<< endl;
     s.push(50);
     s.push(60);
     s.show();
    return 0;
   }
