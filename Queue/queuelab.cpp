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
            int removedElement = arr[frontIndex];
            frontIndex++;
            
            if (frontIndex == rear) {
                frontIndex = 0;
                rear = 0;
            }
            return removedElement;
        }
    }


    bool isEmpty() {
        return frontIndex == rear;
    }
    int front() {
        if (frontIndex == rear) {
            return -1;
        } else {
            return arr[frontIndex];
        }
    }
    void show() {
        if (frontIndex == rear) {
            cout << "Queue is Empty" << endl;
        } else {
            cout<< "Elements : ";
            for (int i = frontIndex; i < rear; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

};


int main(){
     Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.show();  
    cout<<"Front : "<<q.front()<<endl;
    cout << "Dequeued: " << q.dequeue() << endl;  
    q.show();  

    cout << "Dequeued: " << q.dequeue() << endl;  
    cout << "Dequeued: " << q.dequeue() << endl;  

    q.show(); 


    

    return 0;
}