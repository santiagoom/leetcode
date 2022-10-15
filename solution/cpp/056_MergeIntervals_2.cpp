
#include <iostream>
#include <cppUtils.h>

using namespace std;


class Solution_056_MergeIntervals_2 {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        for (auto interval: intervals) {
            // if the list of merged intervals is empty or if the current
            // interval does not overlap with the previous, simply append it.
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            }
                // otherwise, there is overlap, so we merge the current and previous
                // intervals.
            else {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        return merged;
    }
};

int main() {
    vector<vector<int>> intervals = {{1,  3},
                                     {8,  10},
                                     {2,  6},
                                     {15, 18}};
    auto *so = new Solution_056_MergeIntervals_2();
    vector<vector<int>> res = so->merge(intervals);
    CppUtils::print_2d_vector(res);
    return 0;
}
                    