
#include <iostream>
#include <cppUtils.h>
using namespace std;

                    
class Solution_263_UglyNumber_1 {
public:
    bool isUgly(int num) {
        for (int i=2; i<6 && num; i++)
    while (num % i == 0)
        num /= i;
return num == 1;
        
    }
};

int main() {
auto *so = new Solution_263_UglyNumber_1();
vector<int> nums{2, 7, 11, 15};
int target = 26;
string s = "aa";
vector<vector<int>> arrays;
CppUtils::print(s);
CppUtils::print_1d_vector(nums);
CppUtils::print_2d_vector(arrays);
return 0;
}
                    