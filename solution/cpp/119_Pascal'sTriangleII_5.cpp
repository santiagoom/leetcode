
#include <iostream>
#include <cppUtils.h>
using namespace std;

                    

class Solution_119_Pascal'sTriangleII_5 {
 public:
  vector<int> getRow(int n) {
    vector<int> ans = {1};

    for (int k = 1; k <= n; k++)
      ans.push_back((int)((ans.back() * (long long)(n - k + 1)) / k));

    return ans;
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
                    