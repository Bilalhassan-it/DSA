   // OPEN HASHING
#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* HT[10]; 

void initialize() {
    for (int i = 0; i < 10; i++) {
        HT[i] = NULL;
    }
}

void insert(int value) {
    int ind = value % 10; 

    if (HT[ind] == NULL) {
        HT[ind] = new node;
        HT[ind]->data = value;
        HT[ind]->next = NULL;
    } else {
        node* temp = HT[ind];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        node* newNode = new node;
        newNode->data = value;
        newNode->next = NULL;
        temp->next = newNode;
    }
}

void display() {
    for (int i = 0; i < 10; i++) {
        node* temp = HT[i];
        cout << "Index " << i << ": ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
}

bool search(int value) {
    int ind = value % 10;
    node* temp = HT[ind];
    while (temp != NULL) {
        if (temp->data == value) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main() {
    initialize();

    insert(23);
    insert(13);
    insert(75);
    insert(123);
    insert(88);
    insert(98);

    display();

    int val = 123;
    if (search(val)) {
        cout << "Value " << val << " found in the hash table." << endl;
    } else {
        cout << "Value " << val << " not found." << endl;
    }

    return 0;
}