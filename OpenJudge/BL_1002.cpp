#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> str_phone(n), str_uni_phone(n);
    for (int i = 0; i < n; ++i) {
        char ch;
        while (cin.get(ch)) {
            if (ch == '-') {
                continue;  // 跳过读取
            }

            str_phone[i] += ch;
        }

        for (char tmp : str_phone[i]){
            if (tmp) {
                str_uni_phone[i];
            }
        }

    }
    return 0;
}
