#include <iostream>
#include <cmath>

using namespace std;

class Circle {
private:
    double radius;

public:
    // 构造函数初始化半径值
    explicit Circle(double r) : radius(r) {}

    // 成员函数计算圆的面积
    [[nodiscard]] double calcArea() const {
        return M_PI * radius * radius;
    }

    // 成员函数计算圆的周长
    [[nodiscard]] double calcPerimeter() const {
        return 2 * M_PI * radius;
    }
};

int main() {
    double radius_val;
    cout << "请输入圆的半径：";
    cin >> radius_val;

    // 确保圆的半径值合法
    while (true) {
        if (radius_val > 0)
            break;
        cout << "输入数值不合法，请重新输入：";
        cin >> radius_val;
    }

    // 创建对象并初始化半径值
    Circle circle(radius_val);

    // 调用成员函数计算圆的面积与周长
    double area = circle.calcArea();
    double perimeter = circle.calcPerimeter();

    cout << "圆的面积为：" << area << endl;
    cout << "圆的周长为：" << perimeter << endl;

    return 0;
}
