#include<iostream>
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

long long n, k, a, ans;
vector <int> d, v;

int main() 
{

    while (cin >> n >> k) 
    {
        if (n == 0 && k == 0) break;
        d.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            d.push_back(a);
        }
        v.clear();
        for (int i = 0; i < k; i++) 
        {
            cin >> a;
            v.push_back(a);
        }
        if (n > k) 
        {
            cout << "Loowater is doomed!\n";
            continue;
        }
        sort(d.begin(), d.end());
        sort(v.begin(), v.end());
        int idx = 0;
        bool flag = true;
        ans = 0;
        for (int i = 0; i < n; i++) 
        {
            while (v[idx] < d[i] && idx < k - 1) idx++;
            if (v[idx] < d[i])
            {
                flag = false;
                break;
            }
            ans += v[idx];
            idx++;
        }
        if (!flag) cout << "Loowater is doomed!\n";
        else cout << ans << "\n";
    }
}