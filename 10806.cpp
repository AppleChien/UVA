#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define vvint vector< vector<int> >
#define vint vector<int>
using namespace std;

static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

int N, M;
int _s = 1, _t;
vvint edge;
vvint cost;
vvint capacity;
vvint net;
vint dis;
vint p;

void init()
{
	_t = N;
	edge.assign(110, vint());
	cost.assign(110, vint(110, 0));
	capacity.assign(110, vint(110, 0));
	net.assign(110, vint(110, 0));
	p.assign(110, 0);
}

void read()
{
	int u, v, c;
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		cin >> u >> v >> c;
		edge[u].emplace_back(v);
		edge[v].emplace_back(u);
		cost[u][v] = cost[v][u] = c;
		capacity[u][v] = capacity[v][u] = 1;
	}
}

bool bellman()
{
	dis.assign(110, INT_MAX);
	dis[_s] = 0;
	queue<int> Q;
	vint inQ(110, false);
	Q.emplace(_s);
	inQ[_s] = true;
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		inQ[u] = false;
		for (auto& v : edge[u])
		{
			if (net[v][u] > 0 && dis[u] + (-cost[v][u]) < dis[v])
				dis[v] = dis[u] + (-cost[v][u]);
			else if (capacity[u][v] > net[u][v] && dis[u] + cost[u][v] < dis[v])
				dis[v] = dis[u] + cost[u][v];
			else continue;
			p[v] = u;
			if (!inQ[v]) Q.emplace(v), inQ[v] = true;
		}
	}
	if (dis[_t] == INT_MAX) return false;
	else return true;
}

void updateflow(int u, int v, int c)
{
	if (v == _s) return;
	net[u][v] += c;
	net[v][u] -= c;
	updateflow(p[u], u, c);
}

void maxflow()
{
	int ret = 0, cnt = 0;
	while (bellman() && ++cnt <= 2)
	{
		ret += dis[_t];
		updateflow(p[_t], _t, 1);
	}
	if (cnt < 2) cout << "Back to jail\n";
	else cout << ret << "\n";
}

int main()
{
	while (cin >> N, N)
	{
		init();
		read();
		maxflow();
	}
}
