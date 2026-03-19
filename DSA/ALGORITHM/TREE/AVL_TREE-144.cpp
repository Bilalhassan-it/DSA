//WHY WE USE AVL TREE?
//Because it keeps tree balanced and improves searching time.

// #include <iostream>
// using namespace std;

// struct Node {
//     int key;
//     Node *left, *right;
//     int height;
// };

// int height(Node *n) {
//     if (n == NULL) return 0;
//     return n->height;
// }

// Node* createNode(int key) {
//     Node* node = new Node();
//     node->key = key;
//     node->left = node->right = NULL;
//     node->height = 1;
//     return node;
// }

// int getBalance(Node *n) {
//     if (n == NULL) return 0;
//     return height(n->left) - height(n->right);
// }

// // Right Rotation
// Node* rightRotate(Node *y) {
//     Node *x = y->left;
//     Node *T2 = x->right;

//     x->right = y;
//     y->left = T2;

//     y->height = max(height(y->left), height(y->right)) + 1;
//     x->height = max(height(x->left), height(x->right)) + 1;

//     return x;
// }

// // Left Rotation
// Node* leftRotate(Node *x) {
//     Node *y = x->right;
//     Node *T2 = y->left;

//     y->left = x;
//     x->right = T2;

//     x->height = max(height(x->left), height(x->right)) + 1;
//     y->height = max(height(y->left), height(y->right)) + 1;

//     return y;
// }

// Node* insert(Node* node, int key) {
//     if (node == NULL)
//         return createNode(key);

//     if (key < node->key)
//         node->left = insert(node->left, key);
//     else if (key > node->key)
//         node->right = insert(node->right, key);
//     else
//         return node;

//     node->height = 1 + max(height(node->left), height(node->right));

//     int balance = getBalance(node);

//     // LL
//     if (balance > 1 && key < node->left->key)
//         return rightRotate(node);

//     // RR
//     if (balance < -1 && key > node->right->key)
//         return leftRotate(node);

//     // LR
//     if (balance > 1 && key > node->left->key) {
//         node->left = leftRotate(node->left);
//         return rightRotate(node);
//     }

//     // RL
//     if (balance < -1 && key < node->right->key) {
//         node->right = rightRotate(node->right);
//         return leftRotate(node);
//     }

//     return node;
// }

// void inorder(Node *root) {
//     if (root != NULL) {
//         inorder(root->left);
//         cout << root->key << " ";
//         inorder(root->right);
//     }
// }

// int main() {
//     Node *root = NULL;

//     int arr[] = {120,110,150,130,140,146,136,134,138,160,154,156,132,125,128};
//     int n = sizeof(arr)/sizeof(arr[0]);

//     for (int i = 0; i < n; i++)
//         root = insert(root, arr[i]);

//     cout << "Inorder Traversal:\n";
//     inorder(root);

//     return 0;
// }

#include <iostream>
using namespace std;

// AVL Node Structure (Exactly as per your image)
struct AVLNode {
    int data;
    AVLNode *leftChild;
    AVLNode *rightChild;
    int height;
};

// Safe way to get height of a node (to prevent NULL pointer crashes)
int getHeight(AVLNode* node) {
    if (node == NULL)
        return -1;
    return node->height;
}

// Helper to get max of two numbers
int getMax(int a, int b) {
    return (a > b) ? a : b;
}

// Right Rotation (Single Rotation)
AVLNode* rotateRight(AVLNode* node) {
    AVLNode* tmp = node->leftChild;
    node->leftChild = tmp->rightChild;
    tmp->rightChild = node;

    // Recalculating heights
    node->height = getMax(getHeight(node->leftChild), getHeight(node->rightChild)) + 1;
    tmp->height = getMax(getHeight(tmp->leftChild), getHeight(tmp->rightChild)) + 1;

    return tmp;
}

// Left Rotation (Single Rotation)
AVLNode* rotateLeft(AVLNode* node) {
    AVLNode* tmp = node->rightChild;
    node->rightChild = tmp->leftChild;
    tmp->leftChild = node;

    // Recalculating heights
    node->height = getMax(getHeight(node->leftChild), getHeight(node->rightChild)) + 1;
    tmp->height = getMax(getHeight(tmp->leftChild), getHeight(tmp->rightChild)) + 1;

    return tmp;
}

// Left-Right Rotation (Double Rotation)
AVLNode* rotateLeftRight(AVLNode* node) {
    node->leftChild = rotateLeft(node->leftChild);
    return rotateRight(node);
}

// Right-Left Rotation (Double Rotation)
AVLNode* rotateRightLeft(AVLNode* node) {
    node->rightChild = rotateRight(node->rightChild);
    return rotateLeft(node);
}

// Main Insertion function matching the logic in your image
AVLNode* insertAVL(AVLNode* node, int value) {
    // Base Case: Creating a new node
    if (node == NULL) {
        AVLNode* tmp = new AVLNode();
        tmp->data = value;
        tmp->leftChild = NULL;
        tmp->rightChild = NULL;
        tmp->height = 0; // As mentioned in image: tmp.height=0
        return tmp;
    }

    if (value < node->data) {
        node->leftChild = insertAVL(node->leftChild, value);
        
        // Balancing logic from image
        if ((getHeight(node->leftChild) - getHeight(node->rightChild)) == 2) {
            if (value < node->leftChild->data) {
                node = rotateRight(node);
            } else {
                node = rotateLeftRight(node);
            }
        }
    } 
    else if (value > node->data) {
        node->rightChild = insertAVL(node->rightChild, value);

        // Similar balancing logic for right side
        if ((getHeight(node->rightChild) - getHeight(node->leftChild)) == 2) {
            if (value > node->rightChild->data) {
                node = rotateLeft(node);
            } else {
                node = rotateRightLeft(node);
            }
        }
    }

    // Updating height of the current node
    node->height = getMax(getHeight(node->leftChild), getHeight(node->rightChild)) + 1;

    return node;
}

// Simple function to see the result
void inorder(AVLNode* root) {
    if (root != NULL) {
        inorder(root->leftChild);
        cout << root->data << " ";
        inorder(root->rightChild);
    }
}

int main() {
    AVLNode* root = NULL;

    // Numbers given in your second image
    int values[] = {120, 110, 150, 130, 140, 146, 136, 134, 138, 160, 154, 156, 132, 125, 128};
    int size = sizeof(values) / sizeof(values[0]);

    cout << "Inserting values into AVL tree...\n";
    for (int i = 0; i < size; i++) {
        root = insertAVL(root, values[i]);
    }

    cout << "\nInorder Traversal (Should be sorted):" << endl;
    inorder(root);
    cout << endl;

    return 0;
}


//....................................Super Short Revision..................................................
// AVL = BST + Balance

// Insert → Height update → Balance check → Rotation

// BF = left - right

// LL → Right rotate  
// RR → Left rotate  
// LR → Left + Right  
// RL → Right + Left