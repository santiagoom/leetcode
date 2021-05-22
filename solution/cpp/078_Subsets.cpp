#include <iostream>
#include <vector>
#include <cppUtils.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> subset;
        backtracking(res, subset, nums, 0);
        return res;
    }

private:
    void backtracking(vector<vector<int>> &res, vector<int> &subset, vector<int> &nums, int start) {
        res.push_back(subset);
        for (int i = start; i < nums.size(); i++) {
            subset.push_back(nums[i]);
            backtracking(res, subset, nums, i + 1);
            subset.pop_back();
        }
    }
};

class Solution_p1 {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> curr;
        backtracking(res, curr, nums, 0);
        return res;
    }

    void backtracking(vector<vector<int>> &res, vector<int> &curr, vector<int> &nums, int start) {
        res.push_back(curr);
        for (int i = start; i < nums.size(); ++i) {
            curr.push_back(nums[i]);
            backtracking(res, curr, nums, i + 1);
            curr.pop_back();
        }
    }

};

int main() {
//    auto *so = new Solution();
    auto *so = new Solution_p1();
    vector<int> nums{1, 2, 3};
    vector<vector<int>> res = so->subsets(nums);
    CppUtils::print_2d_vector(res);
    return 0;
}


