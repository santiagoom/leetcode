
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
vector<int> nums{2, 7, 11, 15};
int target = 26;
string s = "aa";
vector<vector<int>> arrays;
CppUtils::print(s);
CppUtils::print_1d_vector(nums);
CppUtils::print_2d_vector(arrays);
return 0;
}
                    