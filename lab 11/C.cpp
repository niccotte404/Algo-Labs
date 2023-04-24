#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int INF = pow(10, 7);

struct edge {
    int a;
    int b;
    int w;
};

bool FindCycle(int n, int x, vector<int> & predecessors, int k){
    if (x == -1)
        return true;
    else {
        int y = x;
        for (int i = 0; i < n; i++)
            y = predecessors[y];

        int curr = y;
        int amn = 0;
        while(true){
            amn++;
            if (curr == y && amn > 1) {
                if (amn-1 <= k){
                    return true;
                }
                else{
                    return false;
                }
            }
            curr = predecessors[curr];
        }
    }
}

bool BellmanFordAlgorithm(int n, int m, vector<edge> & edges, vector<int> & dist, vector<int> & predecessors, int k) {
    int x;
    for (int i = 0; i < n; i++) {
        x = -1;
        bool flag = false;
        for (int j = 0; j < m; j++)
            if (dist[edges[j].a] < INF)
                if (dist[edges[j].b] > dist[edges[j].a] + edges[j].w) {
                    dist[edges[j].b] = max (-INF, dist[edges[j].a] + edges[j].w);
                    predecessors[edges[j].b] = edges[j].a;
                    x = edges[j].b;
                    flag = true;
                }
        if (!flag) {
            break;
        }
    }

    if (FindCycle(n, x, predecessors, k)){
        return true;
    }
    else {
        return false;
    }
}

int main(){

    int N, m, u, v, w, k, n;
    cin >> N >> k;

    for (int i = 0; i < N; i++){
        cin >> n >> m;
        vector<edge> edges;
        vector<int> dist(n);
        vector<int> predecessors(n, -1);

        for (int j = 0; j < m; j++){
            cin >> u >> v >> w;
            u--;
            v--;
            edge e{};
            e.a = u;
            e.b = v;
            e.w = w;
            edges.emplace_back(e);
        }
        if (BellmanFordAlgorithm(n, m, edges, dist, predecessors, k)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

    return 0;
}