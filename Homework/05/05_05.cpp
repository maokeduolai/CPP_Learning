#include <iostream>
#include <cmath>

using namespace std;

class Shape {
public:
    // 虚函数，计算面积
    [[nodiscard]] virtual double calcArea() const = 0;

    // 虚函数，计算周长
    [[nodiscard]] virtual double calcPerimeter() const = 0;

    // 虚析构函数，释放资源
    virtual ~Shape() = default;
};

class Circle : public Shape {
private:
    double radius;

public:
    // 构造函数初始化圆半径
    explicit Circle(double r) : radius(r) {}

    // 重写基类虚函数，计算面积
    [[nodiscard]] double calcArea() const override {
        return M_PI * radius * radius;
    }

    // 重写基类虚函数，计算周长
    [[nodiscard]] double calcPerimeter() const override {
        return 2 * M_PI * radius;
    }
};

class Rectangle : public Shape {
private:
    double length, width;

public:
    // 构造函数初始化矩形长宽
    explicit Rectangle(double initLen, double initWid) : length(initLen), width(initWid) {}

    // 重写基类虚函数，计算矩形面积
    [[nodiscard]] double calcArea() const override {
        return length * width;
    }

    // 重写基类虚函数，计算矩形周长
    [[nodiscard]] double calcPerimeter() const override {
        return 2 * (length + width);
    }
};

class Triangle : public Shape {
private:
    double side_1, side_2, side_3;

public:
    // 构造函数初始化三角形边长
    Triangle(double s1, double s2, double s3) : side_1(s1), side_2(s2), side_3(s3) {}

    // 重写基类虚函数，计算三角形的面积
    [[nodiscard]] double calcArea() const override {
        double s = (side_1 + side_2 + side_3) / 2.0;
        return sqrt(s * (s - side_1) * (s - side_2) * (s - side_3));
    }

    // 重写基类虚函数，计算三角形的周长
    [[nodiscard]] double calcPerimeter() const override {
        return side_1 + side_2 + side_3;
    }
};

int main() {
    Circle circle(6.0);
    cout << "圆的面积为：" << circle.calcArea() << endl;
    cout << "圆的周长为：" << circle.calcPerimeter() << endl;

    Rectangle rectangle(8.0, 6.0);
    cout << endl << "矩形的面积为：" << rectangle.calcArea() << endl;
    cout << "矩形的周长为：" << rectangle.calcPerimeter() << endl;

    Triangle triangle(3.0, 4.0, 5.0);
    cout << endl << "三角形的面积为：" << triangle.calcArea() << endl;
    cout << "三角形的周长为：" << triangle.calcPerimeter() << endl;

    return 0;
}
