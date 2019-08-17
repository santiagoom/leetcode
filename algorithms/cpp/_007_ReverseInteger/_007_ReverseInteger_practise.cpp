#include <iostream>

using namespace std;

class Solution {
    /*
     * mainly deal range overflow and num update.
     * positive and negtive are all same
     * -24 / 10 = -4
     */
public:
    int reverse(int x) {
        int ret = 0;
        while (x != 0) {
            int remainder = x % 10;
            cout << remainder << endl;

            x /= 10;
            if (ret > INT32_MAX / 10 || (ret == INT32_MAX / 10 && remainder > 7)) return 0;
            if (ret < INT32_MIN / 10 || (ret == INT32_MIN / 10 && remainder < -8)) return 0;
            ret = ret * 10 + remainder;
            cout << ret << endl;

        }
        return ret;
    }
};


int main() {
//    2019-08-17 11:56:57
//2019-08-17 12:12:48
    int max = INT32_MAX;
    int min = INT32_MIN;
    auto *so = new Solution();
    int res = so->reverse(-24);
    cout << res << endl;
    return 0;
}
