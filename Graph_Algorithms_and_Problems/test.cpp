#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
 
#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rsz resize
#define bk back()
#define pb push_back
 
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(x,a) for (auto& x: a)
 
const int MX  = 2e5+5;
const int MOD = 1e9+7;
const ll  INF = 1061109567; // 4557430888798830399LL
const ld  EPS = 1e-9;
const ld  PI  = acos(-1);
 
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
 
template<class T> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0;
}
template<class T> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0;
}
 
// FILE I/O
void setIn(string s) { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void setIO(string s = "") {
    ios_base::sync_with_stdio(0); cin.tie(0); // fast I/O
    // cin.exceptions(cin.failbit);
    // throws exception when do smth illegal
    // ex. try to read letter into int
    if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
}
 
template<class C, bool directed> struct Dijkstra {
    int N; vector<C> dist;
    vector<vector<pair<int,C>>> adj;
    void init(int _N) { N = _N; adj.rsz(N); }
    void ae(int u, int v, C w) {
        adj[u].pb({v,w}); if (!directed) adj[v].pb({u,w});
    }
    void gen(int st) {
        dist = vector<C>(N,numeric_limits<C>::max());
        typedef pair<C,int> T; priority_queue<T,vector<T>,greater<T>> pq;
        auto ad = [&](int a, C b) {
            if (dist[a] <= b) return;
            pq.push({dist[a] = b,a});
        }; ad(st,0);
        while(sz(pq)) { 
            T x = pq.top(); pq.pop(); if (dist[x.s] < x.f) continue;
            trav(y,adj[x.s]) ad(y.f,y.s+x.f); 
        }
    }
};
 
Dijkstra<ll,1> D;
 
int32_t main() {
 
    setIO();
 
    int n,m; cin >> n >> m; D.init(n);
 
    F0R(i,m) {
        int u,v; int w; cin >> u >> v >> w;
        D.ae(--u,--v,w);
    } 
 
    D.gen(0);
 
    F0R(i,n) cout << D.dist[i] << " ";
    cout << "\n";
 
}