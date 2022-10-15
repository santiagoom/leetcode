
#include <iostream>
#include <cppUtils.h>
using namespace std;

                    
class Solution_026_RemoveDuplicatesfromSortedArray_1 {
public:
    int removeDuplicates(vector<int>& nums) {
        int insertIndex = 1;
        for(int i = 1; i < nums.size(); i++){
            // We skip to next index if we see a duplicate element
            if(nums[i - 1] != nums[i]) {    
                // Storing the unique element at insertIndex index and incrementing the insertIndex by 1 
                nums[insertIndex] = nums[i];     
                insertIndex++;
            }
        }
        return insertIndex;
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
                    