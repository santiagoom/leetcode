
#include <iostream>
#include <cppUtils.h>

using namespace std;

                    
class Solution {
  public:
  bool isPowerOfTwo(int n) {
    if (n == 0) return false;
    long x = n;
    return (x & (-x)) == x;
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
                    