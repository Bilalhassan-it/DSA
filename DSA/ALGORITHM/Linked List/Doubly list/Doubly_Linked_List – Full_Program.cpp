 //Doubly Linked List – Full Program
#include <iostream>
#include <cstdlib>
#include <limits>   // input buffer clear karne ke liye
using namespace std;

typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} node;

node *head = NULL;

// -------- Safe Input Function --------
int getInput() {
    int x;
    cin >> x;

    while (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input! Enter number again: ";
        cin >> x;
    }
    return x;
}

// -------- Insert at Beginning --------
void insertBeg(int value) {
    node *newnode = (node*) malloc(sizeof(node));
    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = head;

    if (head != NULL)
        head->prev = newnode;

    head = newnode;
}

// -------- Insert at End --------
void insertEnd(int value) {
    node *newnode = (node*) malloc(sizeof(node));
    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL) {
        newnode->prev = NULL;
        head = newnode;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    newnode->prev = temp;
}

// -------- Display --------
void display() {
    if (head == NULL) {
    
        cout << "List is empty\n";
        return;
    }

    node *temp = head;
    cout << "List: ";
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// -------- Search --------
void search(int key) {
    node *temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Value found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Value not found\n";
}

// -------- Delete --------
void del(int key) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    node *temp = head;

    if (temp->data == key) {
        head = temp->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
        cout << "Deleted\n";
        return;
    }

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        cout << "Value not found\n";
        return;
    }

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    free(temp);
    cout << "Deleted\n";
}

// -------- Main --------
int main() {
    int choice, value;

    while (true) {
        cout << "\n1. Insert at Beginning";
        cout << "\n2. Insert at End";
        cout << "\n3. Display";
        cout << "\n4. Search";
        cout << "\n5. Delete";
        cout << "\n6. Exit\n";
        cout << "Enter choice: ";

        choice = getInput();   // SAFE INPUT

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                value = getInput();
                insertBeg(value);
                break;

            case 2:
                cout << "Enter value: ";
                value = getInput();
                insertEnd(value);
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Enter value to search: ";
                value = getInput();
                search(value);
                break;

            case 5:
                cout << "Enter value to delete: ";
                value = getInput();
                del(value);
                break;

            case 6:
                system("pause");
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }
}
