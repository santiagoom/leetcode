
#include <iostream>
#include <cppUtils.h>

using namespace std;

                    
class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    vector<int> curr, prev = {1};

    for (int i = 1; i <= rowIndex; i++) {
      curr.assign(i + 1, 1);

      for (int j = 1; j < i; j++)
        curr[j] = prev[j - 1] + prev[j];

      prev = move(curr);  // This is O(1)
    }

    return prev;
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
                    