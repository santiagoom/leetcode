
#include <iostream>
#include <cppUtils.h>

using namespace std;


class Solution_029_DivideTwoIntegers_1 {
public:
    int divide(int dividend, int divisor) {

        // Special case: overflow.
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        /* We need to convert both numbers to negatives
         * for the reasons explained above.
         * Also, we count the number of negatives signs. */
        int negatives = 2;
        if (dividend > 0) {
            negatives--;
            dividend = -dividend;
        }
        if (divisor > 0) {
            negatives--;
            divisor = -divisor;
        }

        /* Count how many times the divisor has to be added
         * to get the dividend. This is the quotient. */
        int quotient = 0;
        while (dividend - divisor <= 0) {
            dividend -= divisor;
            quotient--;
        }

        /* If there was originally one negative sign, then
         * the quotient remains negative. Otherwise, switch
         * it to positive. */
        if (negatives != 1) {
            return -quotient;
        }
        return quotient;
    }
}

int main() {
    vector<int> nums{2, 7, 11, 15};
    int target = 26;
    string s = "aa";
    vector<vector<int>> arrays;
    CppUtils::print(s);
    CppUtils::print_1d_vector(nums);
    CppUtils::print_2d_vector(arrays);
    return 0;
}
                    