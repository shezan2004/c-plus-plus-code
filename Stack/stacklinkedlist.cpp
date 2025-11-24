#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

class Stack {
    Node* head;
    int capacity;
    int currSize;
public:
    Stack(int c) {
        this->capacity = c;
        this->currSize = 0;
        head = NULL;
    }

    bool isEmpty() {
        return this->head == NULL;
    }

    bool isFull() {
        return this->currSize == this->capacity;
    }

    bool push(int data) {
        if (this->currSize == this->capacity) {
            cout << "Overflowing" << endl;
            return false;
        }
        Node* newNode = new Node(data);
        newNode->next = this->head;
        this->head = newNode;
        this->currSize++;
        return true;
    }

    bool pop() {
        if (this->head == NULL) {
            cout << "Under Flow" << endl;
            return false;
        }
        Node* tobeRemoved = this->head;
        this->head = this->head->next;
        delete tobeRemoved;
        this->currSize--;
        return true;
    }
bool getTop() {
    if (isEmpty()) {
        cout << "Underflow" << endl;
        return false;
    } else{
         return this->head->data;   
      }
    }

    int size() {
        return this->currSize;
    }
};

int main() {
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    
    cout << "Top element: " << st.getTop() << endl;
    cout << "Size: " << st.size() << endl;
    st.push(6);
    cout << "Top element: " << st.getTop() << endl;
    st.pop();
    cout << "Top element: " << st.getTop() << endl;
    cout << "Size: " << st.size() << endl;
    return 0;
}
