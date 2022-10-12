
#include <iostream>
#include <cppUtils.h>

using namespace std;

                    
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> word_set(wordDict.begin(), wordDict.end());
        return wordBreakRecur(s, word_set, 0);
    }

    bool wordBreakRecur(string& s, set<string>& word_set, int start) {
        if (start == s.length()) {
            return true;
        }
        for (int end = start + 1; end <= s.length(); end++) {
            if (word_set.find(s.substr(start, end - start)) != word_set.end() and
                wordBreakRecur(s, word_set, end)) {
                return true;
            }
        }
        return false;
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
                    