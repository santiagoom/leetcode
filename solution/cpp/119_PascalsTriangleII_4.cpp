
#include <iostream>
#include <cppUtils.h>

using namespace std;

                    
class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    vector<int> ans = vector<int>(rowIndex + 1, 1);

    for (int i = 1; i < rowIndex; i++)
      for (int j = i; j > 0; j--)
        ans[j] += ans[j - 1];  // ans[j] = ans[j-1] + ans[j]

    return ans;
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
                    