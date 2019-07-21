
# include <iostream>
#include <vector>

using namespace std;

int main() {
    cout << "new file!" << endl;
    return 0;
}

class Solution1 {
public:
    /*
    题意：找到数列中所有和等于目标数的四元组，需去重
    多枚举一个数后，参照3Sum的做法，O(N^3)
    */
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        int left, right, sum;
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> tmp;
        for (int i = 0; i < len - 3; i++) {
            if (i && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < len - 2; j++) {
                if (j != i + 1 && nums[j] == nums[j - 1]) continue;
                sum = target - nums[i] - nums[j];
                left = j + 1;
                right = len - 1;
                while (left < right) {
                    if (nums[left] + nums[right] == sum) {
                        tmp.clear();
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[j]);
                        tmp.push_back(nums[left]);
                        tmp.push_back(nums[right]);
                        res.push_back(tmp);
                        left++;
                        right--;
                        while (left < right && nums[left] == nums[left - 1]) left++;
                        while (left < right && nums[right] == nums[right + 1]) right--;
                    } else
                    if (nums[left] + nums[right] > sum) right--;
                    else left++;
                }
            }
        }
        return res;
    }
};

class Solution2 {
public:
    /**
     * @param numbers: Give an array
     * @param target: An integer
     * @return: Find all unique quadruplets in the array which gives the sum of zero
     */
    vector<vector<int>> fourSum(vector<int> &numbers, int target) {
        // write your code here
        /*
        -2 -1 0 0 1 2
        -1 -1 -1 -1 0 0 1 1 1 1 2
        */
        vector<vector<int>> result;
        std::sort(numbers.begin(), numbers.end());
        for (int i=0; i<numbers.size(); i++) {
            if (i>0 && numbers[i]==numbers[i-1]) continue;
            for (int j=numbers.size()-1; j>=0; j--) {
                if (j<numbers.size()-1 && numbers[j]==numbers[j+1]) continue;
                if ((j-i)<3) break;
                int sum = numbers[i] + numbers[j];
                int k = i+1;
                int l = j-1;
                while (k<l) {
                    int new_sum = sum + numbers[k] + numbers[l];
                    if (new_sum==target) {
                        result.push_back({numbers[i],numbers[k],numbers[l],numbers[j]});
                        k++;
                        l--;
                        while (k<numbers.size()-1 && numbers[k]==numbers[k-1]) k++;
                        while (l>0 && numbers[l]==numbers[l+1]) l--;
                    } else if (new_sum < target) k++;
                    else l--;
                }
            }
        }
        return result;
    }
};