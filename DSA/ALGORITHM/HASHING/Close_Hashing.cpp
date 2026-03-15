//CLOSE HASHING
#include <iostream>
using namespace std;

int main() {
    //Sirf ek simple array (No Nodes, No Pointers)
    int HT[10];

    //linear probing ke liye -1 se initialize karna (ya koi bhi aisi value jo valid input nahi ho)
    //Table ko khali karna 
    for (int i = 0; i < 10; i++) {
        HT[i] = -1;
    }

    int choice, value;

    while (true) {
        cout << "\n1. Insert | 2. Display | 3. Search | 4. Exit: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter number: ";
            cin >> value;
            int ind = value % 10;
            int startInd = ind; // Yaad rakhne ke liye ke kahan se shuru kiya

            // Agli khali jagah dhundo (Linear Probing)
            while (HT[ind] != -1) {
                ind = (ind + 1) % 10;
                
                // Agar poori table ghum kar wapas wahin aa gaye
                if (ind == startInd) {
                    cout << "Table Full hai!\n";
                    break;
                }
            }

            if (HT[ind] == -1) {
                HT[ind] = value;
                cout << "Inserted at index " << ind << endl;
            }
        } 
        else if (choice == 2) {
            cout << "\n--- Hash Table ---\n";
            for (int i = 0; i < 10; i++) {
                cout << "Index " << i << ": " << HT[i] << endl;
            }
        } 
        else if (choice == 3) {
            cout << "Enter number to search: ";
            cin >> value;
            int ind = value % 10;
            int startInd = ind;
            bool found = false;

            while (HT[ind] != -1) {
                if (HT[ind] == value) {
                    cout << "Value " << value << " found at index " << ind << endl;
                    found = true;
                    break;
                }
                ind = (ind + 1) % 10;
                if (ind == startInd) break;
            }

            if (!found) cout << "Value nahi mili!\n";
        } 
        else if (choice == 4) {
            break;
        }
    }

    return 0;
}