#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

static auto fast_io = []
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);
	return 0;
}();

const int maxn = 10000 + 5;
int a[maxn];
int vis[maxn];
vector<int> c[maxn];
int n;

int main()
{

	int kase = 0;
	while (cin >> n && n)
	{
		if (kase)   cout << endl;
		kase = 1;
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			vis[a[i]]++;
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			cnt = max(cnt, vis[a[i]]);
		}
		sort(a + 1, a + n + 1);
		cout << cnt << endl;
		for (int i = 1; i <= cnt; i++)
		{
			int first = 1;
			for (int j = i; j <= n; j += cnt)
			{
				if (first)
				{
					cout << a[j];
					first = 0;
				}
				else   cout << " " << a[j];
			}
			cout << endl;
		}
	}
}