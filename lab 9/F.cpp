#include <iostream>
#include <vector>

using namespace std;

void DFS(vector<vector<int>> & list, vector<int> & used, int V,  int u) {
    used[u] = 0;
    for (auto j : list[u]) {
        if (used[j] == -1) {
            DFS(list, used, V,  j);
        }
    }
    used[u] = 1;
}


int main(){

    int n, m, u, v, c = 0;
    cin >> n >> m;
    vector<pair<int, int>> edges;
    vector<int> used(n, -1);

    for (int i = 0; i < m; i++){
        cin >> v >> u;
        v--;
        u--;
        edges.emplace_back(v, u);
    }

    vector<vector<int>> list(n);
    for (auto & elem: edges){
        list[elem.first].push_back(elem.second);
        list[elem.second].push_back(elem.first);
    }

    for (int i = 0; i < n; i++) {
        if (used[i] == -1) {
            c++;
            DFS(list, used, n, i);
        }
        if (c != 1){
            cout << "NO";
            return 0;
        }
    }


    int deg1 = 0;
    for (int i = 0; i < n; i++){
        if (list[i].size() > 2){
            cout << "NO";
            return 0;
        }
        if (list[i].size() == 1){
            deg1++;
        }
    }
    if (deg1 != 2){
        cout << "NO";
        return 0;
    }


    cout << "YES";
    return 0;
}