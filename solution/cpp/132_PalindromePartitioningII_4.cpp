
#include <iostream>
#include <cppUtils.h>

using namespace std;

                    
class Solution {
public:
    vector<int> cutsDp;
    vector<vector<bool>> palindromeDp;
    
    int minCut(string s) {
        cutsDp.resize(s.length());
        palindromeDp.resize(s.length(), vector<bool>(s.length(), false));
        // build the palindrome cutsDp for all susbtrings
        buildPalindromeDp(s, s.length());
        for (int end = 0; end < s.length(); end++) {
            int minimumCut = end;
            for (int start = 0; start <= end; start++) {
                if (palindromeDp[start][end]) {
                    minimumCut =
                        start == 0 ? 0 : min(minimumCut, cutsDp[start - 1] + 1);
                }
            }
            cutsDp[end] = minimumCut;
        }
        return cutsDp[s.length() - 1];
    }

    void buildPalindromeDp(string &s, int n) {
        for (int end = 0; end < s.length(); end++) {
            for (int start = 0; start <= end; start++) {
                if (s[start] == s[end] &&
                    (end - start <= 2 || palindromeDp[start + 1][end - 1])) {
                    palindromeDp[start][end] = true;
                }
            }
        }
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
                    