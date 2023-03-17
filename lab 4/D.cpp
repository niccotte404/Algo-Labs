#include <iostream>

using namespace std;

void CountingSort(string arr[], int len, int r, string sortedArr[]){

    char mx = 'a', mn = 'z';
    for (int i = 0; i < len; i++){
        if (arr[i][r] > mx){
            mx = arr[i][r];
        }
        if (arr[i][r] < mn){
            mn = arr[i][r];
        }
    }

    int arrLn = mx - mn + 1;
    int C[arrLn];

    for (int i = 0; i < arrLn; i++){
        C[i] = 0;
    }

    for (int i = 0; i < len; i++){
        C[arr[i][r] - mn]++;
    }

    for (int i = 1; i < arrLn; i++){
        C[i] += C[i-1];
    }

    for (int i = len - 1; i >= 0; i--){
        sortedArr[C[arr[i][r] - mn] - 1] = arr[i];
        C[arr[i][r] - mn]--;
    }

    for (int i = 0 ; i < len; i++){
        arr[i] = sortedArr[i];
    }

}

void RadixSort(string arr[], int len, int k, int m, string sortedArr[]){

    for (int i = m-1; i >= m-k; i--) {
        CountingSort(arr, len, i, sortedArr);
    }
}

int main(){

    int n, m, k;
    cin >> n >> m >> k;
    string arr[n];
    string sortedArr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    RadixSort(arr, n, k, m, sortedArr);

    for (int i = 0; i < n; i++){
        cout << sortedArr[i] << '\n';
    }

    return 0;
}