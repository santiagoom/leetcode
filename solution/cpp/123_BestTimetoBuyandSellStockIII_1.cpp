
#include <iostream>
#include <cppUtils.h>
using namespace std;

                    
class Solution_123_BestTimetoBuyandSellStockIII_1 {
  public:
  int maxProfit(vector<int>& prices) {
    int length = prices.size();
    if (length <= 1) return 0;

    int leftMin = prices[0];
    int rightMax = prices[length - 1];

    vector<int> leftProfits(length, 0);
    // pad the right DP array with an additional zero for convenience.
    vector<int> rightProfits(length + 1, 0);

    // construct the bidirectional DP array
    for (int l = 1; l < length; ++l) {
      leftProfits[l] = max(leftProfits[l - 1], prices[l] - leftMin);
      leftMin = min(leftMin, prices[l]);

      int r = length - 1 - l;
      rightProfits[r] = max(rightProfits[r + 1], rightMax - prices[r]);
      rightMax = max(rightMax, prices[r]);
    }

    int maxProfit = 0;
    for (int i = 0; i < length; ++i) {
      maxProfit = max(maxProfit, leftProfits[i] + rightProfits[i + 1]);
    }
    return maxProfit;
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
                    