
#include <iostream>
#include <cppUtils.h>
using namespace std;

                    
class Solution_249_GroupShiftedStrings_1 {
public:
    char shiftLetter(char letter, int shift) {
        return (letter - shift + 26) % 26 + 'a';
    }
    
    // Create a hash value
    string getHash(string& s) {
        // Calculate the number of shifts to make the first character to be 'a'
        int shift = s[0];
        string hashKey;
        
        for (char letter : s) {
            hashKey += shiftLetter(letter, shift);
        }
        
        return hashKey;
    }
    
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> mapHashToList;
        
        // Create a hash_value (hashKey) for each string and append the string
        // to the list of hash values i.e. mapHashToList["abc"] = ["abc", "bcd"]
        for (string str : strings) {
            string hashKey = getHash(str);
            mapHashToList[hashKey].push_back(str);
        }
        
        // Iterate over the map, and add the values to groups
        vector<vector<string>> groups;
        for (auto it : mapHashToList) {
            groups.push_back(it.second);
        }
        
        return groups;
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
                    