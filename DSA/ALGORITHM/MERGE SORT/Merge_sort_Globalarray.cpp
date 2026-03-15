//merge sort global array
#include<iostream>
using namespace std;    
int a[100], b[100], c[100];
void merge(int m, int n)
{
    int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
        if (a[i] < b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }
    while (i < m) {
        c[k++] = a[i++];
    }
    while (j < n) {
        c[k++] = b[j++];
    }
}
void mergeSort(int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(l, m);
        mergeSort(m + 1, r);
        for (int i = l; i <= m; i++) {
            a[i - l] = a[i];
        }
        for (int j = m + 1; j <= r; j++) {
            b[j - m - 1] = a[j];
        }
        merge(m - l + 1, r - m);
        for (int i = l; i <= r; i++) {
            a[i] = c[i - l];
        }
    }
}
int main()
{    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    mergeSort(0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}