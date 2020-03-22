#include <iostream>
#include <vector>

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


int main() {
//2019-08-18 22:37:27
//2019-08-18 22:49:17
    auto *so = new Solution();
    vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int res = so->trap(height);
    cout << res << endl;
    return 0;
}