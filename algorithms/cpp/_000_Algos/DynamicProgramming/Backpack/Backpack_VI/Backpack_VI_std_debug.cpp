#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int> &nums, int target) {
//        通过 i - nums[j] >= 0 过滤条件
//      if i = 3,
//      when nums[j] = 1, f[3] = f[2] , f[3] = 1 + 2
//      when nums[j] = 2, f[3] = f[1] , f[3] = 2 + 1
//
//
        int n = nums.size();
        unsigned long f[target + 1];
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < n; j++) {

                if (i - nums[j] >= 0) {
                    f[i] += f[i - nums[j]];
                    cout << "i:" << i << " " << nums[j] << " f[i]:" << f[i] << endl;

                }
                for (int k = 0; k < sizeof(f) / sizeof(long); k++) {
                    cout << f[k] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
        return f[target];
    }
};

int main() {
    auto *so = new Solution();
    vector<int> nums{1, 2, 4};
    int target = 4;
    int res = so->combinationSum4(nums, target);
    cout << res << endl;
    delete so;
    return 0;
}
