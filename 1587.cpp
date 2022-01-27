#include <iostream>
using namespace std;

int main() {

	int a[6][2];
	int i, j, u;
	int z;//Number of squares max(6)
	while (cin >> a[0][0] >> a[0][1]) {

		if (a[0][0] == a[0][1]) z = 1; else z = 0;
		for (i = 1; i < 6; i++) {
			cin >> a[i][0] >> a[i][1];
			if (a[i][0] == a[i][1]) z++;
		}

		int ks = 0, k[12] = { 0 };//The number of sides with unequal length max(12) and length
		for (i = 0; i < 6; i++)
			for (j = 0; j < 2; j++) {
				for (u = 0; u < ks;u++) if (a[i][j] == k[u]) break;
				if (u == ks) { k[ks++] = a[i][j]; }
			}

		bool ok = false;
		if (ks == 1) ok = true;//Cube
		if (ks == 2 && z == 2) ok = true;
		if (ks == 3) {
			for (u = 0; u < 3; u++) {
				int t = 0;
				for (i = 0; i < 6; i++)
					if (k[u] == a[i][0] || k[u] == a[i][1]) t++;
				if (t != 4) break;
			}
			if (u == 3) ok = true;
		}
		cout << (ok ? "" : "IM") << "POSSIBLE\n";
	}
	return 0;
}