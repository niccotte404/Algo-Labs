#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{

    int n, m, currLocation, hotelLocation, v, u, p1, p2;
    cin >> n >> m;
    vector <pair<int, int>> ribs;
    for (int i = 0; i < m; i++){
        cin >> p1 >> p2;
        p1--;
        p2--;
        ribs.emplace_back(p1, p2);
    }
    cin >> currLocation >> hotelLocation;
    currLocation--;
    hotelLocation--;


    queue <int> q;
    q.push(currLocation);
    vector <int> dist(n, n);
    dist[currLocation] = 0;

    while (!q.empty()) {
        v = q.front();
        q.pop();
        for (int i = 0; i < m; i++){
            if (ribs[i].first == v){
                u = ribs[i].second;
                if (dist[u] > dist[v] + 1) {
                    dist[u] = dist[v] + 1;
                    q.push(u);
                }
            }
            else if (ribs[i].second == v){
                u = ribs[i].first;
                if (dist[u] > dist[v] + 1) {
                    dist[u] = dist[v] + 1;
                    q.push(u);
                }
            }
        }
    }

    if (dist[hotelLocation] == n){
        cout << -1;
        return 0;
    }
    cout << dist[hotelLocation];

    return 0;
}