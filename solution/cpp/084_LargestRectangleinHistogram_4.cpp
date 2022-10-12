
#include <iostream>
#include <cppUtils.h>

using namespace std;

                    

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        stk.push(-1);
        int max_area = 0;
        for (size_t i = 0; i < heights.size(); i++) {
            while (stk.top() != -1 and heights[stk.top()] >= heights[i]) {
                int current_height = heights[stk.top()];
                stk.pop();
                int current_width = i - stk.top() - 1;
                max_area = max(max_area, current_height * current_width);
            }
            stk.push(i);
        }
        while (stk.top() != -1) {
            int current_height = heights[stk.top()];
            stk.pop();
            int current_width = heights.size() - stk.top() - 1;
            max_area = max(max_area, current_height * current_width);
        }
        return max_area;
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
                    