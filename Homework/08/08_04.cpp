#include <iostream>
#include <forward_list>

template<typename T>
void filterList(std::forward_list<T> &flist, T threshold);

int main() {
    std::forward_list<int> numbers;
    int threshold;
    int input;

    std::cout << "请输入一系列整数（输入'-1'结束输入）：";
    while ((std::cin >> input) && (input != -1)) {
        numbers.push_front(input);
    }

    // 获取阈值
    std::cout << "请输入阈值：";
    std::cin >> threshold;

    // 过滤链表中小于阈值的元素
    filterList(numbers, threshold);

    // 打印处理后的链表
    std::cout << "过滤后的链表为：";
    for (int num: numbers) {
        std::cout << num << ' ';
    }
    std::cout << std::endl;

    return 0;
}

template<typename T>
void filterList(std::forward_list<T> &flist, T threshold) {
    // 移除小于阈值的所有数
    flist.remove_if([threshold](const T &value) {
        return value < threshold;
    });
}
