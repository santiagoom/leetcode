#include <iostream>
#include <vector>
#include <map>
//#include "cppUtils.h"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            if (map.find(target - nums[i]) != map.end()) {
                return {map[target - nums[i]], i};
            } else {
                map[nums[i]] = i;
            }
        }
        return {-1, -1};
    }
};

int main() {
    vector<int> nums{2, 7, 11, 15};
//    int target = 26;
    int target = 9;
    auto *so = new Solution();
    vector<int> res = so->twoSum(nums, target);
//    CppUtils::print_1d_vector(res);
    for (int &x:res)
        cout << x << " ";
    cout << endl;
    delete so;
    return 0;
};