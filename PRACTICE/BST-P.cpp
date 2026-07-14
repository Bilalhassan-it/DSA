
#include<iostream>
using namespace std;
#include<vector>

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node* insert(Node* root, int value){
    if(root == nullptr){
        return new Node(value);
    }
    if(value < root -> data){
        root -> left = insert(root -> left , value);

    }
  else if(value > root -> data ){
    root -> right = insert(root -> right , value);

  }
  return root;
}

Node* BuildBST(vector <int> arr){
    Node* root = nullptr;

    for(int value : arr){
        root = insert(root, value);
    }
    return root;
}

bool search(Node* root, int value){
    if( root == nullptr){
        return false;
    }
    else if(root -> data  == value){
        return true;
    }
    else if(value > root -> data){
        return search(root -> right , value);
    }
   else{
    return search(root -> left , value);
   }
 }

void inorder(Node* root){
 if(root == nullptr){
    return;
 }
  inorder(root -> left);
  cout << root -> data << "  ";
  inorder(root -> right);
}

Node* getInorderSuccessor(Node* root){
   while(root != nullptr && root->left != nullptr){
    root = root->left;
   }
   return root;
}
//delete a node from BST
Node* deleteNode(Node* root , int value){
    if(root == nullptr){
        return nullptr;
    }
   if(value < root -> data){
    root -> left = deleteNode(root -> left , value);
   }
   else if(value > root -> data){
    root -> right =  deleteNode(root -> right , value);
   }
   //one child or no child
   else{
    if(root -> left == nullptr){
        Node* temp = root -> left;
        delete root;
        return temp;
    }
    else if(root ->right == nullptr){
        Node* temp =  root -> right ;
        delete root;
        return temp;
    }
    //2 chldren
    else{
        Node* temp = getInorderSuccessor(root -> right);
        root -> data = temp -> data;
        root -> right = deleteNode(root -> right , temp -> data);
        return root;


    }
   }

}
int  main(){

    vector <int> arr = {5, 3, 7, 2, 4, 6, 8};
    Node* root = BuildBST(arr);

    cout << "Inorder Traversal:before deletion: ";
         inorder(root);
         cout << endl;

    cout << "Inorder Traversal:after deletion: ";
         deleteNode(root, 5);
         inorder(root);  
            cout << endl; 

    // cout << search(root ,5) << endl; //1
    // cout << search(root , 10) << endl; //0
    return 0;
}