#include <bits/stdc++.h>
using namespace std;

typedef vector<int> v32;
const int N = 2e5 + 2;
v32 v[N];
bool vis[N];
vector<int> component_leads; // Stores the representative of each component

void dfs(int st) {
    vis[st] = true;
    for (auto &a : v[st]) {
        if (!vis[a]) {
            dfs(a);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    // Input edges
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    // Find connected components
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            component_leads.push_back(i); // Store a node from this component
            dfs(i);
        }
    }

    // Number of additional roads needed
    int cnt = component_leads.size();
    cout << cnt - 1 << "\n";

    // Output the roads to connect components
    for (int i = 1; i < cnt; i++) {
        cout << component_leads[i - 1] << " " << component_leads[i] << "\n";
    }

    return 0;
}
