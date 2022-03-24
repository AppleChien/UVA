#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

struct point
{
	int x;
	int y;
};

int N;
vector<point> V;

static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

void read()
{
	V.clear();
	for (int i = 0, a, b; i < N; ++i) cin >> a >> b, V.push_back({ a, b });
}

double ds(point& a, point& b)
{
	return max(abs(a.x - b.x), abs(a.y - b.y));
}

double Combine(int& a, int& b, int& mid, double& l, double& r)
{
	double d = min(l, r);
	double line = (V[mid].x + V[mid + 1].x) / 2;
	double Min = d;

	for (int i = mid + 1; i <= b && V[i].x < line + d; ++i)
		for (int j = mid; j >= a && V[j].x > line - d; --j)
			Min = min(Min, ds(V[i], V[j]));

	return Min;
}

double Divide(int a, int b)
{
	if (a >= b) return 1000000;

	int mid = (a + b) / 2;
	double l = Divide(a, mid);
	double r = Divide(mid + 1, b);

	return Combine(a, b, mid, l, r);
}

int main()
{
	while (cin >> N)
	{
		read();
		sort(V.begin(), V.end(), [](point& a, point& b) { return a.x < b.x; });
		cout << Divide(0, N - 1) << "\n";
	}
}