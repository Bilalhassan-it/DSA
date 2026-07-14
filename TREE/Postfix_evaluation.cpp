Checks if a string of brackets is balanced.
 * Example: "{[()]}" is balanced. "{[(])}" is NOT.
#include <iostream>
#include <stack>
#include <map>
#include <string>
using namespace std;

bool isBalanced(string expr) {
    stack<char> s;
    // Map to link closing brackets to opening ones
    map<char, char> bracketMap = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    for (char c : expr) {
        // If it's an opening bracket, push to stack
        if (c == '(' || c == '[' || c == '{') {
            s.push(c);
        }
        // If it's a closing bracket
        else if (c == ')' || c == ']' || c == '}') {
            // If stack is empty or top doesn't match, it's unbalanced
            if (s.empty() || s.top() != bracketMap[c]) {
                return false;
            }
            s.pop(); // Found a match, remove from stack
        }
    }

    // If stack is empty, all brackets were matched correctly
    return s.empty();
};

int main() {
    string test1 = "{[()]}";
    string test2 = "{[(])}";
    string test3 = "((10 + 2) * 5)";

    cout << "Test 1 " << test1 << ": " << (isBalanced(test1) ? "Balanced" : "Not Balanced") << endl;
    cout << "Test 2 " << test2 << ": " << (isBalanced(test2) ? "Balanced" : "Not Balanced") << endl;
    cout << "Test 3 " << test3 << ": " << (isBalanced(test3) ? "Balanced" : "Not Balanced") << endl;

    return 0;
}