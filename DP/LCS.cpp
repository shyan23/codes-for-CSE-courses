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

int LCS(string s1, string s2, int i, int j)
{
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s1[i] == '\0' || s2[j] == '\0')
        return 0;

    if (s1[i] == s2[j])
        return dp[i][j] = LCS(s1, s2, i + 1, j + 1) + 1;
    else
        return dp[i][j] = max(LCS(s1, s2, i + 1, j), LCS(s1, s2, i, j + 1));
}

string subsequence(string s1, string s2)
{
    string ans = "";
    int i = s1.size();
    int j = s2.size();

    while (i > 0 && j > 0)
    {

        if (s1[i - 1] == s2[j - 1])
        {
            ans += s1[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    fast_cin();
    string s1;
    string s2;
    cin >> s1 >> s2;
    memset(dp, -1, sizeof(dp));
    cout << LCS(s1, s2, 0, 0) << endl;
    cout << subsequence(s1, s2);
}