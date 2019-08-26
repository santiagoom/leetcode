#include <iostream>
#include <vector>

using namespace std;

class Solution {
//    from 0;  return i not i+1
public:
    int removeElement(vector<int> &nums, int val) {
        if (nums.empty())
            return 0;
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (val != nums[j]) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};

int main() {
//    2019-08-25 11:59:30
//2019-08-25 12:07:12
    auto *so = new Solution();
    vector<int> nums{0, 0, 1, 1, 1, 2, 2, 3, 3, 4, 5};
    int val = 2;
    int len = so->removeElement(nums, val);
    for (int i = 0; i < len; i++) {
        cout << nums[i];
    }
    return 0;
}
