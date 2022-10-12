
#include <iostream>
#include <cppUtils.h>

using namespace std;

                    
class Solution {
public:
    int calculateArea(vector<int>& heights, int start, int end) {
        if (start > end) {
            return 0;
        }
        int min_index = start;
        for (int i = start; i <= end; i++) {
            if (heights[min_index] > heights[i]) {
                min_index = i;
            }
        }
        return max({heights[min_index] * (end - start + 1),
                    calculateArea(heights, start, min_index - 1),
                    calculateArea(heights, min_index + 1, end)});
    }

    int largestRectangleArea(vector<int>& heights) {
        return calculateArea(heights, 0, heights.size() - 1);
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
                    