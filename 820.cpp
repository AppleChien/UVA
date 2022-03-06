#include <iostream>
#include <memory.h>
using namespace std;

static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

int N, S, T, C;
int u, v, w;
int cases = 0;
int G[101][101];
bool vis[101];

int dfs(int u, int v, int w)
{
	vis[u] = true;
	if (u == v) return w;
	for (int i = 1; i <= N; ++i) if (G[u][i] > 0 && !vis[i])
	{
		int tmp = dfs(i, v, min(w, G[u][i]));
		if (tmp > 0)
		{
			G[u][i] -= tmp;
			G[i][u] += tmp;
			return tmp;
		}
	}
	return 0;
}

int maxflow()
{
	int ret = 0, tmp;
	while (1)
	{
		memset(vis, false, sizeof(vis));
		int tmp = dfs(S, T, 10001);
		if (tmp <= 0) break;
		else ret += tmp;
	}
	return ret;
}

int main()
{
	while (cin >> N, N)
	{
		//init
		cin >> S >> T >> C;
		memset(G, 0, sizeof(G));
		//store network data
		for (int i = 0; i < C; ++i)
		{
			cin >> u >> v >> w;
			G[u][v] += w;
			G[v][u] += w;
		}
		//find maxflow
		cout << "Network " << ++cases << "\nThe bandwidth is " << maxflow() << ".\n\n";
	}
}
