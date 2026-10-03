/*
Dijkstra's Algorithm (Shortest Path)
✅ Works when:
* Graph is weighted
* All edge weights are non-negative/positive
* Works on both DAG and cyclic graphs

Time: O((V + E) log V)
*/
#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define vi vector<int>

vector<int> dijkstra(int n, vector<pii> adj[], int src) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vi dist(n + 1, 1e9);

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); 
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &it : adj[u]) {
            int v = it.first, w = it.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}



int main() {

    ios::sync_with_stdio(false);

    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);

    // Input:

    // u v w

    // edge u -> v with weight w

    for (int i = 0; i < m; i++) {

        int u, v, w;

        cin >> u >> v >> w;

        adj[u].push_back({v, w});

        // For undirected graph:

        // adj[v].push_back({u, w});

    }

    int src;

    cin >> src;

    vector<int> dist = dijkstra(n, adj, src);

    for (int i = 1; i <= n; i++) {

        if (dist[i] == INT_MAX)

            cout << i << " -> INF\n";

        else

            cout << i << " -> " << dist[i] << "\n";

    }

    return 0;

}
