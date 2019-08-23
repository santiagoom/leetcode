#include <iostream>
#include <vector>

using namespace std;


/**
* This reference program is provided by @jiuzhang.com
* Copyright is reserved. Please indicate the source for forwarding
*/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        int f[target+1];
        memset(f, 0, sizeof(f));

        f[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < n; j++)
                if (i - nums[j] >= 0){
                    f[i] += f[i-nums[j]];
                }
        }
        return f[target];
    }
};

int main() {
    auto *so = new Solution();
    cout << "new file!" << endl;
    return 0;
}
