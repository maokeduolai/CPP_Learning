#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N, all_money = 0;
    cin >> N;

    // 定义二维数组容器，存储每个人的信息
    vector<vector<string> > person_arr;

    for (int i = 0; i < N; ++i) {
        int per_money = 0;

        // 分别对每个人存储
        vector<string> person;
        string tmp;

        // 分别读入6个元数据
        for (int j = 0; j < 6; ++j) {
            cin >> tmp;
            person.push_back(tmp);
        }

        // 院士奖学金
        if ((stoi(person[1]) > 80) && (stoi(person[5]) >= 1))
            per_money += 8000;

        // 五四奖学金
        if ((stoi(person[1]) > 85) && (stoi(person[2]) > 80))
            per_money += 4000;

        // 成绩优秀奖
        if (stoi(person[1]) > 90)
            per_money += 2000;

        // 西部奖学金
        if ((stoi(person[1]) > 85) && (person[4] == "Y"))
            per_money += 1000;

        // 班级贡献奖
        if ((stoi(person[2]) > 80) && (person[3] == "Y"))
            per_money += 850;

        // 为每人记录奖学金总数
        person.push_back(to_string(per_money));

        // 添加此人信息
        person_arr.push_back(person);

        // 累加奖学金总值
        all_money += per_money;

        person.clear();
    }

    int max_pos = 0;
    // 比较每人的奖学金总数
    for (int i = 1; i < N; ++i) {
        if (stoi(person_arr[i][6]) > stoi(person_arr[max_pos][6])) {
            // 有比当前最大值还大的，就将最大位置指向他
            max_pos = i;
        }
    }

    cout << person_arr[max_pos][0] << endl << stoi(person_arr[max_pos][6]) << endl << all_money;

    return 0;
}
