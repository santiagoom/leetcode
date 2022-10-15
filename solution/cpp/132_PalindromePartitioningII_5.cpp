
#include <iostream>
#include <cppUtils.h>
using namespace std;

                    
class Solution_132_PalindromePartitioningII_5 {
public:
    int minCut(string s) {
        vector<int> cutsDp;
        vector<vector<bool>> palindromeDp;
        cutsDp.resize(s.length());
        palindromeDp.resize(s.length(), vector<bool>(s.length(), false));
        for (int end = 0; end < s.length(); end++) {
            int minimumCut = end;
            for (int start = 0; start <= end; start++) {
                // check if substring (start, end) is palidrome
                if (s[start] == s[end] &&
                    (end - start <= 2 || palindromeDp[start + 1][end - 1])) {
                    palindromeDp[start][end] = true;
                    minimumCut =
                        start == 0 ? 0 : min(minimumCut, cutsDp[start - 1] + 1);
                }
            }
            cutsDp[end] = minimumCut;
        }
        return cutsDp[s.length() - 1];
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
                    