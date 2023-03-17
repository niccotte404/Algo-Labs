#include <iostream>
#include <malloc.h>

using namespace std;

void Merge(int arr[], int const leftBoard, int const rightBoard, int const mid){

    //initializing && creating divided array copies
    int n1 = mid - leftBoard + 1;
    int n2 = rightBoard - mid;
    int leftArr[n1], rightArr[n2];

    //copy elements into arrays
    for (int i = 0; i < n1; i++){
        leftArr[i] = arr[leftBoard + i];
    }
    for (int i = 0; i < n2; i++){
        rightArr[i] = arr[mid + 1 + i];
    }

    //merging elements while sorting
    int i = 0, j = 0, k = leftBoard;
    while (i < n1 && j < n2){
        if (leftArr[i] < rightArr[j]){
            arr[k] = leftArr[i];
            i++;
        }
        else{
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    //rewrite lasted elements 'couse they're sorted
    while (i < n1){
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2){
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void MergeSort(int arr[], int const leftBoard, int const rightBoard){

    if (leftBoard < rightBoard){

        int mid = leftBoard + (rightBoard - leftBoard) / 2;
        MergeSort(arr, leftBoard, mid);
        MergeSort(arr, mid + 1, rightBoard);
        Merge(arr, leftBoard, rightBoard, mid);

    }

}

int main()
{
    int n;
    cin >> n;
    int* arr;
    arr = (int*) malloc (n * sizeof(int));
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    MergeSort(arr, 0, n-1);

    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}