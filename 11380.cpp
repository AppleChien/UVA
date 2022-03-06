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

int X, Y, P;
int _s = 0, _t;
char c;
int G[2000][2000];
int p[2000];
bool vis[2000];
int m[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

void init()
{
	memset(G, 0, sizeof(G));
	memset(p, 0, sizeof(p));
}

void read_build()
{
	int node = X * Y;
	_t = node * 2 + 1;
	for (int j = 0; j < Y; ++j) for (int i = 0; i < X; ++i)
	{
		int u = X * j + i + 1;
		cin >> c;
		if (c == '.') G[u][u + node] = 1;
		else if (c == '@') G[u][u + node] = INT_MAX;
		else if (c == '*')
		{
			G[u][u + node] = 1;
			G[_s][u] = 1;
		}
		else if (c == '#')
		{
			G[u][u + node] = INT_MAX;
			G[u + node][_t] = P;
		}
		for (int k = 0; k < 4; ++k)
		{
			int x = i + m[k][0];
			int y = j + m[k][1];
			if (x >= 0 && y >= 0 && x < X && y < Y)
			{
				int v = X * y + x + 1;
				G[u + node][v] = INT_MAX;
			}
		}
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
			for (int i = 0; i <= _t; ++i) if (!vis[i] && G[u][i] > 0)
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
	while (cin >> Y >> X >> P)
	{
		init();
		read_build();
		cout << maxflow() << "\n";
	}
}
