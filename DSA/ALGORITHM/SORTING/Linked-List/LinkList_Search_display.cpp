#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;   
    }
};

//Linked List class
class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

//Insert
    void insert(int value) {
        Node* newNode = malloc(sizeof ( Node value));

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

//Search
    void search(int key) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == key) {
                cout << "Value found\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Value not found\n";
    }

//Delete
    void deleteValue(int key) {
        if (head == NULL) {
            cout << "List empty\n";
            return;
        }

        if (head->data == key) {
            Node* del = head;
            head = head->next;
            delete del;
            cout << "Deleted\n";
            return;
        }

        Node* temp = head;
        while (temp->next != NULL && temp->next->data != key) {
            temp = temp->next;
        }

        if (temp->next == NULL) {
            cout << "Value not found\n";
        } else {
            Node* del = temp->next;
            temp->next = del->next;
            delete del;
            cout << "Deleted\n";
        }
    }

//Display
    void display() {
        if (head == NULL) {
            cout << "List empty\n";
            return;
        }

        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    
    void clear() {
        while (head != NULL) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;
    int choice, value;

    do {
        cout << "\n1 Insert\n2 Search\n3 Delete\n4 Display\n5 Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.insert(value);
            break;

        case 2:
            cout << "Search value: ";
            cin >> value;
            list.search(value);
            break;

        case 3:
            cout << "Delete value: ";
            cin >> value;
            list.deleteValue(value);
            break;

        case 4:
            list.display();
            break;

        case 5:
            list.clear();
            cout << "Exited safely\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 5);
    system("pause");
    return 0;
}
