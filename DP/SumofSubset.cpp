#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> v32;
ll dp[30][100];

bool solve(v32 &v, ll n, ll sum, ll i)
{
    if (sum == 0)
        return true;
    if (i >= n)
        return false;

    if (dp[i][sum] != -1)
        return dp[i][sum];

    bool isPossible = solve(v, n, sum, i + 1);

    if (sum - v[i] >= 0)
        isPossible |= solve(v, n, sum - v[i], i + 1); // elements cannot be re-used

    return dp[i][sum] = isPossible;
}

void backtrack(v32 &v, ll n, ll sum, ll i, vector<int> &subset)
{

    while (sum > 0 && i < n)
    {

        if (dp[i + 1][sum])
        {

            i++;
        }

        else
        {
            subset.push_back(v[i]);
            sum -= v[i];
            i++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, sum;
    cin >> n >> sum;
    v32 v(n);
    for (ll i = 0; i < n; i++)
        cin >> v[i];

    memset(dp, -1, sizeof(dp));

    bool possible = solve(v, n, sum, 0);

    if (possible)
    {
        cout << "Subset with sum " << sum << " exists.\n";
        vector<int> subset;
        backtrack(v, n, sum, 0, subset);

        cout << "Subset: ";
        for (int num : subset)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "No subset with sum " << sum << " exists.\n";
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
