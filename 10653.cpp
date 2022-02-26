#include <iostream>
#include <queue>
using namespace std;

static auto fast_io = []
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

int R, C;
int sx, sy, ex, ey; //起點 終點
bool bomb[1005][1005];
bool visited[1005][1005];
int d[] = { 0, 1, 0, -1, 0 }; //偏移量

int BFS()
{
    queue<pair<int, int>> q;
    q.push({ sx, sy });
    visited[sx][sy] = true;

    int steps = 0;
    while (!q.empty())
    {
        int size = q.size();

        while (size--)
        {
            auto [x, y] = q.front();
            q.pop();

            if (x == ex && y == ey) return steps;

            int dx, dy;
            auto stop = [&] //不能走的點
            {
                return dx < 0 || dx >= R || dy < 0
                    || dy >= C || visited[dx][dy] || bomb[dx][dy];
            };
            for (int i = 0; i < 4; ++i)
            {
                dx = x + d[i], dy = y + d[i + 1];
                if (stop()) continue;
                q.push({ dx, dy });
                visited[dx][dy] = true;
            }
        }
        ++steps; //先把目前可能的位置都拓展一步之後再將步數加一
    }
}

int main()
{
    while (cin >> R >> C && !(!R && !C))
    {
        // init
        fill(bomb[0], bomb[0] + 1005 * 1005, false);
        fill(visited[0], visited[0] + 1005 * 1005, false);

        int rows;
        cin >> rows;
        while (rows--)
        {
            int r, n, k;
            cin >> r >> n;
            while (n--) cin >> k, bomb[r][k] = true;
        }

        cin >> sx >> sy >> ex >> ey;
        cout << BFS() << '\n';
    }
}
