
#include <iostream>
#include <cppUtils.h>

using namespace std;

                    
class Solution {
 public:
  bool isPalindrome(string s) {
    string filtered_string, reversed_string;

    for (auto ch : s) {
      if (isalnum(ch))
        filtered_string += tolower(ch);
    }

    reversed_string.resize(filtered_string.size());
    reverse_copy(filtered_string.begin(), filtered_string.end(),
                 reversed_string.begin());

    return filtered_string == reversed_string;
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
                    