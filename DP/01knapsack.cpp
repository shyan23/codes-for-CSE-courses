#include <bits/stdc++.h>
using namespace std;
// ... (keeping your typedefs and defines)
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

// Recursive implementation with memoization
int knapsack_util(vector<int>& p, vector<int>& w, int wt, int n) {
    // Base case
    if (n < 0 || wt == 0) 
        return 0;
        
    // Return memoized result if exists
    if (dp[n][wt] != -1)
        return dp[n][wt];
    
    // Don't include current item
    int not_taken = knapsack_util(p, w, wt, n - 1);
    
    // Include current item if possible
    int taken = 0;
    if (w[n] <= wt) {
        taken = p[n] + knapsack_util(p, w, wt - w[n], n - 1);
    }
    
    // Store and return maximum value
    return dp[n][wt] = max(taken, not_taken);
}

// Iterative implementation with tabulation
int knapsackTabulation(vector<int>& p, vector<int>& w, int wt, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(wt + 1, 0));
    
    // Fill dp table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= wt; j++) {
            // Don't include current item
            dp[i][j] = dp[i-1][j];
            
            // Include current item if possible
            if (w[i-1] <= j) {
                dp[i][j] = max(dp[i][j], 
                              dp[i-1][j - w[i-1]] + p[i-1]);
            }
        }
    }
    
    return dp[n][wt];
}

int main() {
    fast_cin();
    
    int n, wt;
    cin >> n >> wt;
    
    vector<int> profit(n);
    vector<int> weight(n);
    
    memset(dp, -1, sizeof(dp));
    
    // Input profits and weights
    for(int i = 0; i < n; i++) 
        cin >> profit[i];
    for(int i = 0; i < n; i++) 
        cin >> weight[i];
    
    // Calculate using both methods
    cout << "Recursive result: " << knapsack_util(profit, weight, wt, n-1) << "\n";
    cout << "Iterative result: " << knapsackTabulation(profit, weight, wt, n) << "\n";
    
    return 0;
}