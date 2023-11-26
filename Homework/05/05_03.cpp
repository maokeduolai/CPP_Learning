#include <iostream>

using namespace std;

class Point {
private:
    double x, y;

public:
    // 构造函数对点的位置进行初始化
    Point(double initX, double initY) : x(initX), y(initY) {};

    // 成员函数显示坐标
    void display() const {
        cout << "目前点的位置为：(" << x << ", " << y << ")" << endl;
    }

    // 成员函数更改x, y值
    void setXY(double newX, double newY) {
        x = newX;
        y = newY;
    }
};

class Rectangle : public Point {
private:
    double length, width;

public:
    // 构造函数使用点坐标、长、宽进行初始化
    Rectangle(double initX, double initY, double initLen, double initWid) : Point(initX, initY), length(initLen),
                                                                            width(initWid) {};

    // 成员函数计算矩形面积
    [[nodiscard]] double calcArea() const {
        return length * width;
    }

    // 成员函数计算矩形周长
    [[nodiscard]] double calcPerimeter() const {
        return 2 * (length + width);
    }
};

int main() {
    // 创建点对象，并初始化点的位置，显示点的位置
    Point point(2.3, 5.6);
    point.display();

    // 更改点的坐标并显示点的位置
    point.setXY(6.7, 8.9);
    point.display();

    // 创建矩形对象，初始化点的位置和矩形长宽，计算输出矩形面积与周长
    Rectangle rectangle(4.4, 5.7, 5.0, 8.0);
    cout << "矩形的面积为：" << rectangle.calcArea() << endl;
    cout << "矩形的周长为：" << rectangle.calcPerimeter() << endl;

    return 0;
}