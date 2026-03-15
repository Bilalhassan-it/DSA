//MERGE SORT USING VECTOR
#include <iostream>
#include <vector>
using namespace std;    
void merge(const vector<int>& a, const vector<int>& b, vector<int>& c)
{
    int i = 0, j = 0, k = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }
    while (i < a.size()) {
        c[k++] = a[i++];
    }
    while (j < b.size()) {
        c[k++] = b[j++];
    }
}
void mergeSort(vector<int>& a, int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        vector<int> b(a.begin() + l, a.begin() + m + 1);
        vector<int> c(a.begin() + m + 1, a.begin() + r + 1);
        merge(b, c, a);
    }
}
int main()
{    vector<int> a = {38, 27, 43, 3, 9, 82, 10};
    mergeSort(a, 0, a.size() - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}

// This code implements the merge sort algorithm using vectors in C++. 
//The `merge` function takes two sorted vectors `a` and `b`, and merges them into
// a single sorted vector `c`. The `mergeSort` function recursively divides the input vector `a`
// into halves until it reaches single elements, which are inherently sorted. 
//It then merges the sorted halves back together using the `merge` function. 
//The `main` function initializes a vector with unsorted integers, calls the `mergeSort`
// function to sort it, and then prints the sorted array.