#include <iostream>
#include<vector>
#include<cstring>
using namespace std;
#define N 5005
#define INF 1000000
int q[4][2] = { 1,0,0,1,-1,0,0,-1 };

static auto fast_io = []
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

struct edge
{
    int to, cap, rev;
    edge(int a, int b, int c)
    {
        to = a;
        cap = b;
        rev = c;
    }
};

vector<edge>v[N];
void add_edge(int from, int to, int cap);
int dfs(int a, int t, int f);
int max_flow(int s, int t);
int used[N];
int vis[60][60];
int m, n, num;

void add_edge(int from, int to, int cap)
{
    v[from].push_back(edge(to, cap, v[to].size()));
    v[to].push_back(edge(from, 0, v[from].size() - 1));
}

int dfs(int a, int t, int f)
{
    if (a == t)
        return f;
    used[a] = 1;
    for (int i = 0; i < v[a].size(); i++)
    {
        edge& e = v[a][i];
        if (!used[e.to] && e.cap > 0)
        {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0)
            {
                e.cap -= d;
                v[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t)
{
    int flow = 0;
    while (1)
    {
        memset(used, 0, sizeof(used));
        int f = dfs(s, t, INF);
        if (f == 0)
            return flow;
        flow += f;
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int a, b, c, d;
        cin >> m >> n >> num;
        //memset(vis,0,sizeof(vis));
        for (int i = 0; i < N; i++)
            v[i].clear();
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                add_edge((i - 1) * n + j, (i - 1) * n + j + m * n, 1);
                for (int k = 0; k < 4; k++)
                {
                    int k1 = i + q[k][0];
                    int k2 = j + q[k][1];
                    if (k1 > 0 && k1 <= m && k2 > 0 && k2 <= n)
                    {
                        add_edge((i - 1) * n + j + m * n, (k1 - 1) * n + k2, 1);
                    }
                }
            }
        }

        for (int i = 0; i < num; i++)
        {
            cin >> c >> d;
            add_edge(0, (c - 1) * n + d, 1);
        }
        for (int i = 1; i <= n; i++)
        {
            add_edge(i + m * n, m * n * 2 + 1, 1);
        }
        if (m > 1)
        {
            for (int i = 1; i <= n; i++)
            {
                add_edge(i + (m - 1) * n + m * n, m * n * 2 + 1, 1);
            }
        }
        for (int i = 2; i < m; i++)
            add_edge((i - 1) * n + 1 + m * n, m * n * 2 + 1, 1);

        if (n > 1)
        {
            for (int i = 2; i < m; i++)
                add_edge(i * n + m * n, m * n * 2 + 1, 1);
        }
        int ans = max_flow(0, m * n * 2 + 1);
        //cout<<ans;
        if (ans == num)
            cout << "possible\n";
        else
            cout << "not possible\n";
    }
    return 0;
}