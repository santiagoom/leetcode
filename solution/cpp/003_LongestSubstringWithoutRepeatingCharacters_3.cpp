
#include <iostream>
#include <cppUtils.h>

using namespace std;

                    
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = int(s.length()), res = 0;
        unordered_map<char, int> mp;

        for (int j = 0, i = 0; j < n; j++){
            if(mp[s[j]] > 0) {
                i = max(mp[s[j]], i);
            }
            res = max(res, j - i + 1);
            mp[s[j]] = j + 1;
        }
        return res;
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
                    