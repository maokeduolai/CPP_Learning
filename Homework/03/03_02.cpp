#include <iostream>

using namespace std;

int main() {
    cout << "请输入一个整数：" << endl;

    // long 类型给 num 足够范围；count 计数整数位数
    long num;
    int count = 0;

    cin >> num;

    cout << "反向输出该整数为：" << endl;

    // 考虑原数为负数的输出情况
    if (num < 0){
        cout << "-";
        num = -num;
    }

    // 每次除以10，反向输出，同时计算位数
    do {
        cout << num % 10;
        count++;
        num /= 10;
    } while (num != 0);
    cout << endl <<"原数有 " << count << " 位" << endl;

    return 0;
}
