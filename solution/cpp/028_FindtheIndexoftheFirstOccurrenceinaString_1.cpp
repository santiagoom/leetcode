
#include <iostream>
#include <cppUtils.h>

using namespace std;


class Solution_028_FindtheIndexoftheFirstOccurrenceinaString_1 {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() == 0)
            return 0;

        for (int i = 0;; i++) {
            for (int j = 0;; j++) {
                if (needle.length() == j)
                    return i;
                if (haystack.length() < i + j)
                    return -1;
                if (needle[j] != haystack[i + j])
                    break;
            }
        }
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
                    