#include <iostream>
#include <stack>
#include <string>

using namespace std;

// 1. Operator ki priority check karne ke liye simple function
int precedence(char c) {
    if (c == '^') 
        return 3;
    if (c == '*' || c == '/') 
        return 2;
    if (c == '+' || c == '-') 
        return 1;
    return -1; // Agar operator nahi hai (jaise brackets)
}

int main() {
    string infix, postfix = "";
    stack<char> s;

    cout << "Enter Infix Expression: ";
    cin >> infix;

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        // A. Agar operand hai (a-z, A-Z, 0-9) toh seedha output mein dalo
        if (isalnum(c)) {
            postfix += c;
        }
        // B. Agar '(' hai toh stack mein push karo
        else if (c == '(') {
            s.push('(');
        }
        // C. Agar ')' hai toh jab tak '(' na mile, stack se pop karke output mein dalo
        else if (c == ')') {
            while (s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // '(' ko stack se nikal do
        }
        // D. Agar Operator hai (+, -, *, /)
        else {
            while (!s.empty() && precedence(c) <= precedence(s.top())) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    // Aakhir mein stack mein jo bacha hai sab nikal lo
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}