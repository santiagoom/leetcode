#include <iostream>
#include <vector>

using namespace std;

class Solution {

};

class Solution1 {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int> > permute(vector<int> nums) {
        // write your code here
        vector<vector<int> > ans;
        if (nums.size() == 0)
            return ans;
        sort(nums.begin(), nums.end());
        do {
            ans.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return ans;
    }
};

class Solution2 {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int> > permute(vector<int> nums) {
        // write your code here
        vector<vector<int>> results;
        if (nums.empty()) {
            results.push_back(vector<int>());
            return results;
        }
        sort(nums.begin(), nums.end());
        vector<int> visit(nums.size(), 0);
        vector<int> path;
        helper(nums, path, visit, results);
        return results;
    }

private:
    void helper(vector<int> &nums,
                vector<int> &path,
                vector<int> &visit,
                vector<vector<int>> &results) {
        if (path.size() == nums.size()) {
            results.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if ((i >= 1 && nums[i] == nums[i - 1] && visit[i - 1] == 0) || visit[i] == 1) {
                continue;
            }
            visit[i] = 1;
            path.push_back(nums[i]);
            helper(nums, path, visit, results);
            visit[i] = 0;
            path.pop_back();
        }
    }
};

int main() {
    auto *so = new Solution();
    cout << "new file!" << endl;
    return 0;
}
