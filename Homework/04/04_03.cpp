#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long double a, b;
    cin >> a >> b;
    cout << (floor)(log(b)/log(a)) << endl;

    return 0;
}
