
#include <iostream>
#include <cppUtils.h>
using namespace std;

                    
class Solution_287_FindtheDuplicateNumber_2 {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (auto &num : nums) {
            if (seen.count(num))
                return num;
            seen.insert(num);
        }
        return -1;
    }
};

int main() {
auto *so = new Solution_287_FindtheDuplicateNumber_2();
vector<int> nums{2, 7, 11, 15};
int target = 26;
string s = "aa";
vector<vector<int>> arrays;
CppUtils::print(s);
CppUtils::print_1d_vector(nums);
CppUtils::print_2d_vector(arrays);
return 0;
}
                    