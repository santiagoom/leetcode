
#include <iostream>
#include <cppUtils.h>
using namespace std;

                    
class Solution_305_NumberofIslandsII_2 {
public:
  vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
    vector<int> ans;
    unordered_map<int, int> land2id; // land index : island ID
    int num_islands = 0;
    int island_id = 0;
    for (auto pos : positions) {
      int r = pos.first;
      int c = pos.second;
      // check pos's neighbors to see if they are in the existing islands or not
      unordered_set<int> overlap; // how many existing islands overlap with 'pos'
      if (r - 1 >= 0 && land2id.count((r-1) * n + c)) overlap.insert(land2id[(r-1) * n + c]);
      if (r + 1 < m && land2id.count((r+1) * n + c)) overlap.insert(land2id[(r+1) * n + c]);
      if (c - 1 >= 0 && land2id.count(r * n + c - 1)) overlap.insert(land2id[r * n + c - 1]);
      if (c + 1 < n && land2id.count(r * n + c + 1)) overlap.insert(land2id[r * n + c + 1]);

      if (overlap.empty()) { // no overlap
        ++num_islands;
        land2id[r * n + c] = island_id++; // new island
      } else if (overlap.size() == 1) { // one overlap, just append
        auto it = overlap.begin();
        land2id[r * n + c] = *it;
      } else { // more than 1 overlaps, merge
        auto it = overlap.begin();
        int root_id = *it;
        for (auto& kv : land2id) { // update island id
          if (overlap.count(kv.second)) kv.second = root_id;
        }
        land2id[r * n + c] = root_id;
        num_islands -= (overlap.size() - 1);
      }

      ans.push_back(num_islands);
    }

    return ans;
  }
};

int main() {
auto *so = new Solution_305_NumberofIslandsII_2();
vector<int> nums{2, 7, 11, 15};
int target = 26;
string s = "aa";
vector<vector<int>> arrays;
CppUtils::print(s);
CppUtils::print_1d_vector(nums);
CppUtils::print_2d_vector(arrays);
return 0;
}
                    