#include<iostream>
using namespace std;

struct Node {
    public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node* &head, int d) {
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d) {
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void insertNode(Node* &head, Node* &tail, int position, int d) {
    if (position == 1) {
        insertAtHead(head, d);
        return;
    }
    Node *temp = head;
    int count = 1;

    while (count < position - 1) {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL) {
        insertAtTail(tail, d);
        return;
    }
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(int position, Node* &head, Node* &tail) {
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;

        // Update tail if list is now empty
        if (head == NULL) {
            tail = NULL;
        }
    }
     else {
        Node *curr = head;
        Node *prev = NULL;
        int count = 1;
        while (count < position) {
            prev = curr;
            curr = curr->next;
            count++;
        }
        prev->next = curr->next;

        // Update tail if the last node is deleted
        if (curr->next == NULL) {
            tail = prev;
        }
        delete curr;
    }
}

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtHead(head, 12);
    print(head);

    insertAtTail(tail, 13);
    print(head);

    insertNode(head, tail, 1, 22);
    print(head);

    deleteNode(3, head, tail);
    print(head);


    return 0;
}
