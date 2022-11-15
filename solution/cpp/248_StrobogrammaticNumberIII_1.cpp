
#include <iostream>
#include <cppUtils.h>
using namespace std;

                    
class Solution_248_StrobogrammaticNumberIII_1 {
public:
bool compare(string s1, string s2) {
	if (s1.length() != s2.length())
		return s1.length() <= s2.length();

	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] < s2[i]) return true;
		else if (s1[i] > s2[i]) return false;
	}

	return true;
}

int strobogrammaticInRange(const vector<pair<char, char>>& nums, const string& low, const string& high, string t, int cnt) {
	if (high.length() < t.length())
		return cnt;
	if (compare(low, t) && compare(t, high)) 
		if (t.length() == 1 || t.length() > 1 && t.front() != '0')
			cnt++;

	for (auto iter = nums.begin(); iter != nums.end(); ++iter) 
		cnt = strobogrammaticInRange(nums, low, high, string(1, iter->first) + t + string(1, iter->second), cnt);

	return cnt;
}

int strobogrammaticInRange(string low, string high) {
	if (!compare(low, high)) return 0;

	vector<pair<char, char>> nums = { { '0', '0' }, { '1', '1' }, { '6', '9' }, { '8', '8' }, { '9', '6' } };
	
	int cnt = strobogrammaticInRange(nums, low, high, "", 0);
	cnt = strobogrammaticInRange(nums, low, high, "0", cnt);
	cnt = strobogrammaticInRange(nums, low, high, "1", cnt);
	cnt = strobogrammaticInRange(nums, low, high, "8", cnt);
	
	return cnt;
}
};

int main() {
auto *so = new Solution_248_StrobogrammaticNumberIII_1();
vector<int> nums{2, 7, 11, 15};
int target = 26;
string s = "aa";
vector<vector<int>> arrays;
CppUtils::print(s);
CppUtils::print_1d_vector(nums);
CppUtils::print_2d_vector(arrays);
return 0;
}
                    