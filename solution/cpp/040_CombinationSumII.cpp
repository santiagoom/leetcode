#include <iostream>
#include <vector>
#include <cppUtils.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &nums, int target) {
        vector<vector<int>> res;
        vector<int> templist;
        sort(nums.begin(), nums.end());
        backtracking(res, templist, nums, target, 0);
        return res;
    }

private:
    void
    backtracking(vector<vector<int>> &res, vector<int> &templist, vector<int> &nums, int target,
                 int start) {
        if (target < 0)
            return;
        else if (target == 0)
            res.push_back(templist);
        else {
            for (int i = start; i < nums.size(); i++) {
                if (i > start && nums[i - 1] == nums[i]) {
                    continue;
                }
                templist.push_back(nums[i]);
                backtracking(res, templist, nums, target - nums[i], i + 1);
                templist.pop_back();
            }
        }
    }
};

class Solution_p1 {
public:
    vector<vector<int>> combinationSum2(vector<int> &nums, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        backtracking(res, curr, nums, target, 0);
        return res;
    }

    void backtracking(vector<vector<int>> &res, vector<int> &curr, vector<int> &nums, int target, int start) {
        if (target < 0)
            return;
        else if (target == 0)
            res.push_back(curr);
        else {
            for (int i = start; i < nums.size(); ++i) {
                if (i > start && nums[i - 1] == nums[i])
                    continue;
                curr.push_back(nums[i]);
                backtracking(res, curr, nums, target - nums[i], i);
                curr.pop_back();
            }
        }
    }
};

int main() {
//    auto *so = new Solution();
    auto *so = new Solution_p1();
//    vector<int> nums{10, 1, 2, 7, 6, 1, 5};
//    int target = 8;
    vector<int> nums{2, 5, 2, 1, 1, 2};
    int target = 5;
    vector<vector<int>> res = so->combinationSum2(nums, target);
    CppUtils::print_2d_vector(res);
    delete so;
    return 0;
}

