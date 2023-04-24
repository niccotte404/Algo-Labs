#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void FloydWarshall(vector<vector<int>> & dist, int n){
    for(int e = 0; e < n; e++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][e] + dist[e][j]);
            }
        }
    }
}

int main() {
    int n, m, v, u, w;
    cin >> n >> m;
    vector<vector<int>> dist(n, vector<int>(n, 1000));

    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        u--;
        v--;
        dist[u][v] = w;
        dist[v][u] = w;
    }

    for(int i = 0; i < n; i++) {
        dist[i][i] = 0;
    }

    FloydWarshall(dist, n);

    int mx = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (dist[i][j] > mx && dist[i][j] != 1000){
                mx = dist[i][j];
            }
        }
    }
    cout << mx;

    return 0;
}