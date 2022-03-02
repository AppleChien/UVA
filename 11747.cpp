#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

vector< tuple<int, int, int> > edge;
vector<int> parents;
vector<int> ranks;

static auto fast_io = []
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

bool cmp(tuple<int, int, int> s1, tuple<int, int, int> s2)
{
    return get<2>(s1) < get<2>(s2);
}

bool union_find(int u, int v)
{
    // find root of u and v
    while (u != parents[u]) u = parents[u];
    while (v != parents[v]) v = parents[v];

    // circle
    if (u == v) return false;

    if (ranks[u] > ranks[v]) parents[v] = u;
    else if (ranks[v] > ranks[u]) parents[u] = v;
    else parents[v] = u, ++ranks[u];

    return true;
}

void kruskcal()
{
    sort(edge.begin(), edge.end(), cmp);

    bool forest = true;

    for (auto& [u, v, w] : edge) if (!union_find(u, v))
    {
        if (!forest) cout << " ";
        cout << w;
        forest = false;
    }

    if (forest) cout << "forest";
    cout << "\n";
}

int main()
{
    int n, m;
    while (cin >> n >> m, n && m)
    {
        // init
        edge.clear();
        parents.clear();
        ranks.assign(n, 0);
        for (int i = 0; i < n; ++i) parents.emplace_back(i);

        // store side and weight
        while (m--)
        {
            int u, v, w;
            cin >> u >> v >> w;
            edge.push_back({ u, v, w });
        }

        // kruskcal algorithm
        kruskcal();
    }

    return 0;
}