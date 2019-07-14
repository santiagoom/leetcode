#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (m.find(complement) != m.end()) {
                return vector<int>{(*m.find(complement)).second, i};
            }
            m.insert({nums[i], i});
        }
        return vector<int>{-1, -1};
    }
};

int main() {
    vector<int> nums{2, 7, 11, 15};
    int target = 26;

    auto *so = new Solution();
    vector<int> res = so->twoSum(nums, target);

    for (int x : res)
        cout << x << " ";
    return 0;
}