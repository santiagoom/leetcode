
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