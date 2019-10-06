#include <iostream>
#include <vector>
#include <myutils.h>

using namespace std;


class Solution {
public:
    int numDistinct(string &S, string &T) {
        if (T.length() == 0) {
            return 1;
        }
        vector<vector<int>> t(T.length() + 1, vector<int>(S.length() + 1));
        for (int i = 0; i <= T.length(); i++) t[i][0] = 0;
        for (int i = 0; i <= S.length(); i++) t[0][i] = 0;
        for (int i = 1; i <= S.length(); i++) {
            if (T[0] == S[i - 1])
                t[1][i] = t[1][i - 1] + 1;
            else
                t[1][i] = t[1][i - 1];
        }


        for (int i = 2; i <= T.length(); i++) {
            for (int j = 1; j <= S.length(); j++) {
                if (T[i - 1] == S[j - 1])
                    t[i][j] = t[i - 1][j - 1] + t[i][j - 1];
                else
                    t[i][j] = t[i][j - 1];
            }
        }
        return t[T.length()][S.length()];
    }
};

int main() {
    auto *so = new Solution();
    string s = "rabbbit";
    string t = "rabbit";
    int res = so->numDistinct(s, t);
    print(res);
    delete so;
    return 0;
}
