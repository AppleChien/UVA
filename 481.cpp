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
	int a, L = 1;
	vector<int> V;
	vector<int> S;
	vector<int> dp;
	vector<int> ans;

	while (cin >> a /*&& a != 0*/) V.emplace_back(a);
	dp.assign(V.size() + 1, 0), dp[0] = L;
	S.emplace_back(V[0]);

	for (int i = 1; i < V.size(); ++i)
	{
		if (V[i] > S.back())
		{
			S.emplace_back(V[i]);
			dp[i] = ++L;
		}
		else
		{
			auto it = lower_bound(S.begin(), S.end(), V[i]);
			*it = V[i];
			dp[i] = (it - S.begin() + 1);
		}
	}

	for (int i = V.size() - 1; i >= 0; --i) if (dp[i] == L)
	{
		ans.emplace_back(V[i]);
		--L;
	}

	cout << ans.size() << "\n-\n";
	for (int i = ans.size() - 1; i >= 0; --i) cout << ans[i] << "\n";

	return 0;
}