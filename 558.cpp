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

bool bellman(int n)//�p�G���t���h�^�� true
{
    dist[0] = 0;

    //�S�t��:�h��n-1����dist�|�x�s0��C���I���̵u���|
    for (int i = 0; i < n - 1; ++i) for (auto& [u, v, w] : edges)
        if (dist[u] != INT_MAX) dist[v] = min(dist[u] + w, dist[v]);

    //�Y���N�I�ٯ�A��u�h��ܦ��t��
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