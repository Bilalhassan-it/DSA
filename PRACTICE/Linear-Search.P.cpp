#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key)
{
    //print our array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    //cout << endl;

    for (int i = 0; i < n; i++)
    {
    //      if(arr[i] == arr[0] && i == 0){
    //   cout << "array is empty" << endl;
    //   return -1;
    // }
        if (arr[i] == key)
        {
            cout << "\nelement found" << endl;
            return i;
        }
    }
    cout << "element not found" << endl;
    return -1;
};
    
int main(){
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int key = 7;
    int n = 10;

    int result = linearSearch(arr, n, key);
    cout << "element found at index: " << result << endl;

};

// int linearSearch(int arr[], int n, int key) {
//     for(int i = 0; i < n; i++) {
//         if(arr[i] == key) {
//             return i;        // mila! index return karo
//         }
//     }
//     return -1;               // nahi mila
// }

// int main() {
//     int arr[] = {88, 11, 2, 55, 38, 45, 50, 35, 70};
//     int n = 9;
//     int key = 58;

//     int result = linearSearch(arr, n, key);

//     if(result != -1)
//         cout << "Mila at index: " << result << endl;  // 3
//     else
//         cout << "Nahi mila" << endl;

//     return 0;
// }
