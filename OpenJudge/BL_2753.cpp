#include <iostream>

using namespace std;

int Fib(int n);

int main() {
    int n;
    cin >> n;

    // 循环读入数
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        cout << Fib(a) << endl;
    }

    return 0;
}

int Fib(int n) {
    // 0或1时直接返回值
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return Fib(n - 1) + Fib(n - 2);
    }
}
