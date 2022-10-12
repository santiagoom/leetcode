
#include <iostream>
#include <cppUtils.h>

using namespace std;

                    
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> currentSubset;
        sort(nums.begin(), nums.end());
        subsetsWithDupHelper(subsets, currentSubset, nums, 0);
        return subsets;
    }

private:
    void subsetsWithDupHelper(vector<vector<int>>& subsets, vector<int>& currentSubset, vector<int>& nums, int index) {
        // Add the subset formed so far to the subsets list.
        subsets.push_back(currentSubset);

        for (int i = index; i < nums.size(); i++) {
            // If the current element is a duplicate, ignore.
            if (i != index && nums[i] == nums[i - 1]) {
                continue;
            }
            currentSubset.push_back(nums[i]);
            subsetsWithDupHelper(subsets, currentSubset, nums, i + 1);
            currentSubset.pop_back();
        }
    }
};

                    
int main() {
    vector<int> nums{2, 7, 11, 15};
    int target = 26;
    string s = "aa";
    auto *so = new Solution();
    vector<vector<int>> arrays;
    CppUtils::print(s);
    CppUtils::print_1d_vector(nums);
    CppUtils::print_2d_vector(arrays);
    delete so;
    return 0;
}
                    