#include<iostream>
#include<math.h>
using namespace std;

class Stack {
    int *arr;
    int top;
    int capacity;

public:
    Stack(int size = 100) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    void push(int x) {
        if (top == capacity - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return;
        }
        top--;
    }

    int getTop() {
        if (top == -1) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int cal(int v1, int v2, char op) {
    if (op == '^') {
        return pow(v2, v1);
    }
    if (op == '/') {
        return v2 / v1;
    }
    if (op == '*') {
        return v2 * v1;
    }
    if (op == '+') {
        return v2 + v1;
    }
    return v2 - v1;
}

int evaluate(string &str) {
    Stack st;
    for (int i = 0; i < str.size(); i++) {
        char ch = str[i];
        if (isdigit(ch)) {
            st.push(ch - '0');
        } 
        else {
            int v1 = st.getTop();
            st.pop();
            int v2 = st.getTop();
            st.pop();
            st.push(cal(v1, v2, ch));
        }
    }
    return st.getTop();
}

int main() {
    
    string str = "26*41-/53*+";
    cout<< "Result : "<< evaluate(str)<<endl;
    return 0;
}
