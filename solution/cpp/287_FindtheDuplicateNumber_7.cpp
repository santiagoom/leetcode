
#include <iostream>
#include <cppUtils.h>
using namespace std;

                    
class Solution_287_FindtheDuplicateNumber_7 {
public:
    
    // Find the position of the Most Significant Bit in num
    int calcMaxBit(int num) {
        int bits = 0;
        while (num > 0) {
            num /= 2;
            bits++;
        }
        return bits;
    }
    
    int findDuplicate(vector<int>& nums) {
        int duplicate = 0;
        int n = nums.size() - 1;
        int max_num = *max_element(nums.begin(), nums.end());
        int max_bit = calcMaxBit(max_num);
        
        // Iterate over each bit
        for (int bit = 0; bit < max_bit; bit++) {
            int mask = (1 << bit);
            int base_count = 0, nums_count = 0;
            
            for (int i = 0; i <= n; i++) {
                // If bit is set in number (i) then add 1 to base_count
                if (i & mask) {
                    base_count++;
                }
                // If bit is set in nums[i] then add 1 to nums_count
                if (nums[i] & mask) {
                    nums_count++;
                }
            }
            
            // If the current bit is more frequently set in nums than it is in 
            // the range [1, 2, ..., n] then it must also be set in the duplicate number
            if (nums_count > base_count) {
                duplicate |= mask;
            }
        }
        return duplicate;
    }
};

int main() {
auto *so = new Solution_287_FindtheDuplicateNumber_7();
vector<int> nums{2, 7, 11, 15};
int target = 26;
string s = "aa";
vector<vector<int>> arrays;
CppUtils::print(s);
CppUtils::print_1d_vector(nums);
CppUtils::print_2d_vector(arrays);
return 0;
}
                    