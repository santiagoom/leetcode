
#include <iostream>
#include <cppUtils.h>
using namespace std;

                    
class Solution_159_LongestSubstringwithAtMostTwoDistinctCharacters_1 {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        size_t n = s.length();
        if (n < 3) {
            return n;
        }

        // sliding window left and right pointers
        int left = 0, right = 0;
        // hashmap character -> its rightmost position
        // in the sliding window
        map<char, int> hashmap;

        int max_len = 2;

        while (right < n) {
            // when the sliding window contains less than 3 characters
            hashmap[s[right]] = right;
            right++;

            // slidewindow contains 3 characters
            if (hashmap.size() == 3) {
                int del_idx = INT_MAX;
                for (pair<char, int> element : hashmap) {
                    del_idx = min(del_idx, element.second);
                }
                // delete the leftmost character
                hashmap.erase(s[del_idx]);
                left = del_idx + 1;
            }
            max_len = max(max_len, right - left);
        }
        return max_len;
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
                    