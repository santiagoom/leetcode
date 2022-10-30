
#include <iostream>
#include <cppUtils.h>

using namespace std;


class Solution_119_Pascal_sTriangleII_4 {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans = vector<int>(rowIndex + 1, 1);

        for (int i = 1; i < rowIndex; i++)
            for (int j = i; j > 0; j--)
                ans[j] += ans[j - 1];  // ans[j] = ans[j-1] + ans[j]

        return ans;
    }
};

int main() {
    int target = 3;
    auto *so = new Solution_119_Pascal_sTriangleII_4();
    auto nums = so->getRow(3);
    CppUtils::print_1d_vector(nums);
    return 0;
}
                    