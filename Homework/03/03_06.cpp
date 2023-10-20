#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a, b, c, delta;
    cout << "请输入a, b, c的值：" << endl;
    cin >> a >> b >> c;

    if (a == 0) {
        cout << "a 不能为 0" << endl;
        return 0;
    }

    delta = b * b - 4 * a * c;
    if (delta > 0) {
        cout << "该一元二次方程有两个不同实根，分别为：x1 = " << (-b + sqrt(delta)) / (2 * a) << " x2 = "
             << (-b - sqrt(delta)) / (2 * a) << endl;
    } else if (delta < 0) {
        cout << "该一元二次方程无实根" << endl;
    } else {
        cout << "该一元二次方程有两个相同实根为：x1 = x2 = " << -b / (2 * a) << endl;
    }

    return 0;
}
