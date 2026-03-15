#include <iostream>
using namespace std;

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
};

//Insert 
BSTNode* insert(BSTNode* root, int value) {

    if (root == NULL) {
        BSTNode* newNode = new BSTNode;
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
    
    }


    // search function
bool search(BSTNode* root , int value){
    if(root==nullptr){
        return false;
    }
    else if(root->data==value){
        return true;
    }
    else if(value<root->data){
        return search(root->left,value);
    }
    else{
        return search(root->right,value);
    }

}
//Preorder
void preorder(BSTNode* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

//Inorder
void inorder(BSTNode* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

//Postorder
void postorder(BSTNode* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main() {

    BSTNode* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "Preorder: ";
    preorder(root);

    cout << "\nInorder: ";
    inorder(root);

    cout << "\nPostorder: ";
    postorder(root);
    cout << endl;

    bool found = search(root, 100);
    cout << found;

    //BSTNode* newRoot = deleteNode(root, 30);
    //cout << "\nInorder after deletion: ";
    //inorder(newRoot);

    return 0;
}