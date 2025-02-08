#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define ln "\n"
#define INF INT_MAX
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

const int N = 1e3;


bool bfs(int src, int sink, int parent[], int v, int rgraph[][N]) {
    memset(parent, -1, sizeof(int) * v);
    bool visited[N] = {false};
    queue<int> q;
    
    q.push(src);
    visited[src] = true;
    
    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        for (int i = 0; i < v; i++) {
            if (!visited[i] && rgraph[curr][i] > 0) {
                parent[i] = curr;
                visited[i] = true;
                
                if (i == sink)
                    return true;
                
                q.push(i);
            }
        }
    }
    return false;
}


int maxflow(int src, int sink, int rgraph[][N], int v) {
    int parent[N];
    int maxFlow = 0;

    while (bfs(src, sink, parent, v, rgraph)) {
        int pathFlow = INF;

        
        for (int i = sink; i != src; i = parent[i]) {
            int x = parent[i];
            pathFlow = min(pathFlow, rgraph[x][i]);
        }

        
        for (int i = sink; i != src; i = parent[i]) {
            int x = parent[i];
            rgraph[x][i] -= pathFlow;
            rgraph[i][x] += pathFlow;
        }

        maxFlow += pathFlow;
    }
    return maxFlow;
}

int main() {
    fast_cin();
    
    int v;
    cin >> v;
    int graph[N][N] = {0}; 

    forn(i, v) {
        forn(j, v) {
            cin >> graph[i][j];
        }
    }

    int rgraph[N][N];
    forn(i, v) forn(j, v) rgraph[i][j] = graph[i][j];

    int src, sink;
    cin >> src >> sink;

    cout << "Maximum Flow: " << maxflow(src, sink, rgraph, v) << ln;
    return 0;
}
