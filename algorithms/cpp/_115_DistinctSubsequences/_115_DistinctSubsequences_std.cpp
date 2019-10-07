#include <iostream>
#include <vector>
#include <myutils.h>

using namespace std;


/**
* This reference program is provided by @jiuzhang.com
* Copyright is reserved. Please indicate the source for forwarding
*/

class Solution {
public:
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        // write your code here
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

class Solution1 {
public:
    /**
     * @param S: A string
     * @param T: A string
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        // write your code here
        if (T.length() == 0) {
            return 1;
        }
        auto m=S.length(),n=T.length();
        vector<int>cnt(m+1,1);
        // for(auto i=0;i<n;++i)
        //     for(auto j=i,prev=cnt[i],tmp=cnt[i]=0;j<m;){
        //         tmp=cnt[j];
        //         if(S[j]==T[i])
        //             tmp+=prev;
        //         prev=cnt[++j];
        //         cnt[j]=tmp;
        //     }
        // return cnt[m];

        for(auto i=0;i<n;++i)
            for(auto j=0,prev=0;j<m-i;++j)
                prev=cnt[j]=prev+(S[j+i]==T[i]?cnt[j]:0);
        return cnt[m-n];
    }
};

int main() {
    auto *so = new Solution();
    vector<int> nums{};
    delete so;
    return 0;
}
