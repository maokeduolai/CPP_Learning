#include <iostream>

using namespace std;

class Triangle {
private:
    double side_1, side_2, side_3;

public:
    // 构造函数初始化三条边的值
    explicit Triangle(double s1, double s2, double s3) : side_1(s1), side_2(s2), side_3(s3) {};

    // 成员函数判断三角形类型
    void classifyTriangle() const {
        if (side_1 == side_2 && side_2 == side_3) {
            cout << "这是一个等边三角形。" << endl;
        } else if (side_1 == side_2 || side_1 == side_3 || side_2 == side_3) {
            cout << "这是一个等腰三角形。" << endl;
        } else {
            cout << "这是一个不等边三角形。" << endl;
        }
    }
};

bool isTriangle(double a, double b, double c);

int main() {
    double s1, s2, s3;
    cout << "请输入三角形三边长，用空格分隔：";
    cin >> s1 >> s2 >> s3;

    while (not isTriangle(s1, s2, s3)) {
        cout << "三角形三边长度不合法，请重新输入：";
        cin >> s1 >> s2 >> s3;
    }

    // 创建对象并初始化三边长度
    Triangle triangle(s1, s2, s3);

    // 调用成员函数判断并输出结果
    triangle.classifyTriangle();

    return 0;
}

bool isTriangle(double a, double b, double c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}