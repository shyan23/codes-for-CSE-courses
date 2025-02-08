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

vector<int> dp(1000, -1);

int cutRodRecur(int length, vector<int> &price)
{


    // Main Formula =  C[i] = max(1<=k<=i){v_k + c[i-k]}

    if (length == 0)
        return 0;
    if (length < 0)
        return INT_MIN;
    if (dp[length] != -1)
        return dp[length];

    int maxValue = INT_MIN;

    for (int cut = 0; cut < price.size(); cut++)
    {

        int currentValue = price[cut] + cutRodRecur(length - (cut + 1), price);
        maxValue = max(maxValue, currentValue);
    }

    return dp[length] = maxValue;
}

int cutRod(vector<int> &price, int length)
{

    fill(dp.begin(), dp.end(), -1);
    return cutRodRecur(length, price);
}

int cutRod_iterative(vector<int> &price, int length)
{
    vector<int> dp(length + 1, INT_MIN);
    dp[0] = 0;

    for (int i = 1; i <= length; i++)
    {

        for (int cut = 0; cut < min(i, (int)price.size()); cut++)
        {

            dp[i] = max(dp[i], price[cut] + dp[i - (cut + 1)]);
        }
    }

    return dp[length];
}

int main()
{
    int n, l;
    cin >> n >> l;
    vector<int> price(n);
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }

    int result = cutRod(price, l);
    cout << "Maximum revenue: " << result << endl;
    cout << endl;

    cout << cutRod_iterative(price, l);

    return 0;
}