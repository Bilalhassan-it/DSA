// #include <iostream>
// using namespace std;

// int binarySearchRec(int arr[], int low, int high, int key) {
//     if(low > high)               // base case: nahi mila
//         return -1;

//     int mid = low + (high - low) / 2;

//     if(arr[mid] == key)
//         return mid;              // mila!
//     else if(arr[mid] < key)
//         return binarySearchRec(arr, mid+1, high, key);  // right
//     else
//         return binarySearchRec(arr, low, mid-1, key);   // left
// }

// int main() {
//     int arr[] = {2, 11, 35, 38, 45, 50, 55, 70, 88};
//     int n = 9;

//     int result = binarySearchRec(arr, 0, n-1, 50);
//     cout << "Mila at index: " << result << endl;  // 5
//     return 0;
// }


//                   First and Last occurrence (multiple duplicates mein):

#include <iostream>
using namespace std;

int firstOccurrence(int arr[], int n, int key) {
    int low = 0, high = n-1, result = -1;

    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] == key) {
            result = mid;        // yaad rakh lo
            high = mid - 1;     // aur left mein dhoondhte raho
        }
        else if(arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return result;
}

int main() {
    int arr[] = {2, 5, 5, 5, 10, 15};
    int n = 6;
    cout << "First 5 at index: " << firstOccurrence(arr, n, 5) << endl;  // 1
    return 0;
}