#include <bits/stdc++.h>
using namespace std;

typedef vector<int> v32;

int dp[100][100];

int MSN(v32 &v, int i, int j)
{

    if (i == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;

    for (int k = i; k < j; k++)
    {

        int cost = MSN(v, i, k) + MSN(v, k + 1, j) + v[i - 1] * v[k] * v[j]; // state + parameter

        ans = min(ans, cost);
    }

    return dp[i][j] = ans;
}

int main()
{
    int n;
    cin >> n;

    v32 v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    memset(dp, -1, sizeof(dp));

    cout << MSN(v, 1, n - 1) << endl;

    return 0;
}
