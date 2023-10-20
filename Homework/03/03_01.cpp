#include <iostream>

using namespace std;

int main() {
    int num_1, num_2;

    cout << "请输入两个整数，用空格分隔：" << endl;
    cin >> num_1 >> num_2;

    if (num_1 > num_2) {
        cout << num_1 << " 大于 " << num_2 << endl;
    } else if (num_1 == num_2) {
        cout << num_1 << " 等于 " << num_2 << endl;
    } else {
        cout << num_1 << " 小于 " << num_2 << endl;
    }

    return 0;
}
