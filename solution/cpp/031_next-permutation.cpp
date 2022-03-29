# include <iostream>
# include <vector>
# include <cppUtils.h>

using namespace std;

class Solution {
public:
};

int main() {
    vector<int> nums{2, 7, 11, 15};
    int target = 26;
    string s = "aa";
    auto *so = new Solution();
    CppUtils::print(s);
    CppUtils::print_1d_vector(nums);
    delete so;
    return 0;
}

