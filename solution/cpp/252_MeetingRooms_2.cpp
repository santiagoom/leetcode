
#include <iostream>
#include <cppUtils.h>
using namespace std;

                    
class Solution_252_MeetingRooms_2 {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return true;
        }

        // Note: C++ sort function automatically sorts a vector first
        // by the 1st element, then by the 2nd element and so on.
        sort(intervals.begin(), intervals.end());
        for (size_t i = 0; i < intervals.size() - 1; i++) {
            if (intervals[i][1] > intervals[i + 1][0]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
vector<int> nums{2, 7, 11, 15};
int target = 26;
string s = "aa";
vector<vector<int>> arrays;
CppUtils::print(s);
CppUtils::print_1d_vector(nums);
CppUtils::print_2d_vector(arrays);
return 0;
}
                    