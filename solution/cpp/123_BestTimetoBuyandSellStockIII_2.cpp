
#include <iostream>
#include <cppUtils.h>

using namespace std;

                    
class Solution {
  public:
  int maxProfit(vector<int>& prices) {
    int t1Cost = INT_MAX, 
        t2Cost = INT_MAX;
    int t1Profit = 0,
        t2Profit = 0;

    for (int price : prices) {
        // the maximum profit if only one transaction is allowed
        t1Cost = min(t1Cost, price);
        t1Profit = max(t1Profit, price - t1Cost);
        // re-invest the gained profit in the second transaction
        t2Cost = min(t2Cost, price - t1Profit);
        t2Profit = max(t2Profit, price - t2Cost);
    }

    return t2Profit;
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
                    