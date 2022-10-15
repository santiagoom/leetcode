
#include <iostream>
#include <cppUtils.h>
using namespace std;

                    
class Solution_029_DivideTwoIntegers_2 {
public:
int HALF_INT_MIN = -1073741824;

int divide(int dividend, int divisor) {

    // Special case: overflow.
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }

    /* We need to convert both numbers to negatives.
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

    int quotient = 0;
    /* Once the divisor is bigger than the current dividend,
     * we can't fit any more copies of the divisor into it. */
    while (divisor >= dividend) {
        /* We know it'll fit at least once as divivend >= divisor.
         * Note: We use a negative powerOfTwo as it's possible we might have
         * the case divide(INT_MIN, -1). */
        int powerOfTwo = -1;
        int value = divisor;
        /* Check if double the current value is too big. If not, continue doubling.
        * If it is too big, stop doubling and continue with the next step */
        while (value >= HALF_INT_MIN && value + value >= dividend) {
            value += value;
            powerOfTwo += powerOfTwo;
        }
        // We have been able to subtract divisor another powerOfTwo times.
        quotient += powerOfTwo;
        // Remove value so far so that we can continue the process with remainder.
        dividend -= value;
    }

    /* If there was originally one negative sign, then
     * the quotient remains negative. Otherwise, switch
     * it to positive. */
    if (negatives != 1) {
        quotient = -quotient;
    }
    return quotient;
}}

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
                    