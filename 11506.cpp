#include <iostream>
#include <memory.h>
#include <climits>
#include <queue>
using namespace std;

static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

int M, W, U, V, C;
int _s = 1, _t;
int G[150][150];
int p[150];
bool vis[150];

void init()
{
	memset(G, 0, sizeof(G));
	memset(p, 0, sizeof(p));
}

void read_build()
{
	int node = M - 2;
	int _u, _v;
	_t = M + node;
	for (int i = 0; i < node; ++i)
	{
		cin >> U >> C;
		G[U][U + node] = G[U + node][U] = C;
	}
	while (W--)
	{
		cin >> U >> V >> C;
		if (U == M) U = _t;
		if (V == M) V = _t;
		_u = (U != 1 && U != _t ? U + node : U);
		_v = (V != 1 && V != _t ? V + node : V);
		G[_u][V] = G[_v][U] = C;
	}
}

int findflow(int u, int v, int c)
{
	if (v == _s) return c;
	c = findflow(p[u], u, min(G[u][v], c));
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
			for (int i = _s; i <= _t; ++i) if (!vis[i] && G[u][i] > 0)
			{
				Q.emplace(i);
				vis[i] = true;
				p[i] = u;
			}
		}
		if (!vis[_t]) break;
		ret += findflow(p[_t], _t, INT_MAX);
	}
	return ret;
}

int main()
{
	while (cin >> M >> W, !(!M && !W))
	{
		init();
		read_build();
		cout << maxflow() << "\n";
	}
}
