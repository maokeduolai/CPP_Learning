#include <iostream>
#include <vector>
#include <algorithm>

void uniqueSort(std::vector<int> &vec);

int main() {
    std::vector<int> numbers;
    int input;

    std::cout << "请输入一系列整数（输入'-1'结束输入）：";
    while ((std::cin >> input) && (input != -1)) {
        numbers.push_back(input);
    }

    // 去除重复元素并排序
    uniqueSort(numbers);

    // 打印处理后的容器元素
    for (int num: numbers) {
        std::cout << num << ' ';
    }
    std::cout << std::endl;

    return 0;
}

void uniqueSort(std::vector<int> &vec) {
    // 排序
    std::sort(vec.begin(), vec.end());

    // 去除重复元素，迭代器last指向容器中不重复的序列的末尾
    auto last = std::unique(vec.begin(), vec.end());

    // 重设容器大小，移除末尾重复的元素
    vec.erase(last, vec.end());
}
