#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int num) {
    // 当 num 小于3时，仅有质数2、3
    if (num <= 3) {
        return num > 1;
    }

    // 判断该数是否为偶数，若为大于3的偶数则肯定不是质数
    // 再判断其能否被小于 sqrt(num) 的数整除
    // 时间复杂度减少到 O(sqrt(n)/2)
    int sqrt_num = (int) sqrt(num);
    for (int i = 3; i <= sqrt_num; i += 2) {
        if ((num % 2 == 0) || (num % i == 0)) {
            return false;
        }
    }

    return true;
}

int main() {
    cout << "200~300之间的质数有：" << endl;

    for (int i = 200; i <= 300; ++i) {
        if (isPrime(i)) {
            cout << i << endl;
        }
    }

    return 0;
}
