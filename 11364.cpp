#include <iostream>
using namespace std;

int main() {
    int testCase; //代戈计ヘ
    int storeNum; //坝┍计秖
    cin >> testCase;

    while (testCase--) {
        int minNumber = 9999; //程
        int maxNumber = 0; //程
        int number; //坝┍腹絏
        cin >> storeNum;
        for (int i = 0; i < storeNum; i++) {
            cin >> number;
            if (number > maxNumber) {
                maxNumber = number;
            }
            if (number < minNumber) {
                minNumber = number;
            }

        }
        cout << (maxNumber - minNumber) * 2;
    }
    return 0;


}