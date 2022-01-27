#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    int t;
    string s;
    cin >> t;
    getchar();
    while (t--)
    {
        getchar();
        int int_arry[100], n = 1;
        float f[100];
        getline(cin, s);
        stringstream ss;
        ss << s;
        while (ss >> int_arry[n])n++;
        getline(cin, s);
        ss.clear();
        ss << s;
        n = 1;
        while (ss >> f[int_arry[n]])n++;
        for (int i = 1; i < n; i++)
            cout << f[i] << endl;
    }
}