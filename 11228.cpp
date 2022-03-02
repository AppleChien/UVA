#include <iostream>
#include <vector>
#include <tuple>
#include <math.h>
#include <algorithm>
using namespace std;

vector< tuple<int, int, double> > edge;
vector<int> parents;
vector<int> ranks;
int cases = 0;

static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

double dis(pair<int, int>& edge1, pair<int, int>& edge2)
{
	return sqrt(pow(edge2.first - edge1.first, 2.0) + pow(edge2.second - edge1.second, 2.0));
}

//compare distance of every two cities
bool cmp(tuple<int, int, double> edge1, tuple<int, int, double> edge2)
{
	return get<2>(edge1) < get<2>(edge2);
}

bool union_find(int c1, int c2)
{
	// find root of c1 and c2
	while (c1 != parents[c1]) c1 = parents[c1];
	while (c2 != parents[c2]) c2 = parents[c2];

	// circle
	if (c1 == c2) return false;

	if (ranks[c1] > ranks[c2]) parents[c2] = c1;
	else if (ranks[c2] > ranks[c1]) parents[c1] = c2;
	else parents[c2] = c1, ++ranks[c1];

	return true;
}

void kruskcal(int r, int n)
{
	// sort: distance small to big
	sort(edge.begin(), edge.end(), cmp);

	int side = 0;
	int state = 1;
	double raildis = 0;
	double roaddis = 0;

	for (auto& [c1, c2, dis] : edge)
	{
		if (side == n - 1) break;

		// union_find algorithm
		if (union_find(c1, c2))
		{
			if (dis > r) raildis += dis, ++state;
			else roaddis += dis;
			++side;
		}
	}

	cout << "Case #" << ++cases << ": " << state << " " << (int)(roaddis + 0.5) << " " << (int)(raildis + 0.5) << "\n";
}

int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int n, r;
		cin >> n >> r;

		// init
		edge.clear();
		parents.clear();
		ranks.assign(n, 0);
		for (int i = 0; i < n; ++i) parents.emplace_back(i);

		// store cities
		vector< pair<int, int> > city;
		for (int i = 0, a, b; i < n; ++i)
		{
			cin >> a >> b;
			city.push_back({ a, b });
		}

		// connect every two cities and calculate the distance
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				edge.push_back(make_tuple(i, j, dis(city[i], city[j])));
			}
		}

		// kruskcal algorithm
		kruskcal(r, n);
	}

	return 0;
}