
#include <iostream>
#include <cppUtils.h>
using namespace std;

                    
class Solution_214_ShortestPalindrome_1 {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        string rev(s);
        reverse(rev.begin(), rev.end());
        for (int i = 0; i < n; i++) {
            if (s.substr(0, n - i) == rev.substr(i))
                return rev.substr(0, i) + s;
        }
        return "";
    }
};

int main() {
auto *so = new Solution_214_ShortestPalindrome_1();
vector<int> nums{2, 7, 11, 15};
int target = 26;
string s = "aa";
vector<vector<int>> arrays;
CppUtils::print(s);
CppUtils::print_1d_vector(nums);
CppUtils::print_2d_vector(arrays);
return 0;
}
                    