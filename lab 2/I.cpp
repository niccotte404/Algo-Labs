#include <iostream>
#include <vector>

using namespace std;

int Partition(vector <int> &arr, int low, int high){

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++){
        if (arr[j] < pivot){
            i++;
            swap(arr[j], arr[i]);
        }
    }

    swap(arr[i+1], arr[high]);
    return i + 1;

}

void QuickSort(vector <int> &arr, int low, int high){

    if (low < high) {
        int p = Partition(arr, low, high);
        QuickSort(arr, low, p-1);
        QuickSort(arr, p + 1, high);
    }

}

int main()
{
    int n;
    cin >> n;
    vector <int> arr;
    for (int i = 0; i < n; i++){
        int k;
        cin >> k;
        arr.push_back(k);
    }

    QuickSort(arr, 0, n-1);

    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}