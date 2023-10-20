#include <iostream>
#include <random>

using namespace std;

int main() {
    while (true) {
        int computer, player, random_number, result;

        // 创建随机数引擎
        mt19937 rng(random_device{}());

        // 创建非负数的均匀分布
        uniform_int_distribution<int> distribution(0, 2147483647);

        // 生成非负整数
        random_number = distribution(rng);

        // 计算计算机的出拳
        computer = random_number % 3;

        // 玩家出拳
        cout << "请你出拳，0表示石头，1表示剪刀，2表示布：" << endl;
        cin >> player;

        // 判断玩家出拳情况，输入错误需重新输入
        while (player < 0 || player > 2) {
            cout << "你出拳错误，请重新输入：" << endl;
            cin >> player;
        }

        // 是否平手标签
        bool flag = false;

        // 判断输赢
        result = player - computer;
        switch (result) {
            case 0: {
                cout << "你与电脑平手，请双方重新出拳！" << endl;
                flag = true;
                break;
            }
            case 1:
            case -2: {
                cout << "你输了" << endl;
                break;
            }
            case -1:
            case 2: {
                cout << "你赢了" << endl;
                break;
            }
            default:
                break;
        }

        if (flag) {
            // 平手直接进入下一轮
            continue;
        } else {
            string play_or_not;

            cout << "你还想继续玩吗？想玩请输入 Yes，否则输入 No：" << endl;
            cin >> play_or_not;

            if (play_or_not == "Yes")
                continue;
            else
                break;
        }
    }

    return 0;
}
