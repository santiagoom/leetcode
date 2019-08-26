#include <iostream>

using namespace std;


class Solution {
public:
    /**
     * @param dividend: the dividend
     * @param divisor: the divisor
     * @return: the result
     */
    int divide(int dividend, int divisor) {
        // write your code here
        if (divisor == 0) {
            return INT_MAX;
        }

        if (dividend == 0) {
            return 0;
        }

        long a = abs(long(dividend));
        long b = abs(long(divisor));

        long ans = 0;
        long shift = 31;

        // 中心思想，判断除数中包含有多少个被除数，用1的移位进行二进制累加
        while (a >= b) {
            if (a >= (b << shift)) {
                a -= (b << shift);
                ans += (1L << shift);
            }
            --shift;
        }

        // 异或移位判断符号
        ans = ((dividend ^ divisor) >> 31) ? -ans : ans;

        if (ans > INT_MAX) {
            return INT_MAX;
        } else {
            return ans;
        }
    }
};

int main() {
    auto *so = new Solution();
    cout << "new file!" << endl;
    return 0;
}
