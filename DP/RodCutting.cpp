#include <bits/stdc++.h>
using namespace std;

vector<int> dp(1000, -1);

int cutRodRecur(int length, vector<int> &price) {
    
    if (length == 0) return 0;
    if (length < 0) return INT_MIN;
    if (dp[length] != -1) return dp[length];

    int maxValue = INT_MIN;
    
    
    for (int cut = 0; cut < price.size(); cut++) {
        
        int currentValue = price[cut] + cutRodRecur(length - (cut + 1), price);
        maxValue = max(maxValue, currentValue);
    }

    return dp[length] = maxValue;
}

int cutRod(vector<int> &price, int length) {
    
    fill(dp.begin(), dp.end(), -1);
    return cutRodRecur(length, price);
}

int main() {
    int n, l;
    cin >> n >> l;
    vector<int> price(n);
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }
    
    

    int result = cutRod(price, l);
    cout << "Maximum revenue: " << result << endl;
    cout << endl;
    for(int i = 0 ; i <= n;i++)cout << dp[i] << " ";

    return 0;
}