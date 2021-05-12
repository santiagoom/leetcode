#include <iostream>
#include <cppUtils.h>

using namespace std;

class Solution {
public:
    /**
     * @param nums a sorted integer array
     * @param lower an integer
     * @param upper an integer
     * @return a list of its missing ranges
     */
    string getString(long long st, long long ed) {
        if (st > ed) {
            return "";
        }
        if (st == ed) {
            return to_string(st);
        }
        return to_string(st) + "->" + to_string(ed);
    }

    vector<string> findMissingRanges(vector<int> &nums, int lower, int upper) {
        // Write your code here
        vector<string> ans;
        string tmp;

        vector<long long> nums2;
        for (int i = 0; i < nums.size(); i++) {
            nums2.push_back(nums[i]);
        }

        if (nums2.empty()) {
            tmp = getString(lower, upper);
            if (tmp != "") {
                ans.push_back(tmp);
            }
            return ans;
        }
        //////////////////////////////////////////////////////////

        tmp = getString(lower, nums2[0] - 1);
        if (tmp != "") {
            ans.push_back(tmp);
        }

        for (int i = 1; i < nums2.size(); i++) {
            tmp = getString(nums2[i - 1] + 1, nums2[i] - 1);
            if (tmp != "") {
                ans.push_back(tmp);
            }
        }

        tmp = getString(nums2.back() + 1, upper);
        if (tmp != "") {
            ans.push_back(tmp);
        }
        return ans;
    }
};

int main() {
    auto *so = new Solution();
    vector<int> nums = {0, 1, 3, 50, 75};
    int lower = 0;
    int upper = 99;
    vector<string> res = so->findMissingRanges(nums, lower, upper);
    CppUtils::print_1d_vector(res);
    delete so;
    return 0;
}
