
#include <iostream>
#include <cppUtils.h>

using namespace std;


class Solution_038_CountandSay_1 {
public:
    string countAndSay(int n) {
        string currentString = "1";
        for (int i = 2; i <= n; i++) {
            string nextString;
            for (int j = 0, k = 0; j < currentString.size(); j = k) {
                while (k < currentString.size() && currentString[k] == currentString[j]) k++;
                nextString += to_string(k - j) + currentString[j];
            }
            currentString = nextString;
        }
        return currentString;
    }
};

int main() {
    vector<int> nums{2, 7, 11, 15};
    int target = 1;
    auto *so = new Solution_038_CountandSay_1();
    string s = so->countAndSay(target);
    CppUtils::print(s);
    return 0;
}
                    