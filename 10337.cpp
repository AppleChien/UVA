#include <iostream>
#include <vector>
using namespace std;

static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

int main()
{
	int N, X, a;
	vector< vector<int> > wind;
	vector< vector<int> > dp;

	cin >> N;
	while (N--)
	{
		cin >> X, X /= 100;

		// init
		wind.assign(10, vector<int>());
		dp.assign(10, vector<int>(X + 1, 100000));
		dp[0][0] = 0;

		// store wind data (up to down)
		for (int i = 9; i >= 0; --i) for (int j = 0; j < X; ++j)
		{
			cin >> a;
			wind[i].emplace_back(a);
		}

		// DP
		for (int j = 1; j <= X; ++j) for (int i = 0; i < 10; ++i)
		{
			int Min = 100000;

			if (i != 0)
			{
				Min = min(Min, dp[i][j - 1] + 30 - wind[i][j - 1]);
				Min = min(Min, dp[i - 1][j - 1] + 60 - wind[i - 1][j - 1]);
			}
			if (i != 9) Min = min(Min, dp[i + 1][j - 1] + 20 - wind[i + 1][j - 1]);

			dp[i][j] = Min;
		}

		/* print dp
		for (int i = 9; i >= 0; --i)
		{
			for (int j = 0; j <= X; ++j) cout << dp[i][j] << " ";
			cout << "\n";
		}
		*/

		cout << dp[0][X] << "\n\n";
	}

	return 0;
}