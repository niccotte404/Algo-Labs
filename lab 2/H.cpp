#include <iostream>
#include <vector>

using namespace std;

bool operator < (pair <int, int> p1, pair<int, int> p2){
    if (p1.first == p2.first){
        return p1.second < p2.second;
    }
    return p1.first < p2.first;
}

bool operator > (pair <int, int> p1, pair<int, int> p2){
    if (p1.first == p2.first){
        return p1.second > p2.second;
    }
    return p1.first > p2.first;
}

void QuickSort(vector <pair <int, int>> & arr, int l, int h){

    int i = l;
    int j = h;
    pair <int, int> x = arr[(l + h) / 2];
    while (i <= j){
        while (arr[i] < x){
            i++;
        }
        while (arr[j] > x){
            j--;
        }
        if (i <= j){
            pair <int, int> tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }

    if (l < j){
        QuickSort(arr, l, j);
    }
    if (h > i){
        QuickSort(arr, i, h);
    }

}

int main()
{

    int n;
    cin >> n;
    vector <pair <int, int>> arr;

    for (int i = 0; i < n; i++){
        int k, k1;
        cin >> k >> k1;

        if (k < k1) {
            arr.push_back(make_pair(k, k1));
        }
        else{
            arr.push_back(make_pair(k1, k));
        }
    }

    QuickSort(arr, 0, n-1);

    int s = arr[0].first;
    int e = arr[0].second;
    int c = 0;

    for (int i = 1; i < n; i++){
        if (arr[i].first > e){
            c += arr[i].first - e - 1;
            e = arr[i].second;
        }
        else{
            if (arr[i].first >= s && arr[i].first <= e)
                if (arr[i].second > e)
                    e = arr[i].second;
        }
    }

    cout << e - s - c + 1;

    return 0;

}