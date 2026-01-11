// Bubble Sort
#include <iostream>
using namespace std;

int main() {
    int arr[6] = {5, 6, 4, 2, 3, 1};
    int n = 6;

    // Print original array
    cout << "Original Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i]<< " " ;
    }

    // Bubble Sort Algorithm
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Print sorted array
    cout << "\nSorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    system("pause");
    return 0;
}
