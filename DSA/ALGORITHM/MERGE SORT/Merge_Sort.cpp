#include<iostream>
using namespace std;
void merge(int a[], int b[], int c[], int m, int n)
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
void mergeSort(int a[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        int b[m - l + 1], c[r - m];
        for (int i = 0; i < m - l + 1; i++) {
            b[i] = a[l + i];
        }
        for (int j = 0; j < r - m; j++) {
            c[j] = a[m + 1 + j];
        }
        merge(b, c, a + l, m - l + 1, r - m);
    }
}
int main()
{
    int a[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(a) / sizeof(a[0]);
    mergeSort(a, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
