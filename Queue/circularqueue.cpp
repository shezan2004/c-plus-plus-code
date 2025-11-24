#include<bits/stdc++.h>
using namespace std;

class Queue {
    int* array;
    int size;
    int front;
    int rear;
public:
    Queue(int n) {
        this->size = n;
        array = new int[size];
        front = rear = -1;
    }
    bool enqueue(int value) {
        // Check if the queue is full
        if ((front == 0 && rear == size - 1) || (rear == (front - 1 ) %( size-1))) {
            cout << "Queue is full" << endl;
            return false;
        } 
        else if (front == -1) { // First element to enqueue
            front = rear = 0;
        } 
        else if (rear == size - 1 && front != 0) {
            rear = 0; // To maintain cyclic nature
        } 
        else {
            rear++;
        }
        array[rear] = value;
        return true;
    }

    int dequeue() {
        if (front == -1) {
            cout << "Queue is Empty" << endl; 
            return -1;
        }
        int ans = array[front];
        array[front] = -1;
        if (front == rear) { // Single element present
            front = rear = -1;
        } 
        else if (front == size - 1) { // To maintain cyclic nature
            front = 0;
        } 
        else {
            front++;
        }
        return ans;
    }
};

int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << "Dequeued element: " << q.dequeue() << endl;

    q.enqueue(60);

    cout << "Dequeued element: " << q.dequeue() << endl;

    return 0;
}
