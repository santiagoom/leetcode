
# include <iostream>
#include <vector>

using namespace std;

int main() {
    cout << "new file!" << endl;
    return 0;
}

class Solution1 {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> &numbers, int target) {
        // write your code here
        if(numbers.size() < 3) {return -1;}
        sort(numbers.begin(), numbers.end());
        int min_diff = INT_MAX;
        int result;
        for(int i = 0; i < numbers.size() - 2; i++) {
            int left = i + 1, right = numbers.size() - 1;
            while(left < right) {
                int sum3 = numbers[i] + numbers[left] + numbers[right];
                if(std::abs(target - sum3) < min_diff) {
                    min_diff = std::abs(target - sum3);
                    if(min_diff == 0) {
                        return sum3;
                    }
                    result = sum3;
                }

                if(sum3 < target) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        return result;
    }
};