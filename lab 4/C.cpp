#include <iostream>
#include <vector>

using namespace std;

void Siftdown(vector <pair <int, int>> & arr, int n, int i){

    int min = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l].first < arr[min].first)
        min = l;
    if (r < n && arr[r].first < arr[min].first)
        min = r;

    if (min != i){
        swap(arr[i], arr[min]);
        Siftdown(arr, n, min);
    }

}

void Siftup(vector <pair <int, int>> & arr, int i) {
    while (arr[i].first < arr[(i - 1) / 2].first) {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int main() {

    vector <pair <int, int>> arr;
    string s;
    int p = 1, ln = 0;

    while (cin >> s){

        if (s == "push"){
            int n;
            ln++;
            cin >> n;
            arr.emplace_back(make_pair(n, p));
            Siftup(arr, ln - 1);
        }

        else if (s == "extract-min"){
            if (ln > 0) {
                cout << arr[0].first << "\n";
                arr[0] = arr[ln - 1];
                arr.pop_back();
                ln--;
                Siftdown(arr, ln, 0);
            }
            else {
                cout << "*\n";
            }
        }

        else if (s == "decrease-key"){
            int k, n;
            cin >> k >> n;
            int i;
            for (i = 0; i < ln; i++) {
                if (arr[i].second == k){
                    arr[i].first = n;
                    break;
                }
            }
            Siftup(arr, i);
        }

        p++;

    }

    return 0;

}
