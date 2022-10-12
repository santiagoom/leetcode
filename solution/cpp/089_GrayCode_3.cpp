
#include <iostream>
#include <cppUtils.h>

using namespace std;

                    
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        result.push_back(0);
        
        for (int i = 1; i <= n; i++) {
            int previousSequenceLength = result.size();
            int mask = 1 << (i - 1);
            for (int j = previousSequenceLength - 1; j >= 0; j--) {
                result.push_back(mask + result[j]);
            }
        }
        return result;
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
                    