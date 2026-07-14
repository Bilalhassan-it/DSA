 
// 1. Implement binary search to find the first occurrence of a number in a sorted array with duplicates
// 2. Implement binary search to find the last occurrence of a number in a sorted array with duplicates
// 3. Implement binary search to find the number of occurrences of a number in a sorted array with duplicates
// 4. Implement binary search to find the smallest element in a rotated sorted array   
// 5. Implement binary search to find the largest element in a rotated sorted array
// 6. Implement binary search to find the square root of a number (integer part only)

#include<iostream>
using namespace std;

int BinarySearch(int arr[5] , int n , int key){
    int left  = 0;
    int right = n - 1;
    int mid = (left + right)/2;
    while(left <= right){
        if(arr[mid] == key){
            return mid;
        }
        if(arr[mid] < key){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return -1;
}
 int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    int key = 4;
    int n = 5;
    int result = BinarySearch(arr, n , key);
    if(result != -1){
        cout<< "Element found at index: " << result;
    }
    else{
        cout<< "Element not found in the array";
    }
 }