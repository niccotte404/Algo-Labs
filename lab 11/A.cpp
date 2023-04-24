#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void FloydWarshall(vector<vector<int>> & dist, int n, int k){
    for(int e = 0; e < n; e++) {
        for(int i = 0; i < n; i++) {
            if (dist[i][e] == 1){
                continue;
            }
            for(int j = 0; j < n; j++) {
                if (dist[e][j] <= k)
                    dist[i][j] = min(dist[i][j], dist[i][e] + dist[e][j]);
            }
        }
    }
}

int main() {
    int n, m, k, q, v, u, w, s, e;
    cin >> n >> m >> k;
    vector<vector<int>> dist(n, vector<int>(n, pow(10, 7)));

    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        u--;
        v--;
        dist[u][v] = w;
    }
    cin >> q;

    for(int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }

    FloydWarshall(dist, n, k);

    for (int i = 0; i < q; i++){
        cin >> s >> e;
        s--;
        e--;
        if (dist[s][e] == pow(10, 7)){
            cout << -1 << "\n";
        }
        else {
            cout << dist[s][e] << "\n";
        }
    }

    return 0;
}