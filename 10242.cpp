#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int i, t;
	double x[4], y[4], ax, ay;

	while (cin >> x[0] >> y[0])//輸入測資 
	{
		ax = x[0];//全部的點相加 
		ay = y[0];//全部的點相加 

		for (i = 1;i < 4;i++)//輸入測資
		{
			cin >> x[i] >> y[i];
			ax += x[i];//全部點相加 
			ay += y[i];//全部點相加 
		}

		for (i = 0;i < 4;i++)
		{
			for (t = i + 1;t < 4;t++)
			{
				if (x[i] == x[t] && y[i] == y[t])//找到一樣的點 
				{
					cout << fixed << setprecision(3);//精確到小數點下三位 
					cout << ax - 3 * x[i] << " ";//輸出x座標 
					cout << ay - 3 * y[i] << endl;//輸出y座標 
				}
			}
		}
	}
	return 0;
}