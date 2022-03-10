#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#define vll vector<long long>
using namespace std;

static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

int N, M, D, K;
int _s = 1, _t;
vector<vll> capacity;
vector<vll> net;
vector<vll> cost;
vector< vector<int> > G;
vll dis;
vector<int> p;

void init()
{
	_t = N;
	capacity.assign(110, vll(110, 0));
	net.assign(110, vll(110, 0));
	cost.assign(110, vll(110, 0));
	G.assign(110, vector<int>());
	p.assign(110, 0);
}

void read()
{
	long long u, v, c;
	for (int i = 0; i < M; ++i)
	{
		cin >> u >> v >> c;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
		cost[u][v] = cost[v][u] = c;
		capacity[u][v] = capacity[v][u] = 1;
	}
	cin >> D >> K;
}

bool bellman()
{
	dis.assign(110, LLONG_MAX);
	dis[_s] = 0;
	queue<int> Q;
	vector<bool> inQ(110, false);
	Q.emplace(_s);
	inQ[_s] = true;
	while (!Q.empty())
	{
		long long u = Q.front();
		Q.pop();
		inQ[u] = false;
		for (auto& v : G[u])
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
	if (dis[_t] == LLONG_MAX) return false;
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
	long long ret = 0;
	while (bellman())
	{
		if (D > K) ret += dis[_t] * K;
		else ret += dis[_t] * D;
		D -= K;
		updateflow(p[_t], _t, 1);
		if (D <= 0) break;
	}
	if (D > 0) cout << "Impossible.\n";
	else cout << ret << "\n";
}

int main()
{
	while (cin >> N >> M)
	{
		init();
		read();
		maxflow();
	}
}
