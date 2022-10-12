
#include <iostream>
#include <cppUtils.h>

using namespace std;

                    
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();

        // Sort the generated subset. This will help to identify duplicates.
        sort(nums.begin(), nums.end());
        vector<vector<int>> subsets;

        int maxNumberOfSubsets = pow(2, n);
        // To store the previously seen sets.
        unordered_set<string> seen;

        for (int subsetIndex = 0; subsetIndex < maxNumberOfSubsets; subsetIndex++) {
            // Append subset corresponding to that bitmask.
            vector<int> currentSubset;
            string hashcode = "";
            for (int j = 0; j < n; j++) {
                // Generate the bitmask
                int mask = 1 << j;
                int isSet = mask & subsetIndex;
                if (isSet != 0) {
                    currentSubset.push_back(nums[j]);
                    // Generate the hashcode by creating a comma separated string of numbers in the currentSubset.
                    hashcode.append(to_string(nums[j]) + ",");
                }
            }

            if (seen.find(hashcode) == seen.end()) {
                subsets.push_back(currentSubset);
                seen.insert(hashcode);
            }
        }

        return subsets;
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
                    