
#include <iostream>
#include <cppUtils.h>

using namespace std;

                    
class Solution {
public:
    int minCut(string s) {
        vector<int> cutsDp;
        cutsDp.resize(s.length());
        for (int i = 1; i < s.length(); i++) {
            cutsDp[i] = i;
        }
        for (int mid = 0; mid < s.length(); mid++) {
            // check for odd length palindrome around mid index
            findMinimumCuts(mid, mid, cutsDp, s);
            // check for even length palindrome around mid index
            findMinimumCuts(mid - 1, mid, cutsDp, s);
        }
        return cutsDp[s.length() - 1];
    }

    void findMinimumCuts(int startIndex, int endIndex, vector<int> &cutsDp,
                         string s) {
        for (int start = startIndex, end = endIndex;
             start >= 0 && end < s.length() && s[start] == s[end];
             start--, end++) {
            int newCut = start == 0 ? 0 : cutsDp[start - 1] + 1;
            cutsDp[end] = min(cutsDp[end], newCut);
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
                    