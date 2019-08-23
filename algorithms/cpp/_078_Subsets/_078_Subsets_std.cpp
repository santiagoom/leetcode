#include <iostream>
#include <vector>

using namespace std;


/**
* This reference program is provided by @jiuzhang.com
* Copyright is reserved. Please indicate the source for forwarding
*/

class Solution {
private:
    void helper(vector<vector<int> > &results, vector<int> &subset, vector<int> &nums, int start) {
        results.push_back(subset);

        for (int i = start; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            helper(results, subset, nums, i + 1);
            subset.pop_back();
        }
    }

public:
    vector<vector<int> > subsets(vector<int> &nums) {
        vector<vector<int> > results;
        vector<int> subset;

        sort(nums.begin(), nums.end());
        helper(results, subset, nums, 0);

        return results;
    }
};


int main() {

    //    2019-08-22 15:52:17
    auto *so = new Solution();
    vector<int> nums{1, 2, 3};
    vector<vector<int>> res = so->subsets(nums);
    for (auto &list: res) {
        for (auto ele: list) {
            cout << ele;
        }
        cout << endl;
    }
    return 0;
}
