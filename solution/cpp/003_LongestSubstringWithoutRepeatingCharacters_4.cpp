
#include <iostream>
#include <cppUtils.h>
using namespace std;

                    
class Solution_003_LongestSubstringWithoutRepeatingCharacters_4 {
public:
    int lengthOfLongestSubstring(string s) {
        // we will store a senitel value of -1 to simulate 'null'/'None' in C++
        vector<int> chars(128, -1);

        int left = 0;
        int right = 0;

        int res = 0;
        while (right < s.length()) {
            char r = s[right];

            int index = chars[r];
            if (index != -1 and index >= left and index < right) {
                left = index + 1;
            }
            res = max(res, right - left + 1);

            chars[r] = right;
            right++;
        }
        return res;
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
                    