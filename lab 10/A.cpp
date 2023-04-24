#include <iostream>
#include <vector>

using namespace std;

bool isDanger = false;
vector<int> danger;
vector<int> dangerOutputFormat;
vector<int> components;
int cnt = 0;

void DFS(int u, vector<int> & visited, vector<vector<int>> & list) {

    visited[u] = 1;
    if (danger[u]){
        isDanger = true;
    }
    components[u] = cnt;
    for (auto v: list[u]) {
        if (!visited[v]) {
            if (danger[v]){
                isDanger = true;
            }
            components[v] = cnt;
            DFS(v, visited, list);
        }
    }

}

void FindComponents(int n, vector<int> & visited, vector<vector<int>> & list, vector<int> & res) {

    for (int u = 0; u < n; u++) {
        if (!visited[u]) {
            cnt++;
            isDanger = false;
            DFS(u, visited, list);
            if(isDanger){
                dangerOutputFormat.emplace_back(1);
            }
            else{
                dangerOutputFormat.emplace_back(0);
            }
        }
    }

}

int main() {

    int n, m, k;
    cin >> n >> m;
    vector<vector<int>> list;
    vector<int> visited (n, 0);
    vector<int> res(n);

    list.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        list[u].push_back(v);
        list[v].push_back(u);
    }

    for (int i = 0; i < n; i++){
        cin >> k;
        danger.emplace_back(k);
        components.emplace_back(0);
    }

    FindComponents(n, visited, list, res);

    cout << cnt << "\n";
    for (auto i: components){
        cout << i << " ";
    }
    cout << "\n";
    for (auto i: dangerOutputFormat){
        cout << i << " ";
    }

    return 0;
}
