// STACK LIFO
#include <iostream>
using namespace std;

#define array_size 5

int stack[array_size];
int top = 0;

// PUSH FUNCTION
void push(int value) {
    if (top == array_size) {
        cout << "Stack Overflow\n";
        return;
    }

    stack[top] = value;
    top++;
}

// POP FUNCTION
void pop() {
    if (top == 0) {
        cout << "Stack Underflow\n";
        return;
    }

    top--;
    cout << "Popped value: " << stack[top] << endl;
}

// DISPLAY FUNCTION
void display() {
    if (top == 0) {
        cout << "Stack is empty\n";
        return;
    }

    cout << "Stack elements:\n";
    for (int i = top - 1; i >= 0; i--) {
        cout << stack[i] << endl;
    }
}

// MAIN FUNCTION
int main() {
    int choice, value;

    while (true) {
        cout << "\n1. Push";
        cout << "\n2. Pop";
        cout << "\n3. Display";
        cout << "\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                 system("pause");
           
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }
}
