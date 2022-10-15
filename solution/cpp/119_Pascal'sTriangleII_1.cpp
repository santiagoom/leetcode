
#include <iostream>
#include <cppUtils.h>
using namespace std;

                    
class Solution_119_Pascal'sTriangleII_1 {
 public:
  int getNum(int row, int col) {
    if (row == 0 || col == 0 || row == col)
      return 1;

    return getNum(row - 1, col - 1) + getNum(row - 1, col);
  }

  vector<int> getRow(int rowIndex) {
    vector<int> ans;

    for (int i = 0; i <= rowIndex; i++)
      ans.push_back(getNum(rowIndex, i));

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
                    