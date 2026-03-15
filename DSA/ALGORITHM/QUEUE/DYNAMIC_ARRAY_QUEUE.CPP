#include <iostream>
using namespace std;


struct Node {
    int data;    
    Node* next;  
};

Node* front = NULL;
Node* rear = NULL;

// 2. Enqueue 
void enqueue(int value) {
    Node* newBox = new Node();   
    newBox->data = value;      
    newBox->next = NULL;       

    if (front == NULL) {         
        front = rear = newBox; 
    } else {
        rear->next = newBox;   
        rear = newBox;         
    }
    cout << "--- " << value << " VALUE ENTERED! ---\n";
}

// 3. Dequeue 
void dequeue() {
    if (front == NULL) {
        cout << "\n!!! EMPTY !!!\n";
        return;
    }
    Node* temp = front;           
    cout << "\n>>> " << temp->data << " EXIT! <<<\n";
    front = front->next;          
    delete temp;                  
}

int main() {
    int choice, val;

    while (true) {
        cout << "\n1. Enqueue (Add Number)";
        cout << "\n2. Dequeue (Remove Number)";
        cout << "\n3. Exit";
        cout << "\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Number likhein: ";
                cin >> val;
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                cout << "EXIT!\n";
                return 0;
            defau5lt:
                cout << "WRONG choice!\n";
        }
    }
    system("pause");
    return 0;
}
