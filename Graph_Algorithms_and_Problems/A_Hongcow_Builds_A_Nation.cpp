#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef pair<ll, ll> p64;

#define MOD 1000000007
#define INF 1e9
#define pb push_back
#define endl "\n"
#define fi first
#define se second
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define dbg(x) cout << #x << " = " << x << endl
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

const int N = 3e5 + 5;

v64 adj[N];
vector<bool> visited;
ll ec, nc, max_ED;

void dfs(ll curr) {
    nc++;
    visited[curr] = true;
    for (auto el : adj[curr]) {
        if (!visited[el]) {
            dfs(el);
        }
    }
}

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;

    v64 c(k);
    forn(i, k) {
        cin >> c[i];
    }

    // Create the adjacency list for the graph
    forn(i, m) {
        ll u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    visited.resize(n + 1, false);
    max_ED = 0;
    ll max_Govt_Node_cnt = 0;

    // Perform DFS for each city in the list c
    forn(i, k) {
        nc = 0;
        dfs(c[i]);
        max_ED += nc * (nc - 1) / 2;
        max_Govt_Node_cnt = max(max_Govt_Node_cnt, nc);
    }

    // Count the number of unvisited cities
    ll notVisited = 0;
    for (ll i = 1; i <= n; i++) {
        notVisited += (!visited[i]);
    }

    // Join all the non-visited Edges
    max_ED += notVisited * (notVisited - 1) / 2;
    max_ED += notVisited * max_Govt_Node_cnt;   // joining the nonVis to the maximum govt section

    cout << max_ED - m << endl;
}

int main() {
    fast_cin();
    solve();
    return 0;
}
