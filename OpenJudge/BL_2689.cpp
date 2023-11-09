#include <iostream>
#include <string>

using namespace std;

string ToggleStr(string &ori_str);

int main() {
    string ori_str, fin_str;

    // 输入整行字符串（包含空格）
    getline(cin, ori_str);

    fin_str = ToggleStr(ori_str);
    cout << fin_str << endl;
    return 0;
}

string ToggleStr(string &ori_str) {
    string result_str = ori_str;
    for (char &ch: result_str) {
        // 判断是否为字母
        if (isalpha(ch)) {
            // 根据原先字母的大小写情况确定改大写还是小写
            ch = static_cast<char>((islower(ch)) ? toupper(ch) : tolower(ch));
        }
    }
    return result_str;
}