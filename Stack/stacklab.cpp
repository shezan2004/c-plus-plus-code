#include<bits/stdc++.h>
using namespace std;
class MyStack{
    private:
    int Stack[5] , top, size;
    public:
    MyStack(int size){
        this->size = size;
        top = 0;
    }
    bool isEmpty(){
        if(top == 0){
            return true;
        }
        else{
            return false;
        }
    }
    bool isFull(){
        if(top == size){
            return true;
        }
        else{
            return false;
        }
    }
    bool push(int element){
        if(isFull()){
            cout<< "Stack is full"<<endl;
            return false;
        }
            Stack[top++]= element;
            return false;
    
    }
    bool pop(){
        if(isEmpty()){
            cout<< "Stack is empty"<<endl;
            return false;
        }
        top--;
        return true;
    }
    int  topElement(){
            return Stack[top - 1];
    }
    void show(){
        if(isEmpty()){
            cout<< "Staack is Empty"<<endl;
        }
     else{
        cout<< "Stack elements: ";
            for (int i = top - 1; i >= 0; i--) {
                cout << Stack[i] << " ";
            }
            cout<<endl;
        }
    }
     
    
};


int main(){
      MyStack m(5);
      m.pop();
      m.push(10);
      m.push(20);
      m.push(30);
      m.push(40);
      m.show();
      m.pop();
      m.show();
      cout<< "Top Element : "<<m.topElement()<<endl;
      m.push(50);
      m.push(60);
      m.show();
      m.push(70);



    

    return 0;
}