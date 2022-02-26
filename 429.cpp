#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
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
    int T;
    cin >> T;
    while (T--)
    {
        vector<string> words;

        string word;
        while (cin >> word, word != "*")
            words.push_back(word);

        cin.ignore();

        string line;
        while (getline(cin, line) && line != "")
        {
            stringstream ss(line);
            string s, t;
            ss >> s >> t;
            //BFS
            queue<string> q;
            map<string, int> trans;

            trans[s] = 0;
            q.push(s);
            while (!q.empty() && trans.count(t) == 0)
            {
                string u = q.front();
                q.pop();

                for (size_t i = 0; i < words.size(); ++i)
                {
                    const string& v = words[i];
                    if (!trans.count(v) && u.length() == v.length())
                    {
                        int diff = 0;
                        for (size_t j = 0; j < u.length(); ++j)
                            if (u[j] != v[j])
                                ++diff;
                        if (diff == 1)
                        {
                            trans[v] = trans[u] + 1;
                            q.push(v);
                        }
                    }
                }
            }
            cout << s << " " << t << " " << trans[t] << endl;
        }
        if (T)
            cout << endl;
    }
    return 0;
}