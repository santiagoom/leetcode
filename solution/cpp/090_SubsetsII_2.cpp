
#include <iostream>
#include <cppUtils.h>
using namespace std;

                    
class Solution_090_SubsetsII_2 {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subsets = {{}};

        int subsetSize = 0;

        for (int i = 0; i < nums.size(); i++) {
            int startingIndex = (i >= 1 && nums[i] == nums[i - 1]) ? subsetSize : 0;
            // subsetSize refers to the size of the subset in the previous step. This value also indicates the starting index of the subsets generated in this step.
            subsetSize = subsets.size();
            for (int j = startingIndex; j < subsetSize; j++) {
                vector<int> currentSubset = subsets[j];
                currentSubset.push_back(nums[i]);
                subsets.push_back(currentSubset);
            }
        }
        return subsets;
    }
};

int main() {
vector<int> nums{2, 7, 11, 15};
int target = 26;
string s = "aa";
vector<vector<int>> arrays;
CppUtils::print(s);
CppUtils::print_1d_vector(nums);
CppUtils::print_2d_vector(arrays);
return 0;
}
                    