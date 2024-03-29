#include <iostream>
#include <vector>
#include <cppUtils.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        backtracking(res, subset, nums);
        return res;
    }

private:
    void backtracking(vector<vector<int>> &res, vector<int> &subset, vector<int> &nums) {
        if (subset.size() == nums.size())
            res.push_back(subset);

        for (int i = 0; i < nums.size(); i++) {
            if (find(subset.begin(), subset.end(), nums[i]) != subset.end())
                continue;
            subset.push_back(nums[i]);
            backtracking(res, subset, nums);
            subset.pop_back();
        }
    }
};


class Solution_p1 {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int >> res;
        vector<int> curr;
        backtrackting(res, curr, nums);
        return res;
    }

    void backtrackting(vector<vector<int>> &res, vector<int> &curr, vector<int> &nums) {
        if (curr.size() == nums.size())
            res.push_back(curr);
        else {
            for (int i = 0; i < nums.size(); ++i) {
                if (find(curr.begin(), curr.end(), nums[i]) != curr.end())
                    continue;
                curr.push_back(nums[i]);
                backtrackting(res, curr, nums);
                curr.pop_back();
            }
        }
    }

};

int main() {
//    auto *so = new Solution();
    auto *so = new Solution_p1();
    vector<int> nums{1, 2, 3};
    vector<vector<int>> res = so->permute(nums);
    CppUtils::print_2d_vector(res);
    delete so;
    return 0;
}
