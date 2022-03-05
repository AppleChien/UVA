#include <iostream>
#include <memory.h>
#include <climits>
#include <queue>
using namespace std;

int N, M, U, V, C, B, D;
int _s = 0, _t;
int G[250][250];
int P[250];
bool vis[250];

static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

void init()
{
	memset(G, 0, sizeof(G));
	memset(P, 0, sizeof(P));
}

void read_build()
{
	int a;
	_t = N * 2 + 1;
	for (int i = 1; i <= N; ++i) cin >> G[i][i + N];
	cin >> M;
	while (M--) cin >> U >> V >> C, G[U + N][V] = C;

	cin >> B >> D;
	while (B--) cin >> a, G[_s][a] = INT_MAX;
	while (D--) cin >> a, G[a + N][_t] = INT_MAX;
}

int findflow(int u, int v, int c)
{
	if (v == _s) return c;
	c = findflow(P[u], u, min(G[u][v], c));
	G[u][v] -= c;
	G[v][u] += c;
	return c;
}

int maxflow()
{
	int ret = 0;
	while (1)
	{
		memset(vis, false, sizeof(vis));
		queue<int> Q;
		Q.emplace(_s);
		vis[_s] = true;
		while (!Q.empty() && !vis[_t])
		{
			int u = Q.front();
			Q.pop();
			for (int i = 0; i <= _t; ++i) if (!vis[i] && G[u][i] > 0)
			{
				Q.emplace(i);
				vis[i] = true;
				P[i] = u;
			}
		}
		if (!vis[_t]) break;
		ret += findflow(P[_t], _t, INT_MAX);
	}
	return ret;
}

int main()
{
	fast_io();
	while (cin >> N)
	{
		init();
		read_build();
		cout << maxflow() << "\n";
	}
}
