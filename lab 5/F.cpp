#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int key;
    int l;
    int r;
};


void Postorder(vector <int> & arr, int &i, const int n, int mn, int mx) {
    if (i >= n)
        return;
    else if (arr[i] > mx or arr[i] < mn)
        return;
    int parent = arr[i];
    i++;
    Postorder(arr, i, n, mn, parent);
    Postorder(arr, i, n, parent, mx);
    cout << parent << " ";
}


int main() {

    int n, elem;
    cin >> n;
    vector <int> arr(n);
    int mn = 200001, mx = -200001;

    for (int i = 0; i < n; i++){
        cin >> elem;
        if (elem < mn){
            mn = elem;
        }
        if (elem > mx){
            mx = elem;
        }
        arr[i] = elem;
    }

    for (int i = 0; i < n; i++){
        Postorder(arr, i, n, mn, mx);
    }

    return 0;
}