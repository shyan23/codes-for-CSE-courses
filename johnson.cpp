#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Edge {
    int u, v, weight;
};

class JohnsonsAlgorithm {
public:
    int V;
    vector<Edge> edges;
    vector<vector<pair<int, int>>> adjList;

    JohnsonsAlgorithm(int V) : V(V), adjList(V) {}

    void addEdge(int u, int v, int weight) {
        edges.push_back({u, v, weight});
        adjList[u].push_back({v, weight});
    }

    bool bellmanFord(vector<int>& h) {
        h.assign(V, INF);
        h[V - 1] = 0; // New source vertex

        for (int i = 0; i < V - 1; i++) {
            bool updated = false;
            for (auto &edge : edges) {
                if (h[edge.u] < INF && h[edge.v] > h[edge.u] + edge.weight) {
                    h[edge.v] = h[edge.u] + edge.weight;
                    updated = true;
                }
            }
            if (!updated) break;
        }

        for (auto &edge : edges) {
            if (h[edge.u] < INF && h[edge.v] > h[edge.u] + edge.weight)
                return false; // Negative cycle detected
        }
        return true;
    }

    void dijkstra(int src, vector<int>& dist) {
        dist.assign(V, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            for (auto &[v, weight] : adjList[u]) {
                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
    }

    void johnson() {
        int originalV = V;
        V++; // Add extra vertex q
        for (int i = 0; i < originalV; i++)
            addEdge(originalV - 1, i, 0); // Connect q to all nodes with weight 0

        vector<int> h;
        if (!bellmanFord(h)) {
            cout << "Negative-weight cycle detected! Algorithm terminated.\n";
            return;
        }

        // Reweight edges
        for (auto &edge : edges)
            edge.weight += h[edge.u] - h[edge.v];

        adjList.clear();
        adjList.resize(originalV);
        for (auto &edge : edges)
            if (edge.u < originalV && edge.v < originalV)
                adjList[edge.u].push_back({edge.v, edge.weight});

        V = originalV; // Restore original V

        // Run Dijkstra for each vertex
        for (int u = 0; u < V; u++) {
            vector<int> dist;
            dijkstra(u, dist);
            for (int v = 0; v < V; v++) {
                if (dist[v] == INF)
                    cout << "INF ";
                else
                    cout << (dist[v] - h[u] + h[v]) << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    int V = 4;
    JohnsonsAlgorithm ja(V);

    ja.addEdge(0, 1, 4);
    ja.addEdge(0, 2, 1);
    ja.addEdge(2, 1, 2);
    ja.addEdge(1, 3, 1);
    ja.addEdge(2, 3, 5);

    cout << "All Pairs Shortest Paths using Johnson's Algorithm:\n";
    ja.johnson();

    return 0;
}
