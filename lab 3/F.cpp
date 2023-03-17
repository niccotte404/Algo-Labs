#include <iostream>
#include <vector>

using namespace std;

int LeftBS(vector <int> & arr, int tof, int n) {
    int l = -1;
    int r = n;
    bool isTrue = false;
    while (l < r - 1){
        int m = (l + r) / 2;
        if (arr[m+1] == tof){
            isTrue = true;
        }
        if (arr[m] < tof)
            l = m;
        else
            r = m;
    }
    if (isTrue) {
        return r+1;
    }
    else{
        return -1;
    }
}


int RightBS(vector <int> & arr, int tof, int n) {
    int l = -1;
    int r = n;
    bool isTrue = false;
    while (l < r - 1){
        int m = (l + r) / 2;
        if (arr[m] == tof){
            isTrue = true;
        }
        if (arr[m] <= tof)
            l = m;
        else
            r = m;
    }
    if (isTrue) {
        return r;
    }
    else{
        return -1;
    }
}


int main() {

    int n;
    cin >> n;
    vector <int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int iter;
    cin >> iter;
    vector <int> farr(iter);
    for (int i = 0; i < iter; i++){
        cin >> farr[i];
    }

    for (int i = 0; i < iter; i++){
        int tof = farr[i];
        int l = LeftBS(arr, tof, n);
        int r = RightBS(arr, tof, n);
        cout << l << " " << r << "\n";

    }

    return 0;

}
