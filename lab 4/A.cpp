#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    bool isTrue = true;
    for (int i = 0; i < (n - 1) / 2; i++){
        if (a[i] > a[2*i + 1] || a[i] > a[2*i + 2]){
            isTrue = false;
            break;
        }
    }

    if (isTrue) cout << "YES";
    else cout << "NO";

    return 0;

}