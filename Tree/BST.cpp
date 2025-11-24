#include<bits/stdc++.h>
using namespace std;

class node {
    public: 
    int data;
    node* left;
    node* right;

    node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// Insert into BST
node* insertIntoBST(node* root, int data) {
    if (root == NULL) {
        return new node(data);
    }
    
    if (data < root->data) {
        root->left = insertIntoBST(root->left, data);
    } else {
        root->right = insertIntoBST(root->right, data);
    }
    
    return root;
}

// Find the inorder successor (smallest value in the right subtree)
node* findMin(node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Delete a node from BST
node* deleteNode(node* root, int key) {
    if (root == NULL) {
        return NULL;
    }

    // Traverse the tree to find the node
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node found

        // Case 1: Node has no children
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // Case 2: Node has one child
        if (root->left == NULL) {
            node* temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == NULL) {
            node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Node has two children
        node* temp = findMin(root->right); // Find inorder successor
        root->data = temp->data; // Replace root's data with successor's data
        root->right = deleteNode(root->right, temp->data); // Delete the inorder successor
    }

    return root;
}

// Build the BST by inserting values
node* buildBST() {
    node* root = NULL;
    int data;
    
    cout << "Enter data (-1 to stop): " << endl;
    cin >> data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cout << "Enter data (-1 to stop): " << endl;
        cin >> data;
    }

    return root;
}

// Inorder traversal
void inorderTraversal(node* root) {
    if (root == NULL) return;
    
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    node* root = NULL;
    root = buildBST();

    cout << "Inorder traversal of BST: ";
    inorderTraversal(root);
    cout << endl;

    int key;
    cout << "Enter value to delete: ";
    cin >> key;

    root = deleteNode(root, key);

    cout << "Inorder traversal after deletion: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
