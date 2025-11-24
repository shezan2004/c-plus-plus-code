#include<iostream>
using namespace std;

class MyStack {
    private:
    int Stack[100], top, MaxSize;

public: 
    MyStack(int size = 100) {
        MaxSize = size;
        top = 0;
    }
    
    bool isEmpty() {
        return top == 0;
    }
    
    bool isFull() {
        return top == MaxSize - 1;
    }
    
    bool push(int element) {
        if (isFull()) {
            cout << "Stack is full" << endl;
            return false;
        } else {
            Stack[top++] = element;
            return true;
        }
    }
    
    bool pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return false;
        } else {
            top--;
            return true;
        }
    }
    
    int TopElement() {
        /*if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return ;
        } else {*/
            return Stack[top-1];
        //}
    }
    
    void Show() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Stack elements: ";
            for (int i = top-1; i >=0; i--) {
                cout << Stack[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    MyStack stack;
    
    stack.push(10);
    stack.push(20);
    stack.push(30);
    
    stack.Show();
    
    cout << "Top element: " << stack.TopElement() << endl;
    
    stack.pop();
    stack.Show();
    
    cout << "Top element after pop: " << stack.TopElement() << endl;
    
    return 0;
}

 