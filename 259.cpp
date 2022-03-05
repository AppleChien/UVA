#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

vector<int> x[500], y[500];
int xp[500], yp[500];
int xcount, ycount;
int xtype[500];
int xvist[500], yvist[500];

static auto fast_io = []
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    return 0;
}();

bool dfs(int node, int step)
{
    bool found = false;
    if (step & 1)//Y
    {
        yvist[node] = true;
        if (yp[node] == -1)
            found = true;
        else
            found = dfs(yp[node], step + 1);
        yvist[node] = false;
    }
    else//X
    {
        xvist[node] = true;
        for (int i = 0; i < x[node].size(); i++)
        {
            int next = x[node][i];
            if ((!yvist[next]) && xp[node] != next)
                if (dfs(next, step + 1))
                {
                    found = true;
                    xp[node] = next;
                    yp[next] = node;
                    break;
                }
        }
        xvist[node] = false;
    }

    return found;
}

int main()
{
    char str[500];
    bool going = true;

    while (going)
    {
        //init
        xcount = 0;
        ycount = 0;
        for (int i = 0; i < 10; i++)
            y[i].clear();
        for (int i = 0; i < 300; i++)
            x[i].clear();
        memset(xp, -1, sizeof(xp));
        memset(yp, -1, sizeof(yp));
        memset(xvist, 0, sizeof(xvist));
        memset(yvist, 0, sizeof(yvist));

        //inputs
        while (1)
        {
            if (!fgets(str, 200, stdin))
            {
                going = false;
                break;
            }
            if (str[0] == '\n')
                break;


            int a = str[0];
            for (int i = 0; i < str[1] - '0'; i++)
            {
                for (int i = 3; str[i] != ';'; i++)
                {
                    xtype[xcount] = a;
                    x[xcount].push_back(str[i] - '0');
                    y[str[i] - '0'].push_back(xcount);
                }
                xcount++;
            }
        }

        //process
        bool update = true;
        while (update)
        {
            update = false;
            for (int i = 0; i < xcount; i++)
                if (xp[i] == (-1) && dfs(i, 0))
                    update = true;
        }

        //ans
        bool solved = true;
        for (int i = 0; i < xcount; i++)
            if (xp[i] == -1)
            {
                puts("!");
                solved = false;
                break;
            }
        if (!solved)
            continue;
        for (int i = 0; i < 10; i++)
            if (yp[i] != -1)
                putchar(xtype[yp[i]]);
            else
                putchar('_');

        putchar('\n');

    }

    return 0;
}