
# include <iostream>

using namespace std;

//int main() {
//    cout << "new file!" << endl;
//    return 0;
//}


// A C++ dynamic programming
// solution for longest palindrome

//#include <bits/stdc++.h>
#include <iostream>

using namespace std;


// Function to print a substring str[low..high]
void printSubStr(string str, int low, int high) {
    for (int i = low; i <= high; ++i)
        cout << str[i];
}

// This function prints the longest palindrome substring
// It also returns the length of the longest palindrome
string longestPalSubstr(string str) {
    // get length of input string
    int n = str.size();
    if (n == 0)
        return "";

    // table[i][j] will be false if substring str[i..j]
    // is not palindrome.
    // Else table[i][j] will be true
    bool table[n][n];

    memset(table, 0, sizeof(table));

    // All substrings of length 1 are palindromes
    int maxLength = 1;

    for (int i = 0; i < n; ++i)
        table[i][i] = true;

    // check for sub-string of length 2.
    int start = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (str[i] == str[i + 1]) {
            table[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }

    // Check for lengths greater than 2. k is length
    // of substring
    for (int k = 3; k <= n; ++k) {
        // Fix the starting index
        for (int i = 0; i < n - k + 1; ++i) {
            // Get the ending index of substring from
            // starting index i and length k
            int j = i + k - 1;

            // checking for sub-string from ith index to
            // jth index iff str[i+1] to str[j-1] is a
            // palindrome
            if (table[i + 1][j - 1] && str[i] == str[j]) {
                table[i][j] = true;

                if (k > maxLength) {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }

    // return length of LPS
//    cout << start << "," << maxLength << "," << start + maxLength << endl;
    return str.substr(start, maxLength);;
}

// Driver Code
int main() {
//    string str = "forgeeksskeegfor";
    string str = "cbbbd";
//    string str = "dbabc";
//    string str = "babad";
    cout << "\nLength is: " << longestPalSubstr(str);



//    cout << str.substr(0,3);
    return 0;
}
