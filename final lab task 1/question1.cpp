#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int value) {
        key = value;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree {
private:
    Node* root;
    void deleteDeepest(Node* delNode) {
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            if (temp == delNode) {
                delNode = NULL;
                return;
            }

            if (temp->right) {
                if (temp->right == delNode) {
                    temp->right = NULL;
                    return;
                } else {
                    q.push(temp->right);
                }
            }

            if (temp->left) {
                if (temp->left == delNode) {
                    temp->left = NULL;
                    return;
                } else {
                    q.push(temp->left);
                }
            }
        }
    }

public:
    BinaryTree() {
        root = NULL;
    }

    
    void insert(int key) {
        if (root == NULL) {
            root = new Node(key);
        } else {
            _insert(root, key);
        }
    }

   
    void _insert(Node* current, int key) {
        queue<Node*> q;
        q.push(current);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            if (temp->left == NULL) {
                temp->left = new Node(key);
                break;
            } else {
                q.push(temp->left);
            }

            if (temp->right == NULL) {
                temp->right = new Node(key);
                break;
            } else {
                q.push(temp->right);
            }
        }
    }

    
    void deleteNode(int key) {
        if (root == NULL) {
            cout << "Tree is empty." << endl;
            return;
        }

        if (root->key == key && !root->left && !root->right) {
            delete root;
            root = NULL;
            return;
        }

        Node* keyNode = NULL;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            if (temp->key == key) {
                keyNode = temp;
            }

            if (temp->left) {
                q.push(temp->left);
            }

            if (temp->right) {
                q.push(temp->right);
            }
        }

        if (keyNode) {
           
            Node* deepestNode = q.back();
            deleteDeepest(deepestNode);
            keyNode->key = deepestNode->key;
        } else {
            cout << "Node with key " << key << " not found." << endl;
        }
    }


    void inOrder(Node* node) {
        if (node) {
            inOrder(node->left);
            cout << node->key << " ";
            inOrder(node->right);
        }
    }

    Node* getRoot() {
        return root;
    }
};

int main() {
    BinaryTree tree;
    int choice, key;

    while (true) {
        cout << "\nOptions:" << endl;
        cout << "1. Insert a node" << endl;
        cout << "2. Display In-Order Traversal" << endl;
        cout << "3. Delete a node" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> key;
                tree.insert(key);
                break;

            case 2:
                cout << "In-Order Traversal: ";
                tree.inOrder(tree.getRoot());
                cout << endl;
                break;

            case 3:
                cout << "Enter the value to delete: ";
                cin >> key;
                tree.deleteNode(key);
                break;

            case 4:
                cout << "Exiting..." << endl;
                return 0;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
}
