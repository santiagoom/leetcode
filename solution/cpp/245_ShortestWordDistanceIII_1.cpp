
#include <iostream>
#include <cppUtils.h>
using namespace std;

                    
class Solution_245_ShortestWordDistanceIII_1 {
public:
int shortestWordDistance(vector<string>& words, string word1, string word2) {
    long long dist = INT_MAX, i1 = dist, i2 = -dist;
    bool same = word1 == word2;
    for (int i=0; i<words.size(); i++) {
        if (words[i] == word1) {
            i1 = i;
            if (same)
                swap(i1, i2);
        } else if (words[i] == word2) {
            i2 = i;
        }
        dist = min(dist, abs(i1 - i2));
    }
    return dist;
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
                    