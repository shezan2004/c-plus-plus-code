#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *next;
    Node *prev;

    Node(int data) {
        value = data;
        next = NULL;
        prev = NULL;
    }
};

struct DoublyLinkedList {
    Node *head;
    DoublyLinkedList() {
        head = NULL;
    }

    // Insert at the beginning
    void insertAthead(int value) {
        Node *newNode = new Node(value);
        if (head != NULL) {
            newNode->next = head;
            head->prev = newNode;
        }
        head = newNode;
    }

    // Append at the end
    void append(int value) {
        Node *newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            return;
        }

        Node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }

        current->next = newNode;
        newNode->prev = current;
    }

    // Insert at a specific position (0-based indexing)
    void insertAtPosition(int value, int position) {
        if (position < 0) {
            cout << "Invalid position" << endl;
            return;
        }

        Node *newNode = new Node(value);
        if (position == 0) {
            newNode->next = head;
            if (head != NULL) {
                head->prev = newNode;
            }
            head = newNode;
            return;
        }

        Node *current = head;
        int currentPosition = 0;

        while (current != NULL && currentPosition < position - 1) {
            currentPosition++;
            current = current->next;
        }

        if (current == NULL) {
            cout << "Position out of bounds!" << endl;
            return;
        }

        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != NULL) {
            current->next->prev = newNode;
        }
        current->next = newNode;
    }

    // Delete node at a specific position (0-based indexing)
    void deleteAtPosition(int position) {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        if (position < 0) {
            cout << "Invalid position" << endl;
            return;
        }

        Node *current = head;
        if (position == 0) {
            head = head->next;
            if (head != NULL) {
                head->prev = NULL;
            }
            delete current;
            return;
        }

        int currentPosition = 0;
        while (current != NULL && currentPosition < position - 1) {
            current = current->next;
            currentPosition++;
        }

        if (current == NULL || current->next == NULL) {
            cout << "Position out of bounds" << endl;
            return;
        }

        Node *temp = current->next;
        current->next = current->next->next;
        if (current->next != NULL) {
            current->next->prev = current;
        }
        delete temp;
    }

    // Print the entire linked list
    void printList() {
        if (head == NULL) return;

        Node *current = head;
        while (current != NULL) {
            cout << current->value << " <-> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyLinkedList dll;

    dll.insertAthead(1);
    dll.append(2);
    dll.append(3);
    dll.append(4);
    dll.append(5);
    dll.append(6);

    dll.printList();

    dll.deleteAtPosition(4);
    dll.printList();

    return 0;
}