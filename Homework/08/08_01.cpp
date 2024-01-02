#include <iostream>
#include <list>

int main() {
    std::list<int> numbers;
    int input;

    std::cout << "请输入一系列整数（输入'-1'结束输入）：";

    // 读取整数并添加到链表中
    while ((std::cin >> input) && (input != -1)) {
        numbers.push_back(input);
    }

    // 检查链表中至少有两个元素才能删除
    if (numbers.size() >= 2) {
        // 删除第一个元素
        numbers.pop_front();
        // 删除最后一个元素
        numbers.pop_back();
    } else {
        std::cerr << "列表中的元素不足以删除第一个和最后一个元素!" << std::endl;
        return 1;
    }

    // 打印剩余的链表
    std::cout << "删除第一个和最后一个元素后的链表: ";
    for (int n: numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}
