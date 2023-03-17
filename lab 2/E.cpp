#include <iostream>

using namespace std;

int main()
{
    int n, m = 2;
    int* arr;
    cin >> n;
    arr = new int [n * m];
    for (int i = 0; i < n * m; i++){
        cin >> arr[i];
    }

    for (int i = 1; i < n*2; i = i+2){
        int j = i - 2;
        int points = arr[i];
        int id = arr[i-1];
        while (((arr[j] < points) && (j >= 0)) || ((arr[j] == points) && (j >= 0) && (arr[j-1] > id))){
            arr[j + 2] = arr[j];
            arr[j + 1] = arr[j - 1];
            j -= 2;
        }
        arr[j + 2] = points;
        arr[j + 1] = id;
    }

    for (int i = 1; i < n*2; i = i+2){
        cout << arr[i-1] << " " << arr[i] << endl;
    }

    return 0;
}