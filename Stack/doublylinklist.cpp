#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

struct linkedList {
    Node* head;
    Node* tail;
    linkedList() {
        head = NULL;
        tail = NULL;
    }

    void insertAtHead(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        if (tail == NULL) {
            tail = newNode;
        }
    }

    void insertAtTail(int data) {
        if (head == NULL) {
            insertAtHead(data);
            return;
        }
        Node* newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void addNode(int data) {
        insertAtTail(data);
    }

    void insertNode(int data, int position) {
        if (position < 1) {
            cout << "Position cannot be less than 1" << endl;
            return;
        }
        if (position == 1) {
            insertAtHead(data);
            return;
        }
        Node* newNode = new Node(data);
        Node* temp = head;
        int count = 1;
        while (temp != NULL && count < position - 1) {
            temp = temp->next;
            count++;
        }
        if (temp == NULL) {
            cout << "Position Out of Range" << endl;
            return;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        if (newNode->next == NULL) {
            tail = newNode;
        }
    }

    void deleteNode(int position) {
        if (head == NULL) {
            cout << "Empty!!" << endl;
            return;
        }
        if (position < 1) {
            cout << "Invalid Position" << endl;
            return;
        }
        if (position == 1) {
            Node* temp = head;
            head = head->next;
            if (head != NULL) {
                head->prev = NULL;
            } else {
                tail = NULL;
            }
            delete temp;
            return;
        }
        Node* temp = head;
        int count = 1;
        while (temp != NULL && count < position - 1) {
            temp = temp->next;
            count++;
        }
        if (temp == NULL || temp->next == NULL) {
            cout << "Position Out of Range" << endl;
            return;
        }
        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        if (nodeToDelete->next != NULL) {
            nodeToDelete->next->prev = temp;
        } else {
            tail = temp;
        }
        delete nodeToDelete;
    }

    // void searchNode(int data) {
    //     if (head == NULL) {
    //         cout << "Empty!!" << endl;
    //         return;
    //     }
    //     Node* curr = head;
    //     int nodeNumber = 1;
    //     while (curr != NULL) {
    //         if (curr->data == data) {
    //             cout << data << " is found at Position: " << nodeNumber << " in the list" << endl;
    //             return;
    //         }
    //         curr = curr->next;
    //         nodeNumber++;
    //     }
    //     cout << data << " is Not found in the list" << endl;
    // }

    void printLinkedList() {
        if (head == NULL) {
            return;
        }
        
        // Print from head to tail
        Node* temp = head;
        cout << "List from head to tail: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
        
        // Print from tail to head
        temp = tail;
        cout << "List from tail to head: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    linkedList link;

    link.insertAtHead(4);
    link.addNode(5);
    link.addNode(6);
    link.addNode(7);
    link.addNode(8);
    link.addNode(9);

    cout << "Initial List: ";
    link.printLinkedList();

    link.insertNode(2, 1);
    cout << "After inserting 2 at position 1: ";
    link.printLinkedList();

    link.deleteNode(3);
    cout << "After deleting node at position 3: ";
    link.printLinkedList();

    // link.searchNode(9);
    return 0;
}