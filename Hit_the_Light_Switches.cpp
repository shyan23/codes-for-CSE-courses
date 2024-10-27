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
const int N = 5e5 + 1;

vector<int> adj_list[N];
bool vis[N];

void DFS_util(int vertex) {
    vis[vertex] = true;

    for (auto &c : adj_list[vertex]) {
        if (!vis[c]) {
            DFS_util(c);
        }
    }
}

int solve(int n) {
    int count = 0; // Initialize count of connected components

    for (int i = 1; i <= n; i++) { // Loop from 1 to n for 1-based indexing
        if (!vis[i]) {
            count++;
            DFS_util(i); // Start DFS from the unvisited node
        }
    }
    return count;
}

int main() {
    fast_cin();
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++) {
        int n, m;
        cin >> n >> m;

        // Reset the visited array for each test case
        fill(vis, vis + n + 1, false);

        // Clear adjacency list for each test case
        forn(i, n + 1) {
            adj_list[i].clear();
        }

        forn(i, m) {
            int x, y;
            cin >> x >> y;
            adj_list[x].push_back(y);
            //adj_list[y].push_back(x); // Assuming undirected graph
        }

        cout << "Case " << it << ": ";
        cout << solve(n) << endl;
    }
    return 0;
}
