
# include <iostream>

using namespace std;

int main() {
    cout << "new file!" << endl;
    return 0;
}

class Solution {
public:
    /**
     * @param nums:  an array of n integers
     * @param target: a target
     * @return: the number of index triplets satisfy the condition nums[i] + nums[j] + nums[k] < target
     */
    int threeSumSmaller(vector<int> &nums, int target) {
        // Write your code here
        sort(nums.begin(),nums.end());
        int ans = 0;
        int len = nums.size();
        for( int i = 0;i < len - 2; ++i )
        {
            int sum = target - nums[i];
            int start =  i + 1;
            int end = len - 1;
            while( start < end )
            {
                if( nums[start] + nums[end] >= sum )
                {
                    --end;
                }else{
                    ans += (end - start);
                    ++start;
                }
            }
        }
        return ans;
    }
};

class Solution1 {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        // Sort + Three pointers
        // O(n^2) time & O(1) space

        if (nums.size() < 3) {
            return 0;
        }

        int n = nums.size();
        sort(nums.begin(), nums.end());

        int count = 0;
        for (int i = 0; i < n - 2; i++) {
            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < target) {
                    count += k - j;
                    j++;
                } else {
                    k--;
                }
            }
        }

        return count;
    }
};