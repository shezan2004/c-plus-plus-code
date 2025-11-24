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
 Node *searchNode(Node *root,int value){
        if(root!=NULL){
            if(value==root->data){
                cout<<value<<" is found"<<endl;
                return root;
            }
            if(value<root->data){
                searchNode(root->left,value);
            }
            else if(value>root->data){
                searchNode(root->right,value);
            }
        }else{
            cout<<value<<" is not Found"<<endl;
        }
   }
void inorderTraversal(node* root) {
    if (root == NULL) return;
    
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}
//void inorderTraversal(node* root) {
//     if (root == NULL) return;
//     cout << root->data << " "; //pre
//     inorderTraversal(root->left);
//     inorderTraversal(root->right);
// }
// void inorderTraversal(node* root) {
//     if (root == NULL) return;
    
//     inorderTraversal(root->left);
//     inorderTraversal(root->right);
//     cout << root->data << " ";//post
// }


int main() {
    node* root = NULL;

    root = insertIntoBST(root, 10);
    root = insertIntoBST(root, 20);
    root = insertIntoBST(root, 30);
    root = insertIntoBST(root, 40);
    root = insertIntoBST(root, 50);
    root = insertIntoBST(root,60);
    root = insertIntoBST(root, 70);
    root = insertIntoBST(root, 80);
    root = insertIntoBST(root, 90);
    root = insertIntoBST(root, 100);
    
    cout << "Inorder traversal before deletion: ";
    inorderTraversal(root);
    cout << endl;

    root = deleteNode(root, 40);
    cout << "Inorder traversal after deleting node 4: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
