#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() == 0)
            return 0;

        for (int i = 0;; i++) {
            for (int j = 0;; j++) {
                if (needle.length() == j)
                    return i;
                if (haystack.length() < i + j)
                    return -1;
                if (needle[j] != haystack[i + j])
                    break;
            }
        }
    }
};

int main() {
//    2019-08-25 13:11:33
//2019-08-25 13:21:45
    auto *so = new Solution();
    string s = "aaaaaaaaaaaac";
    string needle = "aaac";
    int index = so->strStr(s, needle);
    cout << index << endl;
    return 0;
}
