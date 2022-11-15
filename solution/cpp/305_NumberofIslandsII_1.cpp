
#include <iostream>
#include <cppUtils.h>
using namespace std;

                    
class Solution_305_NumberofIslandsII_1 {
private:
  void dfs(vector<vector<char>>& grid, int r, int c, vector<vector<bool>>& visited) {
    int nr = grid.size();
    int nc = grid[0].size();

    if (r < 0 || c < 0 || r >= nr || c >= nc || grid[r][c] == '0' || visited[r][c]) return;

    visited[r][c] = true;
    dfs(grid, r - 1, c, visited);
    dfs(grid, r + 1, c, visited);
    dfs(grid, r, c - 1, visited);
    dfs(grid, r, c + 1, visited);
  }

  int numIslands(vector<vector<char>>& grid) {
    int nr = grid.size();
    int nc = grid[0].size();

    vector<vector<bool>> visited (nr, vector<bool>(nc, false));
    int num_islands = 0;
    for (int r = 0; r < nr; ++r) {
      for (int c = 0; c < nc; ++c) {
        if (grid[r][c] == '1' && !visited[r][c]) {
          ++num_islands;
          dfs(grid, r, c, visited);
        }
      }
    }

    return num_islands;
  }

public:
  vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
    vector<int> ans;
    vector<vector<char>> grid (m, vector<char>(n, '0'));
    for (auto pos : positions) {
      grid[pos.first][pos.second] = '1';
      ans.push_back(numIslands(grid));
    }

    return ans;
  }
};

int main() {
auto *so = new Solution_305_NumberofIslandsII_1();
vector<int> nums{2, 7, 11, 15};
int target = 26;
string s = "aa";
vector<vector<int>> arrays;
CppUtils::print(s);
CppUtils::print_1d_vector(nums);
CppUtils::print_2d_vector(arrays);
return 0;
}
                    