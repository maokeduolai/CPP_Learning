#include <iostream>

using namespace std;

int ans[92][8], tmp[8], num = 0;

void FindQueen(int k);

int main() {
    int n;
    cin >> n;

    // 回溯法搜索可能的皇后位置
    FindQueen(0);

    // 逐个读取输出对应串
    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;

        for (int j = 0; j < 8; ++j) {
            cout << ans[b-1][j] + 1;
        }
        cout << endl;
    }
    return 0;
}

void FindQueen(int k) {
    // 如果八个皇后位置已搜寻结束，则存储
    if (k == 8) {
        for (int i = 0; i < 8; ++i) {
            ans[num][i] = tmp[i];
        }
        ++num;
        return;
    }

    int i, j;

    // 遍历8个列尝试摆放
    for (i = 0; i < 8; ++i) {
        // 遍历已经放置的皇后的冲突
        for (j = 0; j < k; ++j) {
            // (tmp[j] == i) 判断是否存在列冲突
            // (abs(j - k) == abs(tmp[j] - i)) 判断是否存在对角线冲突
            if ((tmp[j] == i) || (abs(j - k) == abs(tmp[j] - i))) {
                break;
            }
        }

        // 如果检测完毕正常退出循环，则保存皇后位置
        if (j == k) {
            tmp[k] = i;
            FindQueen(k + 1);
        }
    }
}
