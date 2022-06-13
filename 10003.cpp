#include <iostream>
#include <memory.h>
#include <climits>
using namespace std;

int dp[52][52];
int wood[52];

static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

int main()
{
	int L, N, a, e;

	while (cin >> L, L && cin >> N)
	{
		memset(wood, 0, sizeof(wood));
		memset(dp, 0, sizeof(dp));

		// wood[0] is 0, wood[N + 1] is L
		for (int i = 1; i <= N; ++i) cin >> wood[i];
		wood[++N] = L;

		// when r = 1, the cost is always 0, so we start with r = 2
		for (int r = 2; r <= N; ++r) for (int b = 0; b < N; ++b)
		{
			if ((e = b + r) > N) break;

			dp[b][e] = INT_MAX;

			for (int c = b + 1; c < e; ++c)
			{
				int tmp = dp[b][c] + dp[c][e] + wood[e] - wood[b];
				dp[b][e] = min(dp[b][e], tmp);
			}
		}

		cout << "The minimum cutting is " << dp[0][N] << ".\n";
	}

	return 0;
}