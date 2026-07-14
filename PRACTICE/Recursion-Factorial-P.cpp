#include <iostream>
using namespace std;

void countdown(int n) {
    if(n == 0) {           // BASE CASE — ruk jao
        cout << "Go!" << endl;
        return;
    }
    cout << n << endl;     // pehle print karo
    countdown(n - 1);      // phir chhhote number pe call karo
}

int main() {
    countdown(3);
    return 0;
}

//...........................................................................

// #include<iostream>
// using namespace std;

// void RecursionFactorial(int n){
//     if( n == 0 || n == 1){

//         return 1;

//         return n * RecursionFactorial(n -1);
//     }

// }
//  int main(){
//     int n  = 130;
//     cout << n << endl;
//     cout << n << endl;
//     return 0;
//  }
//..................................................................................................

// #include <iostream>
// using namespace std;

// int factorial(int n) {
//     if(n == 0 || n == 1)   // BASE CASE
//         return 1;

//     return n * factorial(n - 1);  // RECURSIVE CASE
// }

// int main() {
//     cout << factorial(5) << endl;  // 120
//     cout << factorial(0) << endl;  // 1
//     return 0;
// }