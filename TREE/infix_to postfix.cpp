// Convert Infix to Postfix
#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check precedence
int precedence(char op)
{
    switch(op)
    {
        case '+':
        case '-':
            return 1;

        case '*':
        case '/':
            return 2;

        case '^':
            return 3;

        default:
            return -1;
    }
}

int main()
{
    string infix, postfix = "";
    stack<char> s;

    cout << "Enter infix expression: ";
    cin >> infix;

    for(int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];

        // If operand
        if(isalnum(c))
        {
            postfix += c;
        }

        // If opening bracket
        else if(c == '(')
        {
            s.push(c);
        }

        // If closing bracket
        else if(c == ')')
        {
            while(!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }

            if(!s.empty())
            {
                s.pop(); // remove '('
            }
        }

        // If operator
        else
        {
            while(!s.empty() && precedence(c) <= precedence(s.top()))
            {
                postfix += s.top();
                s.pop();
            }

            s.push(c);
        }
    }

    // Pop remaining operators
    while(!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}