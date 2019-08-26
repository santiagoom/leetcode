#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        // write your code here
        if (0 == x) {
            return 0;
        }
        int left = 1;
        int right = x / 2 + 1;
        while (left + 1 < right) {
            long long mid = left + (right - left) / 2;
            long long multiply = mid * mid;
            //cout << multiply << " " << left << " " << right << endl;
            if (multiply == x) {
                return mid;
            }
            if (multiply > x) {
                right = mid;
            } else {
                left = mid;
            }
        }
        if ((long long) (right) * right < x) {
            return right;
        }
        return left;
    }
};

int main() {
    auto *so = new Solution();
    cout << "new file!" << endl;
    return 0;
}
