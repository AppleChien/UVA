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
	int S, N, cases = 0;

	cin >> S;

	while (S-- && cin >> N)
	{
		// init
		vector<int> h(N), w(N);
		vector<int> lis(N), lds(N);
		int ans_lis = 0, ans_lds = 0;

		for (int i = 0; i < N; ++i) cin >> h[i];
		for (int i = 0; i < N; ++i) cin >> w[i], lis[i] = lds[i] = w[i];

		// find lis and lds
		for (int i = 0; i < N; ++i) for (int j = 0; j <= i; ++j)
		{
			if (h[i] > h[j]) lis[i] = max(lis[i], lis[j] + w[i]);
			if (h[i] < h[j]) lds[i] = max(lds[i], lds[j] + w[i]);

			ans_lis = max(ans_lis, lis[i]);
			ans_lds = max(ans_lds, lds[i]);
		}

		cout << "Case " << ++cases << ". ";
		if (ans_lis >= ans_lds) cout << "Increasing (" << ans_lis << "). Decreasing (" << ans_lds << ").\n";
		else cout << "Decreasing (" << ans_lds << "). Increasing (" << ans_lis << ").\n";
	}

	return 0;
}