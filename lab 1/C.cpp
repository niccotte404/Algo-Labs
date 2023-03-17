#include <iostream>
using namespace std;
int main(){
    int size;
    cin >> size;
    int* arr;
    arr = new int [size];

    for (int i=0; i < size; i++){
        cin >> arr[i];
    }

    int index;
    int minNum1 = 100000000;
    for (int i=0; i < size; i++){
        if (arr[i] < minNum1){
            minNum1 = arr[i];
            index = i;
        }
    }

    arr[index] = 100000000;

    int minNum2 = 100000000;
    for (int i=0; i < size; i++){
        if (arr[i] < minNum2){
            minNum2 = arr[i];
        }
    }
    cout << minNum1 << " " << minNum2;
    return 0;
}