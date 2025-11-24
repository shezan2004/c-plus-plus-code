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

node* findMin(node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

node* deleteNode(node* root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

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

        node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// node* buildBST() {
//     node* root = NULL;
//     int data;
    
//     cout << "Enter data (-1 to stop): " << endl;
//     cin >> data;

//     while (data != -1) {
//         root = insertIntoBST(root, data);
//         cout << "Enter data (-1 to stop): " << endl;
//         cin >> data;
//     }

//     return root;
// }

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
    cout << "Enter the value to delete: ";
    cin >> key;
    
    root = deleteNode(root, key);
    
    cout << "Inorder traversal after deletion: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
