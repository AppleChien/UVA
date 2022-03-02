#include <iostream>
#include <memory.h>
#include <vector>
#include <math.h>
#include <climits>
#include <unordered_set>
using namespace std;

vector< vector< pair<int, int> > > edge;
int busyness[201];
int dis[201];
unordered_set<int> store;

static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

void bellman(int n)
{
	dis[1] = 0;

	for (int i = 0; i < n - 1; ++i) for (int u = 1; u <= n; ++u)
	{
		for (auto& [v, w] : edge[u]) if (dis[u] != INT_MAX) dis[v] = min(dis[v], dis[u] + w);
	}

	for (int u = 1; u <= n; ++u) for (auto& [v, w] : edge[u])
	{
		if (dis[v] > dis[u] + w)
		{
			dis[v] = dis[u] + w;
			store.emplace(v);
		}
	}

}

int main()
{
	int n, cases = 0;
	while (cin >> n)
	{
		// init
		edge.assign(n + 1, vector< pair<int, int> >());
		memset(busyness, 0, sizeof(busyness));
		fill(dis, dis + 201, INT_MAX);
		store.clear();

		for (int i = 1, tmp; i <= n; ++i) cin >> tmp, busyness[i] = tmp;

		int m, u, v;
		cin >> m;
		while (m--) cin >> u >> v, edge[u].push_back({ v, pow(busyness[v] - busyness[u], 3.0) });

		bellman(n);

		cout << "Set #" << ++cases << "\n";
		int q, num;
		cin >> q;
		while (q--)
		{
			cin >> num;
			if (store.count(num) || dis[num] < 3 || dis[num] == INT_MAX) cout << "?\n";
			else cout << dis[num] << "\n";
		}
	}

	return 0;
}