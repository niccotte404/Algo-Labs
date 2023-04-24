#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int INF = 2147483647;

void DijkstraAlgorithm(int n, vector<vector<pair<int, int>>> & adjList, vector<int> & dist, priority_queue<pair<int, int>> & queue){
    while (!queue.empty()) {
        int v = queue.top().second;
        int curr = -queue.top().first;
        queue.pop();
        if (curr > dist[v]){
            continue;
        }
        for (auto u: adjList[v]) {
            if (dist[v] + u.second < dist[u.first]) {
                dist[u.first] = dist[v] + u.second;
                queue.push(make_pair(-dist[u.first], u.first));
            }
        }
    }
}

int main(){

    int m, u, v, w, n, q, start, end;
    cin >> n >> m >> q >> start;

    start--;
    vector<vector<pair<int,int>>> adjList(n);
    priority_queue<pair<int,int>> queue;
    queue.push(make_pair(0, start));
    vector<int> dist(n, INF);
    dist[start] = 0;

    for (int i = 0; i < m; i++){
        cin >> u >> v >> w;
        u--;
        v--;
        adjList[u].emplace_back(make_pair(v, w));
        adjList[v].emplace_back(make_pair(u, w));
    }

    DijkstraAlgorithm(n, adjList, dist, queue);

    for (int i = 0; i < q; i++){
        cin >> end;
        end--;
        if (dist[end] == INF){
            cout << -1 << endl;
        }
        else {
            cout << dist[end] << endl;
        }
    }

    return 0;
}