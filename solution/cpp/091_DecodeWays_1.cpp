
#include <iostream>
#include <cppUtils.h>

using namespace std;

                    
class Solution {
public:
    map<int, int> memo;

    int recursiveWithMemo(int index, string& str) {
        // Have we already seen this substring?
        if (memo.find(index) != memo.end()) {
            return memo[index];
        }

        // If you reach the end of the string
        // Return 1 for success.
        if (index == str.length()) {
            return 1;
        }

        // If the string starts with a zero, it can't be decoded
        if (str[index] == '0') {
            return 0;
        }

        if (index == str.length() - 1) {
            return 1;
        }

        int ans = recursiveWithMemo(index + 1, str);
        if (stoi(str.substr(index, 2)) <= 26) {
            ans += recursiveWithMemo(index + 2, str);
        }

        // Save for memoization
        memo[index] = ans;

        return ans;
    }

    int numDecodings(string s) {
        return recursiveWithMemo(0, s);
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
                    