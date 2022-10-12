
#include <iostream>
#include <cppUtils.h>

using namespace std;

                    
class Solution {
public:
    bool overlap(vector<int>& interval1, vector<int>& interval2) {
        return interval1[0] >= interval2[0] and interval1[0] < interval2[1]
               or interval2[0] >= interval1[0] and interval2[0] < interval1[1];
    }
    
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        for (size_t i = 0; i < intervals.size(); i++) {
            for (size_t j = i + 1; j < intervals.size(); j++) {
                if (overlap(intervals[i], intervals[j])) {
                    return false;
                }
            }
        }
        return true;
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
                    