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


int main() {

    int n, m, v, iter = 0, c = 0;
    char elem;
    cin >> n >> m;
    vector<vector<int>> room;

    for (int i = 0; i < n; i++) {
        room.resize(n);
        for (int j = 0; j < m; j++) {
            cin >> elem;
            if (elem == '.') {
                room[i].emplace_back(iter);
                iter++;
            }
            else {
                room[i].emplace_back(-1);
            }
        }
    };

    vector<vector<int>> list;
    list.resize(iter);

    v = iter;
    iter = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (room[i][j] >= 0) {
                if (room[i][j+1] >= 0) {
                    list[iter].push_back(iter+1);
                    list[iter+1].push_back(iter);
                }
                if (room[i][j-1] >= 0) {
                    list[iter].push_back(iter-1);
                    list[iter-1].push_back(iter);
                }
                if (room[i+1][j] >= 0) {
                    list[iter].push_back(room[i+1][j]);
                    list[room[i+1][j]].push_back(iter);
                }
                if (room[i-1][j] >= 0) {
                    list[iter].push_back(room[i-1][j]);
                    list[room[i-1][j]].push_back(iter);
                }
                iter++;
            }
        }
    }


    vector <int> used(v, -1);
    for (int i = 0; i < v; i++) {
        if (used[i] == -1) {
            c++;
            DFS(list, used, v, i);
        }
    }
    cout << c;

    return 0;
}
