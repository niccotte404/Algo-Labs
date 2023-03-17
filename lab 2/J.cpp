#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector <int> arr(n);
    for (int i = 0; i < n; ++i){
        arr[i] = i+1;
    }

    for (int i=2;i<n;i++)
        swap(arr[i], arr[i/2]);

    for (int i = 0; i < n; ++i){
        cout << arr[i] << " ";
    }

    return  0;
}