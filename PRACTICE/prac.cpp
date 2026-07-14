#include<iostream>
using namespace std;
// int i = '*';
// for(int i = 0; i <= 6 ; i++){
//     return i;
// }
// int main() {
//     cout << "*"     << endl;
//     cout << "**"    << endl;
//     cout << "***"   << endl;
//     cout << "****"  << endl;
//     cout << "*****" << endl;
//     cout << "******"<< endl;
    
//     return 0;
// }


int[] arr = {5, 3, 1, 4, 2};

void boolean sorted = false{
while (!sorted) {
    sorted = true;
    for (int i = 0; i < arr.length - 1; i++) {
        if (arr[i] > arr[i+1]) {          // ascending ke liye >
            // swap
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
            sorted = false;
        }
    }
}
}

// int main() {
//     cout << "******"     << endl;
//     cout << "*****" << endl;
//     cout << "****"  << endl;
//     cout << "***"   << endl;
//     cout << "**"    << endl;
//     cout << "*"<< endl;
    
//     return 0;
// }

//JAVA
// public class Pattern {
//     public static void main(String[] args) {
        
//         System.out.println("*");
//         System.out.println("**");
//         System.out.println("***");
//         System.out.println("****");
//         System.out.println("*****");
//         System.out.println("******");
        
//     }
// }