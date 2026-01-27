#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct node {
    int data;
    struct node *next;
} node;

node *head = NULL;

// -------- Insert --------
void insert(int value) {
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = value;

    // agar list empty ho
    if (head == NULL) {
        head = newnode;
        newnode->next = head;
        return;
    }

    node *temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->next = head;
}

// -------- Display --------
void display() {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    node *temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(HEAD)\n";
}

// -------- Search --------
void search(int key) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    node *temp = head;
    do {
        if (temp->data == key) {
            cout << "Value found\n";
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Value not found\n";
}

// -------- Delete --------
void del(int key) {
    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    node *temp = head;
    node *prev = NULL;

    // ?? case 1: sirf aik hi node ho
    if (head->data == key && head->next == head) {
        free(head);
        head = NULL;
        cout << "Deleted\n";
        return;
    }

    // ?? case 2: head delete karni ho
    if (head->data == key) {
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = head->next;
        free(head);
        head = temp->next;
        cout << "Deleted\n";
        return;
    }

    // ?? case 3: middle / last node
    temp = head;
    do {
        prev = temp;
        temp = temp->next;

        if (temp->data == key) {
            prev->next = temp->next;
            free(temp);
            cout << "Deleted\n";
            return;
        }
    } while (temp != head);

    cout << "Value not found\n";
}

// -------- Main --------
int main() {
    int choice, value;

    while (true) {
        cout << "\n1. Insert";
        cout << "\n2. Display";
        cout << "\n3. Search";
        cout << "\n4. Delete";
        cout << "\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insert(value);
                break;

            case 2:
                display();
                break;

            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                search(value);
                break;

            case 4:
                cout << "Enter value to delete: ";
                cin >> value;
                del(value);
                break;

            case 5:
                system("pause");
                return 0;

            default:
                cout << "Invalid choice\n";
                sytem("pause");
                
        }
    }
}
