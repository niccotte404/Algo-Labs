#include <stdio.h>
#include <stdlib.h>

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

int* Unique(int *arr, int n, int * uniqSize) {
    int * uniqArr = (int*)malloc(sizeof(int) * n);
    uniqArr[0] = arr[0];
    int uniqCount = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] != uniqArr[uniqCount - 1]) {
            uniqArr[uniqCount] = arr[i];
            uniqCount++;
        }
    }
    uniqArr = (int*)realloc(uniqArr, uniqCount * sizeof(int));
    *uniqSize = uniqCount;
    return uniqArr;
}

int main()
{
    int n1;
    scanf("%d", &n1);
    int* arr1;
    arr1 = (int*) malloc (n1 * sizeof(int));
    for (int i = 0; i < n1; i++){
        scanf("%d", &arr1[i]);
    }

    int n2;
    scanf("%d", &n2);
    int* arr2;
    arr2 = (int*) malloc (n2 * sizeof(int));
    for (int i = 0; i < n2; i++){
        scanf("%d", &arr2[i]);
    }

    MergeSort(arr1, 0, n1-1);
    MergeSort(arr2, 0, n2-1);

    int* uniqArrLen1 = (int*) malloc (sizeof (int));
    int* uniqArr1 = Unique(arr1, n1, uniqArrLen1);
    int* uniqArrLen2 = (int*) malloc (sizeof(int));
    int* uniqArr2 = Unique(arr2, n2, uniqArrLen2);

    if (*uniqArrLen1 != *uniqArrLen2){
        printf("NO");
    }
    else {
        int amn = 0;
        for (int i = 0; i < *uniqArrLen1; i++) {
            if (uniqArr1[i] == uniqArr2[i]) {
                amn++;
            }
        }
        if (amn == *uniqArrLen1){
            printf("YES");
        }
        else{
            printf("NO");
        }
    }

    return 0;
}