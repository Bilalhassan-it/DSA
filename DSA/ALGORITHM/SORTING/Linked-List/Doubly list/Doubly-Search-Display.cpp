#include <iostream>
#include <cstdlib>
using namespace std;

// -------- Node Structure --------
typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
} node;

node *head = NULL;

// -------- Insert at End --------
void insert(int value) {
    node *newnode = (node*) malloc(sizeof(node));
    newnode->data = value;
    newnode->next = NULL;
    newnode->prev = NULL;

    if (head == NULL) {
        head = newnode;
        return;
    }

    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->prev = temp;
}

// -------- Display List --------
void display() {
    node *temp = head;

    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    cout << "List: ";
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// -------- Search Function --------
void search(int key) {
    node *temp = head;
    int position = 1;

    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Value found at position " << position << endl;
            return;
        }
        temp = temp->next;
        position++;
    }

    cout << "Value not found in list\n";
}

// -------- Main Function --------
int main() {
    int choice, value;

    while (true) {
        cout << "\n1. Insert";
        cout << "\n2. Display";
        cout << "\n3. Search";
        cout << "\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insert(value);
                system("pause");
                break;

            case 2:
                display();
                system("pause");
                break;

            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                search(value);
                system("pause");
                break;

            case 4:
                system("pause");
                return 0;

            default:
                cout << "Invalid choice\n";
                system("pause");
        }
    }
}
