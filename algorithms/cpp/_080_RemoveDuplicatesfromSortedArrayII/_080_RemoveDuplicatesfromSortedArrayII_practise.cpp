#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.empty())
            return 0;
        int i = 0;
        int count = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j - 1] != nums[j]) {
                count = 0;
                i++;
                nums[i] = nums[j];
            } else {
                count++;
                if (count <= 1) {
                    i++;
                    nums[i] = nums[j];
                }
            }
        }
        return i + 1;
    }
};

int main() {
//    2019-08-25 12:07:25
//2019-08-25 12:14:04
    auto *so = new Solution();
    vector<int> nums{0, 0, 1, 1, 1, 2, 2, 3, 3, 4, 5};
    int len = so->removeDuplicates(nums);
    for (int i = 0; i < len; i++) {
        cout << nums[i];
    }
    return 0;
}