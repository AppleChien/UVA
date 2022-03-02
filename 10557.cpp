#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector< vector<int> > G;
vector< vector<int> > G_;
vector<int> energy;
vector<int> dis;
unordered_set<int> us;

static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

void dfs(int u)
{
	us.emplace(u);
	for (auto& v : G_[u]) if (!us.count(v)) dfs(v);
}

bool bellman(int n)
{
	dis[1] = 100;

	for (int i = 0; i < n - 1; ++i) for (int u = 1; u <= n; ++u)
	{
		for (auto& v : G[u]) if (dis[u]) dis[v] = max(dis[v], dis[u] + energy[v]);
	}

	for (int u = 1; u <= n; ++u) for (auto& v : G[u])
	{
		if (dis[u] && dis[v] < dis[u] + energy[v])
		{
			if (us.count(v)) return true;
			dis[v] = dis[u] + energy[v];
		}
	}

	return dis[n];
}

int main()
{
	int n;
	while (cin >> n, n != -1)
	{
		// init
		G.assign(n + 1, vector<int>());
		G_.assign(n + 1, vector<int>());
		energy.assign(n + 1, 0);
		dis.assign(n + 1, 0);
		us.clear();

		for (int i = 1; i <= n; ++i)
		{
			int val, j, nxt;
			cin >> val >> j;
			energy[i] = val;
			while (j--) cin >> nxt, G[i].emplace_back(nxt), G_[nxt].emplace_back(i);
		}

		dfs(n);

		// bellman algorithm
		cout << (bellman(n) ? "winnable\n" : "hopeless\n");
	}

	return 0;
}