#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;

static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

struct point
{
	double x;
	double y;
	double d;
};
vector< point > V;
vector< point > ret;
int T, N;
double L;

double dist(point& a, point& b)
{
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double cross(point& o, point& a, point& b)
{
	return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

bool cmp(point& a, point& b)
{
	auto c = cross(V[0], a, b);
	return c == 0 ? a.d < b.d : c > 0;
}

void init()
{
	V.clear();
	ret.clear();
}

void read()
{
	double a, b;
	cin >> L >> N;
	for (int i = 0; i < N; ++i) cin >> a >> b, V.push_back({ a, b });
}

void GrahamScan()
{
	sort(V.begin(), V.end(), [](point& a, point& b)
		{ return a.y < b.y || (a.y == b.y && a.x < b.x); });
	for (int i = 1; i < N; ++i) V[i].d = dist(V[0], V[i]);
	sort(V.begin() + 1, V.end(), cmp);

	for (int i = 0; i < N; ++i)
	{
		int m = ret.size();
		while (m >= 2 && cross(ret[m - 2], ret[m - 1], V[i]) <= 0)
		{
			ret.pop_back();
			--m;
		}
		ret.emplace_back(V[i]);
	}
	ret.emplace_back(V[0]);
}

void print()
{
	double ans = 0;
	for (int i = 1; i < ret.size(); ++i) ans += dist(ret[i - 1], ret[i]);

	cout << setprecision(5) << fixed << max(ans, L) << "\n";
}

int main()
{
	cin >> T;
	while (T--)
	{
		init();
		read();
		GrahamScan();
		print();
	}
}