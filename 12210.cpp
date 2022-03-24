#include <iostream>
using namespace std;

static auto fast_io = []
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

int Case, n, m, a, mn;

int main() 
{
    while (cin >> n >> m) 
    {
        if (n == 0 && m == 0) break;
        mn = 100;
        for (int i = 0; i < n; i++) 
        {
            cin >> a;
            mn = min(mn, a);
        }
        for (int i = 0; i < m; i++) 
        {
            cin >> a;
        }
        Case++;
        cout << "Case " << Case << ": ";
        if (n <= m) cout << 0 << "\n";
        else cout << n - m << " " << mn << "\n";
    }
}