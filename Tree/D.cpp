#include<iostream>
using namespace std;


class node {
 public:
    int val;
    node* left;
    node* right;

    node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    } 
};

node* insertNode(node* root , int data) {
    if(root == NULL) {
        root = new node(data);
      return root;  
    }

    if(root->val < data) {
        root->right = insertNode(root->right , data);
    }
    else {
        root->left = insertNode(root->left , data);
    }
  return root;  
}

node* searchNode(node* root , int data) {
    if(root == NULL) return NULL;
    if(root->val == data) return root;

    if(data > root->val) {
        return searchNode(root->right , data);
    }
    else {
        return searchNode(root->left , data);
    }
}

void inorderTraversal(node* root) {
    if(root == NULL) {
      return;
    }

    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

//--------------------------Main Here-------------------------------
int main() {
    
   node* root = nullptr;

   int arr[] = {1,2,3,4,5,6,7,8,9,10,11};

   for(int i = 0; i < 11; i++) {
      root = insertNode(root , arr[i]);
   }
   
   inorderTraversal(root);
   
   cout << endl; 

   node* find = searchNode(root , 10);

   if(find != NULL) {
    cout << "node 10 present" << endl;
   }
   else {
    cout << "Node 10 not present" << endl;
   }







    return 0;
}
