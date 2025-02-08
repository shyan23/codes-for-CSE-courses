#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;

#define forn(i, e) for (ll i = 0; i < e; i++)
#define pb push_back
#define ln "\n"
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int timer = 1; // Global timer to track discovery times

void dfs(int node, int parent, vector<bool> &vis, vector<vector<int>> &adj,
         vector<int> &disc, vector<int> &low, vector<vector<int>> &bridges)
{
    vis[node] = true;
    disc[node] = low[node] = timer++; // Set discovery and low values for the node

    cout << "Visiting node: " << node << ", Parent: " << parent << ln;
    cout << "Initial discovery time and low value of node " << node << ": " << disc[node] << ln;

    for (int child : adj[node])
    {
        if (child == parent)
        {
            cout << "Skipping parent edge (" << node << " -> " << parent << ")" << ln;
            continue; // Skip the parent edge
        }

        if (!vis[child])
        { // If child is not visited
            cout << "Exploring edge (" << node << " -> " << child << ")" << ln;
            dfs(child, node, vis, adj, disc, low, bridges);

            // Backtracking: Update low value for the current node
            cout << "Backtracking to node " << node << " from child " << child << ln;
            cout << "Updating low[" << node << "] = min(low[" << node << "], low[" << child << "])" << ln;
            low[node] = min(low[node], low[child]);
            cout << "Updated low[" << node << "] = " << low[node] << ln;

            // Check for a bridge
            if (low[child] > disc[node])
            {
                cout << "Bridge found: (" << node << " -> " << child << ")" << ln;
                bridges.push_back({node, child});
            }
        }
        else
        {
            // A back edge is encountered
            cout << "Back edge detected (" << node << " -> " << child << ")" << ln;
            cout << "Updating low[" << node << "] = min(low[" << node << "], disc[" << child << "])" << ln;
            low[node] = min(low[node], disc[child]);
            cout << "Updated low[" << node << "] = " << low[node] << ln;
        }
    }
}

vector<vector<int>> FindingBridges(int n, vector<vector<int>> &conn)
{
    vector<vector<int>> adj(n + 1);
    for (auto &edge : conn)
    {
        adj[edge[0]].pb(edge[1]);
        adj[edge[1]].pb(edge[0]);
    }

    vector<bool> vis(n + 1, false);
    vector<int> disc(n + 1, 0);
    vector<int> low(n + 1, 0);
    vector<vector<int>> bridges;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            cout << "Starting DFS at node " << i << ln;
            dfs(i, -1, vis, adj, disc, low, bridges);
        }
    }

    sort(bridges.begin(), bridges.end());
    return bridges;
}

// DFS for finding articulation points
void dfsAP(int node, int parent, vector<bool> &vis, vector<vector<int>> &adj,
           vector<int> &disc, vector<int> &low, vector<bool> &ap)
{
    vis[node] = true;
    disc[node] = low[node] = timer++; // Set discovery and low values for the node
    int children = 0;

    cout << "Visiting node: " << node << ", Parent: " << parent << ln;
    cout << "Initial discovery time and low value of node " << node << ": " << disc[node] << ln;

    for (int child : adj[node])
    {
        if (child == parent)
        {
            cout << "Skipping parent edge (" << node << " -> " << parent << ")" << ln;
            continue; // Skip the parent edge
        }

        if (!vis[child])
        { // If child is not visited
            cout << "Exploring edge (" << node << " -> " << child << ")" << ln;
            children++; // Count children of the root node
            dfsAP(child, node, vis, adj, disc, low, ap);

            // Backtracking: Update low value for the current node
            cout << "Backtracking to node " << node << " from child " << child << ln;
            cout << "Updating low[" << node << "] = min(low[" << node << "], low[" << child << "])" << ln;
            low[node] = min(low[node], low[child]);
            cout << "Updated low[" << node << "] = " << low[node] << ln;

            // Articulation point condition for non-root nodes
            if (parent != -1 && low[child] >= disc[node])
            {
                cout << "\n";
                cout << "Articulation point found at node: " << node << ln;
                cout << "\n";
                ap[node] = true;
                ++children;
            }
        }
        else
        {
            // A back edge is encountered
            cout << "Back edge detected (" << node << " -> " << child << ")" << ln;
            cout << "Updating low[" << node << "] = min(low[" << node << "], disc[" << child << "])" << ln;
            low[node] = min(low[node], disc[child]); // Update low value using the discovery time of the back edge,nahole jodi oi point ta articulation
                                    // point hoito,then oitar low te jawa jaito na, tai greedily amra oitar disc value tai nei
            cout << "Updated low[" << node << "] = " << low[node] << ln;
        }
    }

    // Articulation point condition for root node
    if (parent == -1 && children > 1)
    {
        cout << "Root node " << node << " is an articulation point (has more than 1 child)" << ln;
        ap[node] = true;
    }
}

vector<int> FindingArticulationPoints(int n, vector<vector<int>> &conn)
{
    vector<vector<int>> adj(n + 1);
    for (auto &edge : conn)
    {
        adj[edge[0]].pb(edge[1]);
        adj[edge[1]].pb(edge[0]);
    }

    vector<bool> vis(n + 1, false);
    vector<int> disc(n + 1, 0);
    vector<int> low(n + 1, 0);
    vector<bool> ap(n + 1, false);
    int children = 0;

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            cout << "Starting DFS at node " << i << ln;
            dfsAP(i, -1, vis, adj, disc, low, ap);
        }
    }

    vector<int> articulationPoints;
    for (int i = 1; i <= n; i++)
    {
        if (ap[i])
        {
            articulationPoints.push_back(i);
        }
    }

    return articulationPoints;
}

int main()
{
    fast_cin();
    int n, t;
    cin >> n >> t;

    vector<vector<int>> conn;
    forn(i, t)
    {
        int x, y;
        cin >> x >> y;
        conn.pb({x, y});
    }

    // Finding Bridges
    // vector<vector<int>> bridges = FindingBridges(n, conn);
    // cout << "Bridges in the graph:" << ln;
    // for (auto &bridge : bridges)
    // {
    //     cout << bridge[0] << " - " << bridge[1] << ln;
    // }

    // Finding Articulation Points
    vector<int> articulationPoints = FindingArticulationPoints(n, conn);
    cout << "Articulation Points in the graph:" << ln;
    for (auto &ap : articulationPoints)
    {
        cout << ap << ln;
    }

    return 0;
}
