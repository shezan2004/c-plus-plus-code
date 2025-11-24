#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BinarySearchTree {
private:
    Node* root;

    void inOrderTraversal(Node* node) {
        if (node == NULL) {
            return;
        }

        inOrderTraversal(node->left);       
        cout << node->data << " ";         
        inOrderTraversal(node->right);      
    }

    void deleteTree(Node* node) {
        if (node == NULL) {
            return;
        }

        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

public:
    BinarySearchTree() : root(NULL) {}

    ~BinarySearchTree() {
        deleteTree(root);
    }

    void insert(int value) {
        Node* newNode = new Node(value);

        if (root == NULL) {
            root = newNode;
            return;
        }

        Node* current = root;
        Node* parent = NULL;

        while (current != NULL) {
            parent = current;

            if (value < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        if (value < parent->data) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
        }
    }

    void inOrder() {
        inOrderTraversal(root);
        cout << endl;
    }
};

int main() {
    BinarySearchTree tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    cout << "In-order traversal of the binary search tree:" << endl;
    tree.inOrder();

    return 0;
}
