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

ll MOD = 1e9 + 7;
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

const int N = 300123;
ll m, n, cost[N];
vector<v64> g(N), g_transpose(N), connected(N);

void normal_dfs(ll src, vector<bool>& visited, stack<ll>& st) {
    visited[src] = true;

    for (auto it : g[src]) {
        if (!visited[it]) {
            normal_dfs(it, visited, st);
        }
    }
    st.push(src);
}

void transpose_dfs(ll src, vector<bool>& visited, ll cnt) {
    visited[src] = true;

    for (auto it : g_transpose[src]) {
        if (!visited[it]) {
            transpose_dfs(it, visited, cnt);
        }
    }
    connected[cnt].pb(src);
}

ll kosaraju() {
    stack<ll> st;
    vector<bool> visited(N, false);

    forsn(i, 1, n + 1) {
        if (!visited[i]) {
            normal_dfs(i, visited, st);
        }
    }

    fill(visited.begin(), visited.end(), false);

    ll cnt = 0;
    while (!st.empty()) {
        ll top = st.top();
        st.pop();

        if (!visited[top]) {
            transpose_dfs(top, visited, cnt);
            cnt++;
        }
    }
    return cnt;
}

int main() {
    fast_cin();

    cin >> n;
    forsn(i, 1, n + 1) cin >> cost[i];

    cin >> m;
    forn(i, m) {
        ll x, y;
        cin >> x >> y;
        g[x].pb(y);
        g_transpose[y].pb(x);
    }

    ll connected_comp = kosaraju();
    ll sum = 0, num_of_ways = 1;

    forn(i, connected_comp) {
        ll mn = INF;
        for (auto it : connected[i]) mn = min(mn, cost[it]);

        ll cnt = 0;
        for (auto it : connected[i]) {
            if (cost[it] == mn) cnt++;
        }

        num_of_ways = (num_of_ways * cnt) % MOD;
        sum += mn;
    }

    cout << sum << " " << num_of_ways << ln;

    return 0;
}
