#include <iostream>

using namespace std;

int main() {
    int row, i = 0;

    cout << "请输入金字塔的行数：" << endl;
    cin >> row;

    while (i < row) {
        i++;

        // 输出*前的填充位
        for (int j = 0; j < row - i; j++) {
            cout << " ";
        }

        // 输出*
        for (int j = 0; j < (i * 2 - 1); j++){
            cout << "*";
        }

        // 换到下一行
        cout << endl;
    }

    return 0;
}
