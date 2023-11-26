#include <iostream>
#include <string>
#include <utility>

using namespace std;

class Student {
private:
    string name, className, number;
    double score;

    // 使用静态变量统计对象个数
    static int count;

public:
    // 构造函数初始化学生变量
    Student(string stuName, string stuClass, string stuNum, double stuScore) : name(
            std::move(stuName)), // 编译器提示，使用move传递所有权，避免拷贝开销
                                                                               className(std::move(stuClass)),
                                                                               number(std::move(stuNum)),
                                                                               score(stuScore) {
        // 每创建一个对象，计数器加一
        count++;
    };

    // 成员函数显示学生信息和成绩
    void display() const {
        cout << "姓名：" << name << endl;
        cout << "班级：" << className << endl;
        cout << "学号：" << number << endl;
        cout << "分数：" << score << endl;

        // 根据分数分段输出成绩
        if (score >= 90) {
            cout << "成绩: A" << endl;
        } else if (score >= 80) {
            cout << "成绩: B" << endl;
        } else if (score >= 60) {
            cout << "成绩: C" << endl;
        } else {
            cout << "成绩: D" << endl;
        }

    }

    // 静态成员函数返回对象总数
    static int getCount() {
        return count;
    }
};

// 初始化统计对象个数的静态变量
int Student::count = 0;

int main() {
    // 创建对象
    Student student_1("王一一", "A班", "220101", 91.3);
    Student student_2("李二二", "B班", "220201", 76.8);

    // 显示学生信息
    student_1.display();
    cout << endl;
    student_2.display();

    // 输出对象总数
    cout << endl << "总共有" << Student::getCount() << "位学生" << endl;

    return 0;
}