//INSERTION SORT FOR ASCENDING ORDER:
#include<iostream>
using namespace std;
int main(){
  int arr[5]={5,3,4,1,2};
  int n=5;
  for(int i=1; i<n; i++){
    int hold=arr[i];
    int j=i-1;
    while(j>=0 && arr[j]>hold){  //condition for descending order =arr[j]<hold
          arr[j+1]=arr[j];
          j--;
    }
           arr[j+1]=hold;
  } 
   cout<<"Sorted Array:";
  for(int i=0; i<5; i++)
     cout<<arr[i]<<" ";
  system("pause");
   return 0;
}
