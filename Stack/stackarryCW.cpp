#include<iostream>
using namespace std;

class Stack{
    int capacity;
    int *arry;
    int top;
  public:
    Stack(int c){
        this->capacity = c;
        arry = new int[c];
        this->top = -1;
    }
    bool isEmpty(){
        return top == -1;
    }
    bool isFull(){
        return top == capacity - 1;
    }
    bool push(int data){
        if(isFull()){
            cout << "Stack is Overflowing" << endl;
            return false;
        } else {
            arry[++top] = data;
            return true;
        }
    }
    bool pop(){
        if(isEmpty()){
            cout << "Stack is Underflowing" << endl;
            return false;
        } else {
            top--;
            return true;
        }
    }
    int topElement(){
        if (!isEmpty()) {
            return arry[top];
        }
        cout << "Stack is empty" << endl;
        return -1; // Return a default value when stack is empty
    }
    void show(){
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--) {
                cout << arry[i] << " ";
            }
            cout << endl;
        }
    }
    
};

int main() {
    Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.show();
    cout << "Top element: " << s.topElement() << endl;
    s.pop();
    s.show();
    cout << "Top element: " << s.topElement() << endl;
    return 0;
}

