#include <stdio.h>

int QuickSelect(int * arr, int n, int k){

    if (n == 1){
        return arr[0];
    }

    int i = 0;
    int j = n-1;
    int x = arr[n / 2];
    while (i <= j){
        while (arr[i] < x){
            i++;
        }
        while (arr[j] > x){
            j--;
        }
        if (i >= j){
            break;
        }
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
        i++;
        j--;
    }

    if (k <= i){
        return QuickSelect(arr, i, k);
    }
    else {
        return QuickSelect(arr + i, n-i, k-i);
    }

}

int main(){

    int n, k, A, B, C, a1, a2;
    scanf("%d %d", &n, &k);
    scanf("%d %d %d %d %d", &A, &B, &C, &a1, &a2);
    int arr[n];
    arr[0] = a1;
    arr[1] = a2;
    for (int i = 2; i < n; ++i){
        arr[i] = A * arr[i-2] + B * arr[i-1] + C;
    }

    printf("%d", QuickSelect(arr, n, k));

    return 0;
}