
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef double dl;

#define endl '\n'
#define PB push_back
#define F first
#define S second
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(x) (int)x.size()

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
#define MOD 1000000007


const int mx = 1e5+2;
ll dist[mx];
vector<vi> adj[mx];
bool train[mx];

void dijkstra ( int s, int n )
{
    for ( int i = 1; i <= n; i++ ) dist[i] = infLL;
    dist[s] = 0;
    priority_queue<pll, vll, greater<pll>> pq;
    pq.push( { 0, s } );

    while ( !pq.empty() ) {
        int u = pq.top().S;
        ll curD = pq.top().F;
        pq.pop();

        if ( dist[u] < curD ) continue;

        for ( auto e : adj[u] ) {
            int v = e[0];
            ll w = e[1];
            int type = e[2];

            if ( curD + w < dist[v] ) {
                dist[v] = curD+w;
                train[v] = type;
                pq.push( {dist[v], v} );
            }
            else if ( curD + w == dist[v] && train[v] == 1 && type == 0 ) { // jodi normally jawa jay taile train use korbo ken?
                train[v] = 0;
            }
        }
    }
}

int main()
{


	int n, m, k;
	cin >> n >> m >> k;

	for ( int i = 1; i <= m; i++ ) {
	    int u, v, w;
	    cin >> u >> v >> w;
	    adj[u].PB ( {v, w, 0} );
	    adj[v].PB ( {u, w, 0} );
	}

	for ( int i = 1; i <= k; i++ ) {
	    int u, w;
	    cin >> u >> w;
	    adj[1].PB ( {u, w, 1} );
	    adj[u].PB ( {1, w, 1} );
	}

	dijkstra(1, n);
	int ans = 0;
	for ( int i = 1; i <= n; i++ ) {
	    ans += train[i];
	}

	cout << k - ans << endl;    // total - useful trains



	return 0;
}