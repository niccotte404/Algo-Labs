#include <iostream>
#include <vector>

using namespace std;

int DFS(vector<vector<int>> & list, vector<int> &used, int v, int parent){

    used[v] = true;
    for (auto w: list[v]){
        if (!used[w]){
            if (DFS(list, used, w, v)){
                return 1;
            }
        }
        else if (w != parent){
            return 1;
        }
    }
    return 0;

}

int main()
{

    int n, m, p1, p2;
    cin >> n >> m;
    vector <pair<int, int>> edges;
    for (int i = 0; i < m; i++){
        cin >> p1 >> p2;
        p1--;
        p2--;
        edges.emplace_back(p1, p2);
    }

    vector <int> used(n);
    vector<vector<int>> list(n);
    for (auto & elem: edges)
    {
        list[elem.first].push_back(elem.second);
        list[elem.second].push_back(elem.first);
    }

    for (int i = 0; i < n; i++){
        if (!used[i]) {
            if (DFS(list, used, i, -1)){
                cout << "YES";
                return 0;
            }
        }
    }

    cout << "NO";
    return 0;
}