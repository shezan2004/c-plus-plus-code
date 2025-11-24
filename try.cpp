#include<bits/stdc++.h>
using namespace std;
class Queue{
    int* arry;
    int front;
    int rear;
    int size;
    public:
    Queue(int n){
        size =n;
        arry = new int[n];
        front = rear =-1;
    }
    bool enqueue(int value){
        if((front == 0 && rear == size -1) || (rear == (front -1) % (size-1))){
            cout<< " Queue is Full"<<endl;
            return false;
        }
        else if(front == -1){
            front = rear = 0;
        }
        else if( rear == size-1 && front != 0){
            rear = 0;
        }
        else{
            rear++;
        }
        arry[rear]=value;
        return true;
    }
    int dequeue(){
        if(front== -1){
            cout<< " Queue is Empty"<<endl;
            return -1;
        }
        int ans = arry[front];
        arry[front]= -1;
        if(front==rear){
            front = rear = -1;
        }
        else{
            front++;
        }
        return ans;
    }
};
int main(){
    Queue q(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.enqueue(9);
    cout << "Dequeued element: " << q.dequeue() << endl;
    q.enqueue(10);
    cout << "Dequeued element: " << q.dequeue() << endl;
    return 0;
}
