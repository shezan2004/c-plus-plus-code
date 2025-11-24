#include<bits/stdc++.h>
using namespace std;

class Queue {
    int* arr;
    int frontIndex;
    int rear;
    int size;

public:
    Queue() {
        size = 1000;
        arr = new int[size];
        frontIndex = 0;
        rear = 0;
    }

    void enqueue(int data) {
        if (rear == size) {
            cout << "Queue is Full" << endl;
        } else {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        if (frontIndex == rear) {
            return -1;
        } else {
            int ans = arr[frontIndex];
            arr[frontIndex] = -1;
            frontIndex++;
            if (frontIndex == rear) {
                frontIndex = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int front() {
        if (frontIndex == rear) {
            return -1;
        } else {
            return arr[frontIndex];
        }
    }

    bool isEmpty() {
        return frontIndex == rear;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.front() << endl;

    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;

    cout << "Front element after dequeue: " << q.front() << endl;

    if (q.isEmpty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue is not empty" << endl;
    }

    q.enqueue(40);
    cout << "Front element after enqueue: " << q.front() << endl;

    return 0;
}
