#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void DFS(int u, vector<int> & visited, vector<vector<int>> & list, stack<int> & stack) {

    visited[u] = 1;
    for (auto v: list[u]) {
        if (!visited[v]) {
            DFS(v, visited, list, stack);
        }
    }
    stack.push(u);

}

void TopSort(int n, vector<int> & visited, vector<vector<int>> & list, stack<int> & stack, vector<int> & res) {

    for (int u = 0; u < n; u++) {
        if (!visited[u]) {
            DFS(u, visited, list, stack);
        }
    }
    for (int i = 1; i < n+1; i++){
        res[stack.top()] = i;
        stack.pop();
    }
}

int main() {

    int n, m;
    cin >> n >> m;
    vector<vector<int>> list;
    vector<int> visited (n, 0);
    stack<int> stack;
    vector<int> res(n);

    list.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        list[u].push_back(v);
    }

    TopSort(n, visited, list, stack, res);

    for (auto i: res){
        cout << i << " " ;
    }

    return 0;
}
