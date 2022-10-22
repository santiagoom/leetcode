
#include <iostream>
#include <cppUtils.h>

using namespace std;


class Solution_091_DecodeWays_3 {
public:
    int numDecodings(string s) {
        if (s[0] == '0') {
            return 0;
        }

        size_t n = s.length();
        int two_back = 1;
        int one_back = 1;

        for (size_t i = 1; i < n; i++) {
            int current = 0;
            if (s[i] != '0') {
                current = one_back;
            }
            int two_digit = stoi(s.substr(i - 1, 2));
            if (two_digit >= 10 and two_digit <= 26) {
                current += two_back;
            }

            two_back = one_back;
            one_back = current;
        }
        return one_back;
    }
};

int main() {
//    string s = "226";
    string s = "12";
    auto* so  = new Solution_091_DecodeWays_3();
    int res = so->numDecodings(s);
    CppUtils::print(res);
    return 0;
}
                    