#include <iostream>

using namespace std;

int main() {
    cout << "请输入一个正整数" << endl;
    int num;
    cin >> num;

    // 计算余数，使用 switch case 对应星期
    num %= 7;
    switch (num) {
        case 0:
            cout << "星期日" << endl;
            break;
        case 1:
            cout << "星期一" << endl;
            break;
        case 2:
            cout << "星期二" << endl;
            break;
        case 3:
            cout << "星期三" << endl;
            break;
        case 4:
            cout << "星期四" << endl;
            break;
        case 5:
            cout << "星期五" << endl;
            break;
        case 6:
            cout << "星期六" << endl;
            break;
        default:
            break;
    }

    return 0;
}
