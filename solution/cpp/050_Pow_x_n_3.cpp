
#include <iostream>
#include <cppUtils.h>

using namespace std;


class Solution_050_Pow_x_n_3 {
public:
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        double ans = 1;
        double current_product = x;
        for (long long i = N; i; i /= 2) {
            if ((i % 2) == 1) {
                ans = ans * current_product;
            }
            current_product = current_product * current_product;
        }
        return ans;
    }
};

int main() {
    double  x = 2;
    int n = 3;
    auto *so = new Solution_050_Pow_x_n_3();
    double res = so->myPow(x,n);
    CppUtils::print(res);
    return 0;
}
                    