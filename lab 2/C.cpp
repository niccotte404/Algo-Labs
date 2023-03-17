#include <iostream>

using namespace std;

int main()
{
    // input values
    int n, m;
    int* arr;
    cin >> n;
    cin >> m;
    arr = new int [n * m];
    for (int i = 0; i < n * m; i++){
        cin >> arr[i];
    }

    int k;
    cin >> k;
    int* mass;
    mass = new int [k];
    for (int i = 0; i < k; i++){
        cin >> mass[i];
    }

    // algorythm
    for (int i = 0; i < n * m; i++){
        int j = i - 1;
        int key = arr[i];
        while ((arr[j] > key) && (j >= 0)){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    for (int i = 0; i < k; i++){
        int j = i - 1;
        int key = mass[i];
        while ((mass[j] > key) && (j >= 0)){
            mass[j + 1] = mass[j];
            j--;
        }
        mass[j + 1] = key;
    }

    int amn = 0;
    int a = 0;
    for (int i = 0; i < n * m; i++){
        int j = a;
        for (j; j < k; j++){
            if (arr[i] >= mass[j]){
                a++;
                amn++;
                break;
            }
            else{
                break;
            }
        }
    }
    cout << amn;

    return 0;
}