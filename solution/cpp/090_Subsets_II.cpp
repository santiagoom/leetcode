#include <iostream>
#include <vector>
#include <cppUtils.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        backtracking(res, subset, nums, 0);
        return res;
    }

private:
    void backtracking(vector<vector<int>> &res, vector<int> &subset, vector<int> &nums, int start) {
        res.push_back(subset);
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i - 1] == nums[i]) {
                continue;
            }
            subset.push_back(nums[i]);
            backtracking(res, subset, nums, i + 1);
            subset.pop_back();
        }
    }
};

class Solution_p1 {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> curr;
        vector<int> visit(nums.size(), 0);
        backtracking(res, curr, visit, nums, 0);
        return res;
    }

    void backtracking(vector<vector<int>> &res, vector<int> &curr, vector<int> &visit, vector<int> &nums, int start) {
        res.push_back(curr);
        for (int i = start; i < nums.size(); ++i) {
//            if (visit[i] || (i > start && nums[i] == nums[i - 1] && visit[i - 1]))
//                continue;
            if (i > start && nums[i] == nums[i - 1])
                continue;
            curr.push_back(nums[i]);
            backtracking(res, curr, visit, nums, i + 1);
            curr.pop_back();
        }
    }
};

int main() {
    auto *so = new Solution();
//    auto *so = new Solution_p1();
    vector<int> nums{1, 2, 2};
    vector<vector<int>> res = so->subsetsWithDup(nums);
    CppUtils::print_2d_vector(res);
    return 0;
}

