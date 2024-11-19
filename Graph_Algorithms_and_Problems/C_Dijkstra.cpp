#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll INF = 1e18;

void findShortestPath(ll source, ll target, ll n, const vector<vector<pll>> &graph)
{

    vector<ll> distance(n + 1, INF);

    vector<ll> parent(n + 1, -1);

    priority_queue<pll, vector<pll>, greater<pll>> pq;

    distance[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        ll currDist = pq.top().first;
        ll currNode = pq.top().second;
        pq.pop();

        if (currDist > distance[currNode])
            continue;

        for (auto &neighbor : graph[currNode])
        {
            ll nextNode = neighbor.first;
            ll edgeWeight = neighbor.second;

            if (distance[currNode] + edgeWeight < distance[nextNode])
            {
                distance[nextNode] = distance[currNode] + edgeWeight;
                parent[nextNode] = currNode;
                pq.push({distance[nextNode], nextNode});
            }
        }
    }

    if (distance[target] == INF)
    {
        cout << -1 << endl;
        return;
    }

    vector<ll> path;
    for (ll node = target; node != -1; node = parent[node])
    {
        path.push_back(node);
    }
    reverse(path.begin(), path.end());

    for (ll node : path)
    {
        cout << node << " ";
    }
    cout << endl;
}

int main()
{

    ll n, m;
    cin >> n >> m;

    vector<vector<pll>> graph(n + 1);

    for (ll i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    findShortestPath(1, n, n, graph);

    return 0;
}
