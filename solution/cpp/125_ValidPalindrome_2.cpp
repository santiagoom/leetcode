
#include <iostream>
#include <cppUtils.h>
using namespace std;

                    
class Solution_125_ValidPalindrome_2 {
 public:
  bool isPalindrome(string s) {
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
      while (i < j && !isalnum(s[i]))
        i++;
      while (i < j && !isalnum(s[j]))
        j--;

      if (tolower(s[i]) != tolower(s[j]))
        return false;
    }

    return true;
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
                    