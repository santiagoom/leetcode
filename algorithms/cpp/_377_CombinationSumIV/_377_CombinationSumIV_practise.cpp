#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum4(vector<int> &nums, int target) {
        vector<vector<int>> res;
        vector<int> templist;
        int count = 0;
        sort(nums.begin(), nums.end());
        backtracking(res, templist, count, nums, target);
        return res;
    }

private:
    void backtracking(vector<vector<int>> &res, vector<int> &templist, int &count, vector<int> &nums, int target) {
        if (target < 0)
            return;
        else if (target == 0) {
            count++;
            res.push_back(templist);
        } else {
            for (int i = 0; i < nums.size(); i++) {
                templist.push_back(nums[i]);
                backtracking(res, templist, count, nums, target - nums[i]);
                templist.pop_back();
            }
        }
    }
};

int main() {
    auto *so = new Solution();
    vector<int> nums{1, 2, 4};
    int target = 7;
    vector<vector<int>> res = so->combinationSum4(nums, target);
    for (auto &list: res) {
        for (auto ele: list) {
            cout << ele;
        }
        cout << endl;
    }
    delete so;
    return 0;
}
