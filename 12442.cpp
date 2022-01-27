#include <iostream>
#include <vector>
using namespace std;
vector<int> sent;
vector<bool> check, sum;
int times;
void dfs(int num)
{
	++times;
	sum[num] = check[num] = true;
	if (!check[sent[num]]) dfs(sent[num]);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T, N;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		cin >> N;
		sent.assign(N + 1, -1);
		sum.assign(N + 1, false);
		for (int j = 0, a, b; j < N; ++j) cin >> a >> b, sent[a] = b;

		int ftimes = 1;
		int fnum = sent[0];
		for (int j = 1; j <= N; ++j)
			if (!sum[j]) {
				check.assign(N + 1, false);
				check[j] = true;
				times = 1;
				dfs(sent[j]);
				if (times > ftimes || (times == ftimes && j < fnum))
					fnum = j, ftimes = times;
			}
		cout << "Case " << i << ": " << fnum << "\n";
	}
	return 0;
}
