#include <iostream>
using namespace std;
int BinarySearch(int arr[], int n , int key)
{
    for (int i = 0; i < n; i++)
    {
        int low = 0;
        int high = n - 1;

        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
        {
            return mid;
            cout << "founnd";
        }
        else if (arr[mid] <= key)
        {
            low = mid + 1;
        
        }
        else
        {
            high = mid - 1;
        }
        return -1;
    }
};

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10;
    int key = 7;

    int result = BinarySearch(arr, n , key);

    if(result != -1){
        cout << " \n not found : " << result << endl;
    }
    else{ 
        cout << "\n found : " << result << endl;
    }
    return 0 ;

    // cout << result << " " << endl;
}


// #include <iostream>
// using namespace std;

// int binarySearch(int arr[], int n, int key) {
//     int low = 0;
//     int high = n - 1;

//     while(low <= high) {
//         int mid = low + (high - low) / 2;  // overflow se bachao

//         if(arr[mid] == key) {
//             return mid;           // mila!
//         }
//         else if(arr[mid] < key) {
//             low = mid + 1;        // right half mein jao
//         }
//         else {
//             high = mid - 1;       // left half mein jao
//         }
//     }
//     return -1;                    // nahi mila
// }

// int main() {
//     int arr[] = {2, 11, 35, 38, 45, 50, 55, 70, 88};
//     int n = 9;
//     int key = 45;

//     int result = binarySearch(arr, n, key);

//     if(result != -1)
//         cout << "Mila at index: " << result << endl;  // 4
//     else
//         cout << "Nahi mila" << endl;

//     return 0;
// }