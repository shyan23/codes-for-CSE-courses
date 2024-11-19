#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p32;
#define mp make_pair
#define forn(i, e) for (int i = 0; i < e; i++)
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// Global variables
char lab[1000][1001];
bool vis[1000][1001];

// Directions for moving up, down, left, right
int drow[] = {1, 0, -1, 0};
int dcol[] = {0, -1, 0, 1};

// Check if the next position is valid
bool isValid(int r, int c, int row, int cols)
{
    return r >= 0 && c >= 0 && r < row && c < cols && !vis[r][c];
}
int cnt = 0;
string path;
bool flag = false;

void solve(int row, int cols, int r, int c)
{
    queue<p32> q;
    q.push(mp(r, c));
    vis[r][c] = true;

    while (!q.empty())
    {
        p32 p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;

        if (lab[x][y] == 'B')
        {
            flag = true;
            return;
        }

        // Process the current cell
        cout << lab[x][y] << " ";

        // Explore all 4 directions
        for (int i = 0; i < 4; i++)
        {
            int adj_X = x + drow[i];
            int adj_Y = y + dcol[i];

            // Check if the adjacent cell is valid
            if (isValid(adj_X, adj_Y, row, cols))
            {
                q.push(mp(adj_X, adj_Y));
                vis[adj_X][adj_Y] = true; // Mark as visited
            }
        }
    }
}

int main()
{
    fast_cin();
    int n, m;
    cin >> n >> m;
    int a,b;
    // Input the grid
    forn(i, n)
    {
        forn(j, m)
        {
            cin >> lab[i][j];
            if (lab[i][j] = 'A')
            {
                solve(n, m, i, j);
            }
        }
    }

    // Start BFS from the top-left corner (0, 0)

    return 0;
}
