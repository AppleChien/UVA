#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

static auto fast_io = []
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

struct edge
{
    int u;
    int v;
    int w;
};

// data
vector<edge> edges;
int dist[1000];

void init(int n)
{
    edges.clear();
    fill(dist, dist + n, INT_MAX);
}

bool bellman(int n)//如果有負環則回傳 true
{
    dist[0] = 0;

    //沒負環:則做n-1次後dist會儲存0到每個點的最短路徑
    for (int i = 0; i < n - 1; ++i) for (auto& [u, v, w] : edges)
        if (dist[u] != INT_MAX) dist[v] = min(dist[u] + w, dist[v]);

    //若任意點還能再更短則表示有負環
    for (auto& [u, v, w] : edges) if (dist[v] > dist[u] + w) return true;

    return false;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n, m;
        cin >> n >> m;
        init(n);

        while (m--)
        {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({ u, v, w });
        }

        if (bellman(n)) cout << "possible\n";
        else cout << "not possible\n";
    }
}