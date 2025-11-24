#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Queue {
    Node* head;
    Node* tail;
    int size;  
public:
    Queue() {
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }

    void enqueue(int data) {
        Node* newNode = new Node(data);
        if (this->head == NULL) {
            this->head = this->tail = newNode;
        } else {
            this->tail->next = newNode;
            this->tail = newNode;
        }
        this->size++;
    }

    void dequeue() {
        if (this->head == NULL) {
            return;
        } else {
            Node* oldHead = this->head;
            Node* newHead = this->head->next;
            this->head = newHead;
            if (this->head == NULL) this->tail = NULL;
            delete oldHead;
        }
        this->size--;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return this->head == NULL;
    }

    int front() {
        if (this->head == NULL) {
            return -1;
        }
        return this->head->data;
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.dequeue();
    q.enqueue(4);
    while (!q.isEmpty()) {
        cout << q.front() << " ";
        q.dequeue();
    }
    return 0;
}
