
#include <iostream>
#include <cppUtils.h>
using namespace std;

                    
class Solution_038_CountandSay_2 {
public:
    string countAndSay(int n) {
        regex e("(.)\\1*");
        string s = "1";
        for (int i = 2; i <= n; i++) {
            string t; 
            for (sregex_iterator it = sregex_iterator(s.begin(), s.end(), e);
                 it != sregex_iterator(); it++) {
                t += to_string(it->str().size()) + it->str(1);
            }
            s = t;
        }
        return s;
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
                    