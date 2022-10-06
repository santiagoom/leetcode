#include <iostream>
#include <vector>
#include <cppUtils.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &nums, int target) {
        vector<vector<int>> res;
        vector<int> templist;
        sort(nums.begin(), nums.end());
        backtracking(res, templist, nums, target, 0);
        return res;
    }

private:
    void backtracking(vector<vector<int>> &res, vector<int> &templist, vector<int> &nums, int target, int start) {
        if (target < 0)
            return;
        else if (target == 0)
            res.push_back(templist);
        else {
            for (int i = start; i < nums.size(); i++) {
                templist.push_back(nums[i]);
                backtracking(res, templist, nums, target - nums[i], i);
                templist.pop_back();
            }
        }
    }
};


class Solution_p1 {
public:
    vector<vector<int>> combinationSum(vector<int> &nums, int target) {
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
    vector<int> nums{2, 2, 3, 4, 5, 7};
    int target = 7;
    vector<vector<int>> res = so->combinationSum(nums, target);
    CppUtils::print_2d_vector(res);
    delete so;
    return 0;
}

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                