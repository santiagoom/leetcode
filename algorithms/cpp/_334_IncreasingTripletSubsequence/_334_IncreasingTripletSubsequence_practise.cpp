#include <iostream>
#include <vector>

using namespace std;

class Solution {
//    vector<int> records(2, INT_MAX)  !=  vector<int> records{2, INT_MAX};
public:
    bool increasingTriplet(vector<int> &nums) {
        if (nums.size() < 3)
            return false;
        vector<int> records(2, INT_MAX);
        for (int &num:nums) {
            if (num <= records[0]) {
                records[0] = num;
            } else if (num <= records[1]) {
                records[1] = num;
            } else {
                return true;
            }
        }
        return false;
    }
};

int main() {
    auto *so = new Solution();
    vector<int> nums{2147483646, 2147483647, 2147483647};
    bool res = so->increasingTriplet(nums);
    cout << res << endl;
    delete so;
    return 0;
}
