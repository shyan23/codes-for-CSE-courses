#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

void solve(vector<vector<int>> edges, v32 &dist, int v, int e)
{
    // Relax all edges (v-1) times
    for (int i = 0; i < v - 1; i++)
    {
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];

            if (dist[u] != INF && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (auto &edge : edges)
    {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];

        if (dist[u] != INF && dist[u] + weight < dist[v])
        {
            cout << "Negative-weight cycle detected!" << ln;
            return;
        }
    }
}

int main()
{
    fast_cin();

    int e, v;
    cin >> v >> e;

    vector<vector<int>> edges;

    forn(i, e)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.pb({u, v, w});
    }

    int source;
    cin >> source;

    vector<int> dist(v, INF);
    dist[source] = 0;

    solve(edges, dist, v, e);

    forn(i, v)
    {
        if (dist[i] == INF)
            cout << "INF" << ln;
        else
            cout << dist[i] << ln;
    }

    return 0;
}
