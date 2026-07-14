#include <iostream>
#include <vector>
using namespace std;

void Merge(vector<int> &arr, int start, int mid, int end)//0(n)
{
    vector<int> temp;
    int i = start, j = mid + 1;

    while (i <= mid && j <= end)
    {

        if (arr[i] <= arr[j])// decreasing order change to arr[i] >= arr[j]
        {

            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while (j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }
    for (int index = 0; index < temp.size(); index++)
    {
        arr[start + index] = temp[index];
    }
}

void MergeSort(vector<int> &arr, int start, int end)
{

    int mid = start + (end - start) / 2;

    if (start < end)
    {
        // LEFT HALF
        MergeSort(arr, start, mid);
        // RIGHT HALF
        MergeSort(arr, mid + 1, end);

        // MERGING
        Merge(arr, start, mid, end);
    }
}

int main()
{
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10, 12, 15, 18, 21, 24, 27, 30, 33, 36, 39, 42, 45, 48};
    MergeSort(arr, 0, arr.size() - 1);
    for (int value : arr)
    {
        cout << value << " ";
    }
    cout << endl;
    return 0;
}