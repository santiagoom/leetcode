// Space optimized C++ implementation 
// of LCS problem 
//#include<bits/stdc++.h>
#include <iostream>

using namespace std;


// Returns length of LCS 
// for X[0..m-1], Y[0..n-1] 
int lcs(string &X, string &Y) {

    // Find lengths of two strings 
    int m = X.length(), n = Y.length();

    int L[2][n + 1];

    // Binary index, used to 
    // index current row and 
    // previous row. 
    bool bi;

    for (int i = 0; i <= m; i++) {

        // Compute current 
        // binary index 
        bi = i & 1;

        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[bi][j] = 0;

            else if (X[i - 1] == Y[j - 1])
                L[bi][j] = L[1 - bi][j - 1] + 1;

            else
                L[bi][j] = max(L[1 - bi][j],
                               L[bi][j - 1]);
        }
    }
//    One important observation in above simple implementation is,
//    in each iteration of outer loop we only, need values
//    from all columns of previous row. So there is no need
//    of storing all rows in our DP matrix, we can just store
//    two rows at a time and use them, in that way used space
//    will reduce from L[m+1][n+1] to L[2][n+1]. Below is
//    the implementation of above idea.

//    0 1 1 2 2 3 3 4
//    0 1 1 2 2 3 3 3
//    Length of LCS is 4
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= n; j++) {
            cout << L[i][j] << " ";
        }
        cout << endl;
    }

    // Last filled entry contains 
    // length of LCS 
    // for X[0..n-1] and Y[0..m-1] 
    return L[bi][n];
}

// Driver code 
int main() {
    string X = "AGGTAB";
    string Y = "GXTXAYB";

    printf("Length of LCS is %d\n", lcs(X, Y));
    return 0;
}