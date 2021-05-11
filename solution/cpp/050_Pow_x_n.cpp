#include <iostream>
#include <cppUtils.h>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) {
            n = -n;
            x = 1 / x;
        }
        return powUtil(x, n);
    }

private:
    double powUtil(double x, int n) {
        if (n == 0)
            return 1;
        return n % 2 == 0 ? powUtil(x * x, n / 2) : x * powUtil(x * x, n / 2);
    }
};

int main() {
    auto *so = new Solution();
    double x = 2.0;
    int n = -2;
    double res = so->myPow(x, n);
    CppUtils::print(res);
    delete so;
    return 0;
}

