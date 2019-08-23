#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> templist;
        vector<int> visit(nums.size(), 0);
        sort(nums.begin(), nums.end());
        backtracking(res, templist, nums, visit);
        return res;
    }

private:
//    visit[i - 1]  and !visit[i - 1] all works
    void backtracking(vector<vector<int>> &res, vector<int> templist, vector<int> &nums, vector<int> &visit) {
        if (nums.size() == templist.size())
            res.push_back(templist);
        else {
            for (int i = 0; i < nums.size(); i++) {
                if (visit[i] || (i > 0 && nums[i - 1] == nums[i] && visit[i - 1]))
                    continue;
                visit[i] = 1;
                templist.push_back(nums[i]);
                backtracking(res, templist, nums, visit);
                visit[i] = 0;
                templist.pop_back();
            }
        }
    }
};

int main() {
//    2019-08-22 20:14:39
//2019-08-22 20:34:10
    auto *so = new Solution();
    vector<int> nums{1, 2, 2};
    vector<vector<int>> res = so->permuteUnique(nums);
    for (auto &list: res) {
        for (auto ele: list) {
            cout << ele;
        }
        cout << endl;
    }
    delete so;
    return 0;
}
