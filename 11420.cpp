#include <iostream>
using namespace std;

long long dp[67][67][2];
int N, S;

static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

int main()
{
	// if there is one drawer, and no safe drawers, the top drawer must be unlock
	// if there is one drawer, and exist one safe drawer, the top drawer must be lock
	dp[1][0][0] = 1;
	dp[1][1][1] = 1;

	for (int i = 2; i < 66; ++i)
	{
		// if there is i drawers, and no safe drawers =
		// there is (i - 1) drawers, the top one is the only lock drawer +
		// there is (i - 1) drawers, no drawer is safe
		dp[i][0][0] = dp[i - 1][1][1] + dp[i - 1][0][0];

		for (int j = 1; j <= i; ++j)
		{
			// add one unlock drawer
			// if the top drawer is lock, this will lead to it unsafe
			dp[i][j][0] = dp[i - 1][j + 1][1] + dp[i - 1][j][0];

			// add one lock drawer
			dp[i][j][1] = dp[i - 1][j - 1][1] + dp[i - 1][j - 1][0];
		}
	}

	while (cin >> N >> S, N >= 0 && S >= 0) cout << dp[N][S][0] + dp[N][S][1] << "\n";

	return 0;
}