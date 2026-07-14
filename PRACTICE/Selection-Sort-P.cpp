#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        int minIdx = i;               // assume karo current position minimum hai

        // baaki array mein se actual minimum dhoondhо
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[minIdx]) {
                minIdx = j;           // naya minimum mila!
            }
        }

        // minimum ko sahi jagah rakh do (swap)
        if(minIdx != i) {             // agar already sahi jagah nahi hai
            int temp = arr[minIdx];
            arr[minIdx] = arr[i];
            arr[i] = temp;
        }
    }
}

int main() {
    int arr[] = {99, 56, 77, 8, 80, 5, 60, 50};
    int n = 8;

    cout << "Before: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";

    selectionSort(arr, n);

    cout << "\nAfter:  ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}