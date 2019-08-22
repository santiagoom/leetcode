
#include <iostream>

using namespace std;


/**
* This reference program is provided by @jiuzhang.com
* Copyright is reserved. Please indicate the source for forwarding
*/

class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        ans = toInt(s[0]);
        for (int i = 1; i < s.length(); i++) {
            ans += toInt(s[i]);
            if (toInt(s[i - 1]) < toInt(s[i])) {
                ans -= toInt(s[i - 1]) * 2;
            }
        }
        return ans;
    }

    int toInt(char s) {
        switch (s) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
    }
};

int main() {
    auto *so = new Solution();
    cout << "new file!" << endl;
    return 0;
}