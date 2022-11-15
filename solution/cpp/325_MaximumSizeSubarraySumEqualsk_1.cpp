
#include <iostream>
#include <cppUtils.h>
using namespace std;

                    
class Solution_325_MaximumSizeSubarraySumEqualsk_1 {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int prefixSum = 0;
        int longestSubarray = 0;
        unordered_map<int, int> indices;
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];

            // Check if all of the numbers seen so far sum to k.
            if (prefixSum == k) {
                longestSubarray = i + 1;
            }
            
            // If any subarray seen so far sums to k, then
            // update the length of the longest_subarray. 
            if (indices.find(prefixSum - k) != indices.end()) {
                longestSubarray = max(longestSubarray, i - indices[prefixSum - k]);
            }

            // Only add the current prefix_sum index pair to the 
            // map if the prefix_sum is not already in the map.
            if (indices.find(prefixSum) == indices.end()) {
                indices[prefixSum] = i;
            }
        }
        
        return longestSubarray;
    }
};

int main() {
auto *so = new Solution_325_MaximumSizeSubarraySumEqualsk_1();
vector<int> nums{2, 7, 11, 15};
int target = 26;
string s = "aa";
vector<vector<int>> arrays;
CppUtils::print(s);
CppUtils::print_1d_vector(nums);
CppUtils::print_2d_vector(arrays);
return 0;
}
                    