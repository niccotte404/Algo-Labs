#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// does elems have strong path
int DFS(vector<int> & visited, vector<vector<int>> & list, int a, int b) {
    if (a == b){ // common situation
        return 1;
    }
    visited[a] = 0;
    int res = 0; // if not found -> return false
    for (auto v: list[a]) {
        if (v == b){ // common situation
            return 1;
        }
        else if (visited[v] == -1) {
            res += DFS(visited, list, v, b); // if found -> res > 1 -> return true
        }
    }
    visited[a] = 1;
    return res;
}

int main() {

    // input
    int n, m, q;
    char c;
    cin >> n >> m >> q;
    vector<vector<int>> list;
    vector<int> visited (n, -1);

    list.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        list[u].push_back(v);
        list[v].push_back(u);
    }

    // input X output
    for (int i = 0; i < q; i++){
        int u, v;
        cin >> c;
        cin >> v >> u;
        v--;
        u--;
        if (c == '?'){
            for (int j = 0; j < n; j++){
                visited[j] = -1;
            }
            if (DFS(visited, list, v, u)){ // output
                cout << "YES" << "\n";
            }
            else{
                cout << "NO" << "\n";
            }
        }
        else if(c == '-'){
            // delete element using its value with remove (include algorithms -> remove/erase)
            list[v].erase(remove(list[v].begin(), list[v].end(), u), list[v].end());
            list[u].erase(remove(list[u].begin(), list[u].end(), v), list[u].end());
        }
    }

    return 0;
}
