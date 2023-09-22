#include <iostream>

using namespace std;

// 闰年判断函数
int is_leap_year(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int choice;

    cout << "请选择对应模式，输入数字" << endl;
    cin >> choice;

    switch (choice) {
        // 输入3个年份，并分别输出是否是闰年。
        case 1: {
            cout << "请输入三个年份，用空号分隔" << endl;

            int year[3];
            for (int &i: year) {
                cin >> i;
            }

            for (int i: year) {
                if (is_leap_year(i)) {
                    cout << i << " 是闰年" << endl;
                } else {
                    cout << i << " 不是闰年" << endl;
                }
            }

            break;
        }

            // 输入1个年份，输出是否是闰年，并输出该年份下一个闰年是多少年后，是哪一年。
        case 2: {
            cout << "请输入年份" << endl;

            int year;
            cin >> year;

            if (is_leap_year(year)) {
                cout << year << " 是闰年" << endl;
            } else {
                cout << year << " 不是闰年" << endl;
            }

            // 搜索下一个闰年
            int next_leap_year = year;
            while (true) {
                next_leap_year++;
                if (is_leap_year(next_leap_year)) {
                    cout << "下一个闰年是 " << (next_leap_year - year) << " 年后" << endl;
                    cout << "下一个闰年是 " << next_leap_year << " 年" << endl;
                    break;
                }
            }

            break;
        }

            // 随机输入3个年份，按照从小年份到大年份，依次排序输出，并根据顺序输出是否是闰年。
        case 3: {
            cout << "请输入三个年份，用空号分隔" << endl;

            int year[3];
            for (int &i: year) {
                cin >> i;
            }

            sort(year, year + 3);  // 年份排序

            for (int i: year) {
                if (is_leap_year(i)) {
                    cout << i << " 是闰年" << endl;
                } else {
                    cout << i << " 不是闰年" << endl;
                }
            }

            break;
        }

            // 错误输入时的输出
        default: {
            cout << "无效的选择" << endl;
        }
    }

    return 0;
}

