#include <iostream>

using namespace std;

int main()
{
    // input values
    int n;
    cin >> n;
    int* arr;
    arr = new int [n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++){
        int ind = arr[i];
        int j = i - 1;
        int key = arr[i];
        while ((arr[j] > key) && (j >= 0)){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
        if (arr[i] != ind) {
            for (int a = 0; a < n; a++) {
                cout << arr[a] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}