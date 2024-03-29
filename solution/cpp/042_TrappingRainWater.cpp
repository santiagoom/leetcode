#include <iostream>
#include <vector>
#include <cppUtils.h>

using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
        int left = 0, right = height.size() - 1, ans = 0;
        int left_max = 0, right_max = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                height[left] >= left_max ? left_max = height[left] : ans += left_max - height[left];
                left++;
            } else {
                height[right] >= right_max ? right_max = height[right] : ans += right_max - height[right];
                right--;
            }
        }
        return ans;
    }
};


class Solution_p1 {
public:
     int trap(vector<int> &height) {
        int left = 0, right = height.size() - 1;
        int left_max = INT32_MIN, right_max = INT32_MIN;
        int res = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] > left_max)
                    left_max = height[left];
                else {
                    res += left_max - height[left];
                }
                left++;
            } else {
                if (height[right] > right_max)
                    right_max = height[right];
                else {
                    res += right_max - height[right];
                }
                right--;
            }
        }
        return res;
    }
};

int main() {
//    auto *so = new Solution();
    auto *so = new Solution_p1();
    vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int res = so->trap(height);
    CppUtils::print(res);
    return 0;
}
