#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n ){
    for(int i = 0; i <n-1; i++){

        for(int j = 0; j < n - i -1; j++){

            if(arr[j] > arr[j+1]){

                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
  int arr[] = {99, 56, 77, 8, 80, 5, 60, 50};
    int n = 8;

    cout << "Before: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";

    bubbleSort(arr, n);

    cout << "\nAfter:  ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;


    // int n = 10;
    // int arr[] = {99, 56, 77, 8, 80, 5, 60, 50, 82, 91};

    // cout << " Before" ;
    // for(int i = 0; i < n-1 ; i++){
    //     cout << arr[i] << " " << endl;
    // }

    //  bubbleSort(arr, n);
    
    //   cout<< "\nAfter" ;
    //  for(int i = 0; i < n-1 ; i++){
    //     cout << arr[i] << " "<< endl;
    //     return 0 ;
    //  }

}