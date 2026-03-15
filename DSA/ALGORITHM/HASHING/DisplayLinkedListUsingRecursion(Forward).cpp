#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Insert at end
void insert(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

//Display Forward using Recursion
void displayForward(Node* head) {
    if (head == NULL)
        return;

    cout << head->data << " ";
    displayForward(head->next);
}

//Display Reverse using Recursion
void displayReverse(Node* head) {
    if (head == NULL)
        return;

    displayReverse(head->next);
    cout << head->data << " ";
}

int main() {
    Node* head = NULL;

    int n, value;

    cout << "Enter number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> value;
        insert(head, value);
    }

    cout << "\nForward Display (Recursion): ";
    displayForward(head);

    cout << "\nReverse Display (Recursion): ";
    displayReverse(head);

    return 0;
}
