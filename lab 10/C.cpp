#include <iostream>
#include <vector>

using namespace std;

vector<int> cycle, components;
int cnt = 0;

// find cycle and push path
void DFS(int u, vector<int> & visited, vector<vector<int>> & list) {
    visited[u] = 1;
    for (auto v: list[u]) {
        if (!visited[v]) {
            DFS(v, visited, list);
        }
    }
    cycle.push_back(u);
}

// find components
void FindComponents(int u, vector<int> & visited, vector<vector<int>> & parents) {
    visited[u] = 1;
    components[u] = cnt;
    for (auto v: parents[u]) {
        if (!visited[v]) {
            FindComponents(v, visited, parents);
        }
    }
}

// unite find cycles and find components
void Executor(int n, vector<int> & visited, vector<vector<int>> & list, vector<vector<int>> & parents) {
    for (int u = 0; u < n; u++) {
        if (!visited[u]) {
            DFS(u, visited, list);
        }
    }

    for (int i = 0; i < n; i++){
        visited[i] = 0;
    }

    for (int i = 0; i < n; i++){
        int u = cycle[n - 1 - i];
        if (!visited[u]){
            FindComponents(u, visited, parents);
            cnt++;
        }
    }
}

int main() {

    // input
    int n, m, q, v1, u1;
    cin >> n >> m >> q;
    vector<vector<int>> list, parents;
    vector<pair<int, int>> path;
    vector<int> visited (n, 0);

    list.resize(n);
    parents.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        list[u].push_back(v);
        parents[v].push_back(u);
    }

    path.resize(q);
    for(int i = 0; i < q; i++){
        cin >> v1 >> u1;
        v1--;
        u1--;
        path[i].first = v1;
        path[i].second = u1;
    }

    components.resize(n);
    for (int i = 0; i < n; i++){
        visited[i] = 0;
    }

    Executor(n, visited, list, parents);

    // output
    for (int i = 0; i < q; i++){
        if (components[path[i].first] == components[path[i].second]){
            cout << "YES" << "\n";
        }
        else{
            cout << "NO" << "\n";
        }
    }

    return 0;
}
