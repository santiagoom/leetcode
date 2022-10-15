
#include <iostream>
#include <cppUtils.h>
using namespace std;

                    
class Solution_157_ReadNCharactersGivenRead4_2 {
public:
    int read(char *buf, int n) {
        int copiedChars = 0;
        int readChars = 4;
        int remainingChars = n;
        
        // While there are at least 4 characters remaining to be read and the last
        // call to readChars returned 4 characters, write directly to buf.
        while (remainingChars >= 4 && readChars == 4) {
            readChars = read4(buf + copiedChars);
            copiedChars += readChars;
        }
        
        // If there are between 1 and 3 characters that we still want to read and
        // readChars was not 0 last time we called read4, then create a buffer
        // for just this one call so we can ensure buf does not overflow.
        if (remainingChars && readChars) {
            char buf4[4];
            readChars = read4(buf4);
            for (int i = 0; i < min(remainingChars, readChars); i++) {
                buf[copiedChars++] = buf4[i];
            }
        }
        
        return min(n, copiedChars);
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
                    