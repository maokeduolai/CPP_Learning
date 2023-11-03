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

void MoveSingle(int disk_num, const string &source, const string &dest) {
    cout << disk_num << ":" << source << "->" << dest << endl;
}

void MoveBlock(int disk_num, const string &source, const string &temp, const string &dest) {
    if (disk_num == 1) {
        MoveSingle(1, source, dest);
    } else {
        MoveBlock(disk_num - 1, source, dest, temp);
        MoveSingle(disk_num, source, dest);
        MoveBlock(disk_num - 1, temp, source, dest);
    }
}