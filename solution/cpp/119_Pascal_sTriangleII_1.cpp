
#include <iostream>
#include <cppUtils.h>

using namespace std;


class Solution_119_Pascal_sTriangleII_1 {
public:
    int getNum(int row, int col) {
        if (row == 0 || col == 0 || row == col)
            return 1;

        return getNum(row - 1, col - 1) + getNum(row - 1, col);
    }

    vector<int> getRow(int rowIndex) {
        vector<int> ans;

        for (int i = 0; i <= rowIndex; i++)
            ans.push_back(getNum(rowIndex, i));

        return ans;
    }
};

int main() {
    int target = 3;
    auto *so = new Solution_119_Pascal_sTriangleII_1();
    auto nums = so->getRow(3);
    CppUtils::print_1d_vector(nums);
    return 0;
}
                    