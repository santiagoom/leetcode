#include <iostream>
#include <vector>
#include <cppUtils.h>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int> &nums, int target) {
        int n = nums.size();
//        unsigned long f[target + 1];
        vector<int> f(target + 1, 0);
//        memset(f, 0, sizeof(f));

        f[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < n; j++) {
                if (i - nums[j] >= 0) {
                    f[i] += f[i - nums[j]];
                }
                CppUtils::print_1d_vector(f);
            }
            CppUtils::print_1d_vector(f);
            CppUtils::print();
        }


        return f[target];
    }
};

int main() {
    auto *so = new Solution();
//    vector<int> nums{3, 33, 333};
    vector<int> nums{1, 2, 3};
    int target = 4;
    int res = so->combinationSum4(nums, target);
    CppUtils::print(res);
    delete so;
    return 0;
}