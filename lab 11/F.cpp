#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<int> dsu;
vector<int> rang;

int find_set(int v) {
    if (v == dsu[v])
        return v;
    return dsu[v] = find_set(dsu[v]);
}

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (rang[a] < rang[b])
            swap (a, b);
        dsu[b] = a;
        if (rang[a] == rang[b])
            ++rang[a];
    }
}

int main() {

    int n, m, q, u, v;
    char c;
    cin >> n >> m >> q;
    vector<char> allReq(q);
    vector<pair<int, int>> requests;
    vector<pair<int, int>> delEdges;
    set<pair<int, int>> edges;
    int reqIter = 0, delIter = 0;

    rang.resize(n);
    dsu.resize(n);
    for (int i = 0; i < n; i++){
        dsu[i] = i;
        rang[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        u--;
        v--;
        edges.emplace(make_pair(u, v));
    }

    for (int i = 0; i < q; i++) {
        cin >> c;
        cin >> u >> v;
        v--;
        u--;
        allReq[i] = c;
        pair<int, int> edge = make_pair(u, v);
        if (c == '?') {
            requests.push_back(edge);
            reqIter++;
        }
        else if (c == '-') {
            delEdges.push_back(edge);
            edges.erase(edge);
            edges.erase(make_pair(v, u));
            delIter++;
        }
    }

    for (auto i: edges){
        pair<int, int> edge = i;
        union_sets(edge.first, edge.second);
    }

    int allReqIter = q - 1;
    vector<string> res(reqIter);
    reqIter--; delIter--;
    int resIter = reqIter;
    int amn = 0;

    pair<int, int> edge;

    for (int i = 0; i < q; i++) {
        c = allReq[allReqIter - i];
        if (c == '?') {
            edge = requests[reqIter];
            reqIter--;
            if (find_set(edge.first) == find_set(edge.second)) {
                res[amn] = "YES";
            }
            else {
                res[amn] = "NO";
            };
            amn++;
            requests.pop_back();
        }
        else if (c == '-') {
            union_sets(delEdges[delIter].first, delEdges[delIter].second);
            delIter--;
        }
    }
    for (int i = resIter; i >= 0; i--) {
        cout << res[i] << "\n";
    }
    return 0;
}