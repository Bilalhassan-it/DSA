#include<iostream>
#include<stack>
#include<string>
using namespace std;

int Precedence(char c) {
    if(c == '^') {
        return 3;
    }
    else if(c == '*' || c == '/') {
        return 2;
    }
    else if(c == '+' || c == '-') {
        return 1;
    }
    else {
        return -1;
    }
}

string infixToPostfix(string s) {
    stack<char> st;
    string result = "";

    for(int i = 0; i < s.length(); i++) {

        if((s[i] >= 'a' && s[i] <= 'z') ||
           (s[i] >= 'A' && s[i] <= 'Z') ||
           (s[i] >= '0' && s[i] <= '9')) {

            result += s[i];
        }

        else if(s[i] == '(') {
            st.push(s[i]);
        }

        else if(s[i] == ')') {

            while(!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }

            if(!st.empty()) {
                st.pop();
            }
        }

        else {

            while(!st.empty() &&
                  Precedence(st.top()) >= Precedence(s[i])) {

                result += st.top();
                st.pop();
            }

            st.push(s[i]);
        }
    }

    // Remaining operators
    while(!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

int main() {

    string infix;

    cout << "Enter Infix Expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);

    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}

//......................................................................................................
// #include<iostream>
// #include<stack>
// #include<string>
// using namespace std;

// int Precedence(char c){
//     if(c == '^'){
//         return 3;
//     }
//     else if(c =='*' &&  c=='/'){
//         return 2;
//     }
//     else if(c =='+' && c == '-'){
//         return 1;
//     }
//     else{
//     //(c == '(' && c == ')')
//         return -1;
//     }
// }

// string infixToPostfix(string s){
//     stack<char> st;
//     string result;

//     for(int i = 0; i < s.length(); i++){

//         if(s[i] >= 'a' && s[i] <= 'z'|| s[i] >= 'A' && s[i] <= 'Z' || s[i] >= '0' && s[i] <= '9'){
//             result += s[i];
//         }
//         else if(s[i] == '('){
//             st.push(s[i]);
//         }
//         else if(s[i] == ')'){

//             while(!st.empty() && st.top() != '('){
//                 result += st.top();
//                 st.pop();
//             }
//             // if(!st.empty()){
//             //     st.pop();
//             // }
//         }
//     }
//     else{
//         while(!st.empty() && Precedence(s[i]) <= Precedence(st.top())){
//             result += st.top();
//             st.pop();
//         }
//         st.push(s[i]);
    
//     }
//     return result;

// }

// int main(){
//     string infix;
//     cout << "Enter Infix Expression: ";
//     cin >> infix;
//     string postfix = infixToPostfix(infix);
//     cout << "Postfix Expression: " << postfix << endl;

// }

