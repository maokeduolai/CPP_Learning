#include <iostream>
#include <deque>
#include <string>
#include <sstream>

int main() {
    std::deque<int> queue;
    std::string command;

    std::cout << "请输入命令 ('push <num>', 'pop', 'print', 'exit'):" << std::endl;

    // 循环读取命令直到输入exit
    while (true) {
        std::getline(std::cin, command); // 读取整行作为命令

        // 使用字符串流解析命令和参数
        std::istringstream iss(command);
        std::string cmd;
        iss >> cmd;

        if (cmd == "push") {
            int num;
            if (iss >> num) {
                queue.push_back(num); // 将数字加入尾部
            } else {
                std::cerr << "命令无效，请输入 'push' 加数字" << std::endl;
            }
        } else if (cmd == "pop") {
            if (!queue.empty()) {
                queue.pop_front(); // 移除队列首部的元素
            } else {
                std::cerr << "队列为空，无法弹出元素" << std::endl;
            }
        } else if (cmd == "print") {
            for (int elem: queue) {
                std::cout << elem << " "; // 打印队列中的所有元素
            }
            std::cout << std::endl;
        } else if (cmd == "exit") {
            break;
        } else {
            std::cerr << "未识别的命令，可用命令：'push <num>', 'pop', 'print', 'exit'" << std::endl;
        }
    }

    return 0;
}
