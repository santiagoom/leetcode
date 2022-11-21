
#include <iostream>
#include <cppUtils.h>
using namespace std;

                    
class Solution_214_ShortestPalindrome_2 {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        int i = 0;
        for (int j = n - 1; j >= 0; j--) {
            if (s[i] == s[j])
                i++;
        }
        if (i == n) {
            return s;
        }
        string remain_rev = s.substr(i, n);
        reverse(remain_rev.begin(), remain_rev.end());
        return remain_rev + shortestPalindrome(s.substr(0, i)) + s.substr(i);
    }
};

int main() {
    auto *so = new Solution_214_ShortestPalindrome_2();
//    string s = "abc";
    string s = "abccb";
    auto ret = so->shortestPalindrome(s);
    CppUtils::print(ret);
    return 0;
}
                    