#include<bits/stdc++.h>
using namespace std;

class Dqueue {
    int* arry;
    int front;
    int rear;
    int size;

public:
    // Constructor
    Dqueue(int n) {
        size = n;
        arry = new int[size];
        front = rear = -1;
    }

    // Push element to the front
    bool pushFront(int value) {
        if (isFull()) {
            return false;
        }
        else if (front == -1) {
            front = rear = 0;
        }
        else if (front == 0 && rear != size - 1) {
            front = size - 1;
        }
        else {
            front--;
        }
        arry[front] = value;
        return true;
    }

    // Push element to the rear
    bool pushRear(int value) {
        if (isFull()) {
            return false;
        }
        else if (front == -1) {
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0) {
            rear = 0;
        }
        else {
            rear++;
        }
        arry[rear] = value;
        return true;
    }

    // Pop element from the front
    int popFront() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        int ans = arry[front];
        arry[front] = -1;
        if (front == rear) {
            front = rear = -1;
        }
        else if (front == size - 1) {
            front = 0;
        }
        else {
            front++;
        }
        return ans;
    }

    // Pop element from the rear
    int popRear() {
        if (isEmpty()) {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        int ans = arry[rear];
        arry[rear] = -1;
        if (front == rear) {
            front = rear = -1;
        }
        else if (rear == 0) {
            rear = size - 1;
        }
        else {
            rear--;
        }
        return ans;
    }

    // Get the front element
    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return arry[front];
    }

    // Check if the deque is empty
    bool isEmpty() {
        return front == -1;
    }

    // Check if the deque is full
    bool isFull() {
        return (front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1));
    }
};

int main() {
    Dqueue dq(5); // Example usage

    dq.pushRear(10);
    dq.pushRear(20);
    dq.pushFront(5);
    cout << "Front element: " << dq.getFront() << endl;
    cout << "Removed element from front: " << dq.popFront() << endl;

    return 0;
}
