#include <iostream>
using namespace std;

int main() {
    int testCase; //����ƥ�
    int storeNum; //�ө����ƶq
    cin >> testCase;

    while (testCase--) {
        int minNumber = 9999; //�̤p��
        int maxNumber = 0; //�̤j��
        int number; //�ө����X
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