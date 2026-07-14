#include<iostream>
using namespace std;

int arr[5] = {1, 2, 3, 4, 5};
int key = 3;
int n = 5;

int LinearSearch(int  arr[5], int n, int key)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == key)
        {
            return i ;
        }
    }
     return -1;

}