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

    void deletion(int position) {
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

    while(curr != NULL) {
       
      if(curr->data == data) {
        break;
      }
      curr = curr->next;
      nodeNumber++;
    }

    if(curr == NULL) {
      cout << "Item is Not found in the list" << endl;
      return;
    }
    else{
      cout << "Item is found at index: " << nodeNumber << " in the list" <<endl;
    }

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
    linkedList ll;

    ll.insertAtHead(1);
    ll.addNode(2);
    ll.addNode(3);
    ll.addNode(4);
    ll.addNode(5);
    ll.addNode(6);

    cout << "Initial List: ";
    ll.printLinkedList();

    ll.insertNode(2, 1); 
    cout << "After inserting 2 at position 1 : ";
    ll.printLinkedList();

    ll.deletion(3); 
    cout << "After deleting node at position 3: ";
    ll.printLinkedList();
    11.searchNode(4);

    return 0;
}
