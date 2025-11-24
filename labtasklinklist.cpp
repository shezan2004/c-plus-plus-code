#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
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
        head = newNode;
        if (tail == NULL) {
            tail = newNode;
        }
    }

    void addNode(int data) {
        if (head == NULL) {
            insertAtHead(data);
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        Node* newNode = new Node(data);
        temp->next = newNode;
        tail = newNode;
    }

    void insertNode(int data, int position) {
        if (position < 1) {
            cout << "Position cannot be less than 1" << endl;
            return;
        }
        Node* newNode = new Node(data);
        if (position == 1) {
            newNode->next = head;
            head = newNode;
            if (tail == NULL) {
                tail = newNode;
            }
            return;
        }
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
            delete temp;
            if (head == NULL) {
                tail = NULL;
            }
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
        delete nodeToDelete;
        if (temp->next == NULL) {
            tail = temp;
        }
    }

    void searchNode(int data) {
        if (head == NULL) {
            cout << "Empty!!" << endl;
            return;
        }

        Node* curr = head;
        int nodeNumber = 0;

        while (curr != NULL) {
            if (curr->data == data) {
                cout << "Item is found at Position : " << nodeNumber +1  << " in the list" << endl;
                return;
            }
            curr = curr->next;
            nodeNumber++;
        }

        cout << "Item is Not found in the list" << endl;
    }

    void printLinkedList() {
        if (head == NULL) {
            return;
        }
        Node* temp = head;
        while (temp) {
            cout << temp->data << "  ";
            temp = temp->next;
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
    cout << "After inserting 2 at position 1 : ";
   link.printLinkedList();

   link.deleteNode(3); 
    cout << "After deleting node at position 3: ";
   link.printLinkedList();

   link.searchNode(8);

    return 0;
}
