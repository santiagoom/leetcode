
#include <iostream>
#include <cppUtils.h>
using namespace std;

                    
class Solution_016_3SumClosest_1 {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX;
        int sz = nums.size();
        sort(begin(nums), end(nums));
        for (int i = 0; i < sz && diff != 0; ++i) {
            int lo = i + 1;
            int hi = sz - 1;
            while (lo < hi) {
                int sum = nums[i] + nums[lo] + nums[hi];
                if (abs(target - sum) < abs(diff)) {
                    diff = target - sum;
                }
                if (sum < target) {
                    ++lo;
                } else {
                    --hi;
                }
            }
        }
        return target - diff;
    }
};

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
                    