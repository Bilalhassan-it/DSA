//QUICK SORT WITH ARRAY
#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int st, int end) {
    int idx = st - 1;
    int pivot = arr[end];

    for (int j = st; j < end; j++) {
        if (arr[j] <= pivot) {
            idx++;
            swap(arr[idx], arr[j]);
        }
    }

    idx++;
    swap(arr[idx], arr[end]);
    return idx;
}

void quickSort(vector<int> &arr, int st, int end) {
    if (st < end) {
        int pivIdx = partition(arr, st, end);

        // left half
        quickSort(arr, st, pivIdx - 1);

        // right half
        quickSort(arr, pivIdx + 1, end);
    }
}

int main() {
    vector<int> arr = {6, 3, 9, 5, 2, 8};

    quickSort(arr, 0, arr.size() - 1);

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}