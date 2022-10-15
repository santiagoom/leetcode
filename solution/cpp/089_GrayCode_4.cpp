
#include <iostream>
#include <cppUtils.h>
using namespace std;

                    
class Solution_089_GrayCode_4 {
public:

    vector<int> grayCode(int n) {
        vector<int> result;
        grayCodeHelper(result, n);
        return result;
    }

private:
    int nextNum = 0;

    void grayCodeHelper(vector<int> &result, int n) {
        if (n == 0) {
            result.push_back(nextNum);
            return;
        }
        grayCodeHelper(result, n - 1);
        // Flip the bit at (n - 1)th position from right
        nextNum = nextNum ^ (1 << (n - 1));
        grayCodeHelper(result, n - 1);

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
                    