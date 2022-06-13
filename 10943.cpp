#include <iostream>
using namespace std;

int dp[101][101];

static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

int main()
{
	int N, K;

	for (int i = 0; i < 101; ++i) dp[i][1] = 1;
	for (int i = 0; i < 101; ++i) for (int j = 1; j < 101; ++j)
		for (int k = 0; k <= i; ++k) dp[i][j] = (dp[i][j] + dp[i - k][j - 1]) % 1000000;

	while (cin >> N >> K, N && K) cout << dp[N][K] << "\n";

	return 0;
}