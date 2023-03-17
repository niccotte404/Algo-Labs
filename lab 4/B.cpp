#include <iostream>
#include <vector>

using namespace std;

void Siftdown(vector <int> & a, int n, int i){

    int mxInd = i;
    int leftInd = 2 * i + 1;
    int rightInd = 2 * i + 2;

    if (a[leftInd] > a[mxInd] && leftInd < n) mxInd = leftInd;
    if (a[rightInd] > a[mxInd] && rightInd < n) mxInd = rightInd;

    if (mxInd != i){
        swap(a[i], a[mxInd]);
        Siftdown(a, n, mxInd);
    }

}

void HeapSort(vector <int> & a, int n){

    for (int i = n / 2 + 1; i >= 0; i--){
        Siftdown(a, n, i);
    }

    for (int i = n - 1; i >= 0; i--){
        swap(a[i], a[0]);
        Siftdown(a, i, 0);
    }

}

int main(){

    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    HeapSort(a, n);

    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }

    return 0;

}