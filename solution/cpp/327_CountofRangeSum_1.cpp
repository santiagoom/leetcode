
#include <iostream>
#include <cppUtils.h>
using namespace std;

                    
class Solution_327_CountofRangeSum_1 {
public:
void mergeArray(vector<long long>& sum, int left, int mid, int right){
    vector<long long> tmp(right-left+1);
    int i = left, j = mid+1, k = 0;
    while(i <= mid && j <= right){
        tmp[k++] = sum[i] <= sum[j]? sum[i++] : sum[j++];
    }
    while(i <= mid){
        tmp[k++] = sum[i++];
    }
    while(j <= right){
        tmp[k++] = sum[j++];
    }
    i = left, k = 0;
    while(i <= right){
        sum[i++] = tmp[k++];
    }
}
int mergeCount(vector<long long>& sum, int left, int right, int lower, int upper){
    if(left == right){
        return sum[left] >= lower && sum[right] <= upper? 1 : 0;
    }
    int count = 0;
    int mid = left + ((right-left)>>1);
    int leftCount = mergeCount(sum, left, mid, lower, upper);
    int rightCount = mergeCount(sum, mid+1, right, lower, upper);
    int i = left, k = mid+1, j = mid+1;
    while(i <= mid){
        long long lowerBound = sum[i]+lower, upperBound = sum[i]+upper;
        while(j <= right && sum[j] <= upperBound){
            ++j;
        }
        while(k <= right && sum[k] < lowerBound){
            ++k;
        }
        count += (j-k);
        ++i;
    }
    mergeArray(sum, left, mid, right);
    return leftCount+rightCount+count;
}
//Time O(NlogN), Space O(N)
int countRangeSum(vector<int>& nums, int lower, int upper) {
    vector<long long> sum(nums.size(), 0);
    sum[0] = nums[0];
    for(int i = 1; i < nums.size(); ++i){
        sum[i] = sum[i-1]+nums[i];
    }
    return mergeCount(sum, 0, sum.size()-1, lower, upper);
}
};

int main() {
auto *so = new Solution_327_CountofRangeSum_1();
vector<int> nums{2, 7, 11, 15};
int target = 26;
string s = "aa";
vector<vector<int>> arrays;
CppUtils::print(s);
CppUtils::print_1d_vector(nums);
CppUtils::print_2d_vector(arrays);
return 0;
}
                    