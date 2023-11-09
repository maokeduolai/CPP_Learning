#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long double a, b;
    cin >> a >> b;

    // 向下取整得到x的值
    cout << (floor)(log(b) / log(a)) << endl;

    return 0;
}
