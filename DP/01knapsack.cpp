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

int dp[100][100];

int knapsack_util(v32 p, v32 w, int wt, int n)
{
    if (dp[n][wt] != -1)
        return dp[n][wt];
    if (wt == 0 || n == 0)
        return 0;

    int nt = knapsack_util(p, w, wt, n - 1);
    if (wt - w[n] >= 0)
        nt = max(knapsack_util(p, w, wt - w[n], n - 1) + p[n], nt);

    return dp[n][wt] = nt;
}
int knapsack(v32 p, v32 w, int wt, int n)
{
    return knapsack_util(p, w, wt, n);
}

int main()
{
    fast_cin();
    int wt, n;
    cin >> n >> wt;
    v32 profit(n);
    v32 weigth(n);
    memset(dp, -1, sizeof(dp));
    forn(i, n) cin >> profit[i];
    forn(j, n) cin >> weigth[j];

    cout << knapsack(profit, weigth, wt, n - 1);
}