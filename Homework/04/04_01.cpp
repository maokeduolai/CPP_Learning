#include <iostream>
#include <string>

using namespace std;

void MoveSingle(int disk_num, const string &source, const string &dest);

void MoveBlock(int disk_num, const string &source, const string &temp, const string &dest);

int main() {
    int disk_num;
    string source, temp, dest;
    cin >> disk_num >> source >> temp >> dest;

    MoveBlock(disk_num, source, temp, dest);
    return 0;
}

// 函数传参时声明const，避免拷贝的内存开销
// 移动单个盘，并输出移动详情
void MoveSingle(int disk_num, const string &source, const string &dest) {
    cout << disk_num << ":" << source << "->" << dest << endl;
}

// 移动一组盘，递归调用
void MoveBlock(int disk_num, const string &source, const string &temp, const string &dest) {
    if (disk_num == 1) {
        MoveSingle(1, source, dest);
    } else {
        MoveBlock(disk_num - 1, source, dest, temp);
        MoveSingle(disk_num, source, dest);
        MoveBlock(disk_num - 1, temp, source, dest);
    }
}