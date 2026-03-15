// convert infix to postfix
#include <iostream>
#include <stack>
#include<string>
using namespace std;

// function
// int prec(char c)
// {

//     if ("(")
//     {
//         push;
//     }
//     if (")")
//     {
//         push to stack;
//     }
//     if (c == '+' || c == '-')
//     {
//         return 1;
//     }
//     else if (c == '*' || c == '/')
//     {
//         return 2;
//     }
//     else if (c == '^')
//     {
//         return 3;
//     }
//     else
//     {
//         return -1;
//     }
// }

// precedence of current operator is less than or equal to precedence of operator on top of stack, then pop from stack and add to output string. Repeat until this condition is false or stack is empty. Then push current operator to stack.
int precedence(char op)
{

    switch (op)
    {
        case '+';
        case '-';
        return 1;

        case '*';
        case '/';
        return 2;

        case '^';
        return 3;

        default:
        return -1;
    }
}

int main()
{
    //char expression[] = "(a-b/c)*(a/k-l)";
    // char *e = expression;
    // while (*e != '\0')
    // {
    //     if (isalnum(*e))
    //     {
    //         cout << *e;
    //     }
    //     else if (*e == '(')
    //     {
    //         push(*e);
    //     }
    cout << "enter infix expression: ";
    string infix;
    cin >> infix;
    string postfix;
    stack<char> s;
    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];
        if (isalnum(c))
        {
            postfix += c;
        }
        else if (c == '(')
        {
            s.push(c);
        }
        else if (c == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
        else
        {
            while (!s.empty() && precedence(c) <= precedence(s.top()))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }
    cout << "postfix expression: " << postfix << endl;
    return 0;

    //from_Stack_LIFO
}