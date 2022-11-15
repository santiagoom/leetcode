
#include <iostream>
#include <cppUtils.h>
using namespace std;

                    
class ValidWordAbbr {
public:
	ValidWordAbbr(vector<string> &dictionary) {
		for (string& d : dictionary) {
			int n = d.length();
			string abbr = d[0] + to_string(n) + d[n - 1];
			mp[abbr].insert(d);
		}
	}

	bool isUnique(string word) {
		int n = word.length();
		string abbr = word[0] + to_string(n) + word[n - 1];
		return mp[abbr].count(word) == mp[abbr].size(); 
	}
private:
	unordered_map<string, unordered_set<string>> mp;
};

int main() {
auto *so = new Solution_288_UniqueWordAbbreviation_1();
vector<int> nums{2, 7, 11, 15};
int target = 26;
string s = "aa";
vector<vector<int>> arrays;
CppUtils::print(s);
CppUtils::print_1d_vector(nums);
CppUtils::print_2d_vector(arrays);
return 0;
}
                    