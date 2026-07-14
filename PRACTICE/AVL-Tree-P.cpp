#include <iostream>
using namespace std;

// Node Structure
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};

// Height Function
int height(Node *node)
{
    if(node == NULL)
        return 0;

    return node->height;
}

// Maximum Function
int max(int a, int b)
{
    if(a > b)
        return a;
    return b;
}

// Create New Node
Node* newNode(int value)
{
    Node* node = new Node;

    node->data = value;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;

    return node;
}

// Right Rotation (LL)
Node* rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Left Rotation (RR)
Node* leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Balance Factor
int getBalance(Node *node)
{
    if(node == NULL)
        return 0;

    return height(node->left) - height(node->right);
}

// Insert Function
Node* insert(Node *node, int value)
{
    if(node == NULL)
        return newNode(value);

    if(value < node->data)
        node->left = insert(node->left, value);

    else if(value > node->data)
        node->right = insert(node->right, value);

    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    // LL Rotation
    if(balance > 1 && value < node->left->data)
        return rightRotate(node);

    // RR Rotation
    if(balance < -1 && value > node->right->data)
        return leftRotate(node);

    // LR Rotation
    if(balance > 1 && value > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL Rotation
    if(balance < -1 && value < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Inorder Traversal
void inorder(Node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Main Function
int main()
{
    Node *root = NULL;

    root = insert(root,30);
    root = insert(root,20);
    root = insert(root,10);
    root = insert(root,40);
    root = insert(root,50);

    cout<<"Inorder Traversal: ";

    inorder(root);

    return 0;
}