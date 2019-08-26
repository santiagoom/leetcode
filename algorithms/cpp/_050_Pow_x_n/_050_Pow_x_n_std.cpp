#include <iostream>

using namespace std;


/**
* This reference program is provided by @jiuzhang.com
* Copyright is reserved. Please indicate the source for forwarding
*/

class Solution1 {
private:
    double _myPow(double x, long long n) {
        // 使用long long以避免 -2147483648 边界数据出错
        if (n == 0)
            return 1.0;
        double half = _myPow(x, n / 2);
        if (n % 2)
            return half * half * x;
        else
            return half * half;
    }
public:
    /**
     * @param x: the base number
     * @param n: the power number
     * @return: the result
     */
    double myPow(double x, int n) {
        return n < 0 ? 1.0 / _myPow(x, -n) : _myPow(x, n);
    }
};

////////////// 循环版本

class Solution2 {
private:
    double _myPow(double x, long long n) {
        double res = 1.0;
        for (double i = x; n; n /= 2, i *= i) {
            if (n % 2)
                res *= i;
        }
        return res;
    }
public:
    /**
     * @param x: the base number
     * @param n: the power number
     * @return: the result
     */
    double myPow(double x, int n) {
        return n < 0 ? 1.0 / _myPow(x, -n) : _myPow(x, n);
    }
};

int main() {
    auto *so = new Solution1();
    cout << "new file!" << endl;
    return 0;
}
