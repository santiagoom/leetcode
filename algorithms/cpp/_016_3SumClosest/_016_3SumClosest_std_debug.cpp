
# include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> &numbers, int target) {
        // write your code here
        if (numbers.size() < 3) { return -1; }
        sort(numbers.begin(), numbers.end());
        int min_diff = INT_MAX;
        int result;
        for (int i = 0; i < numbers.size() - 2; i++) {
            int left = i + 1, right = numbers.size() - 1;
            while (left < right) {
                int sum3 = numbers[i] + numbers[left] + numbers[right];
                if (std::abs(target - sum3) < min_diff) {
                    min_diff = std::abs(target - sum3);
                    if (min_diff == 0) {
                        return sum3;
                    }
                    result = sum3;
                }

                if (sum3 < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return result;
    }
};


int main() {
//    vector<int> nums{-1, 2, 1, -4};
    vector<int> nums{};
    int target = 1;
    auto *so = new Solution();

    cout << so->threeSumClosest(nums, target) << endl;
    return 0;
}