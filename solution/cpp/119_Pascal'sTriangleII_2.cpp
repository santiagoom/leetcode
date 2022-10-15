
#include <iostream>
#include <cppUtils.h>
using namespace std;

                    
class Solution_119_Pascal'sTriangleII_2 {
  unordered_map<size_t, int> cache;

  // use a better hashing function like `boost::hash_combine` in the real world.
  int key(int i, int j) const {
    size_t hash_i = hash<int>{}(i), hash_j = hash<int>{}(j);
    int hashed = (int)(hash_i ^ (hash_i >> 32));
    return (hashed << 5) - 1 + (int)(hash_j ^ (hash_j >> 32));
  }

 public:
  int getNum(int row, int col) {
    auto rowCol = key(row, col);

    if (cache.count(rowCol) > 0)
      return cache[rowCol];

    if (row == 0 || col == 0 || row == col)
      return (cache[rowCol] = 1);

    return (cache[rowCol] = getNum(row - 1, col - 1) + getNum(row - 1, col));
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
                    