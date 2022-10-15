
#include <iostream>
#include <cppUtils.h>
using namespace std;

                    
class Bucket {
public:
    bool used = false;
    int minval = numeric_limits<int>::max();        // same as INT_MAX
    int maxval = numeric_limits<int>::min();        // same as INT_MIN
};

int maximumGap(vector<int>& nums)
{
    if (nums.empty() || nums.size() < 2)
        return 0;

    int mini = *min_element(nums.begin(), nums.end()),
        maxi = *max_element(nums.begin(), nums.end());

    int bucketSize = max(1, (maxi - mini) / ((int)nums.size() - 1));        // bucket size or capacity
    int bucketNum = (maxi - mini) / bucketSize + 1;                         // number of buckets
    vector<Bucket> buckets(bucketNum);

    for (auto&& num : nums) {
        int bucketIdx = (num - mini) / bucketSize;                          // locating correct bucket
        buckets[bucketIdx].used = true;
        buckets[bucketIdx].minval = min(num, buckets[bucketIdx].minval);
        buckets[bucketIdx].maxval = max(num, buckets[bucketIdx].maxval);
    }

    int prevBucketMax = mini, maxGap = 0;
    for (auto&& bucket : buckets) {
        if (!bucket.used)
            continue;

        maxGap = max(maxGap, bucket.minval - prevBucketMax);
        prevBucketMax = bucket.maxval;
    }

    return maxGap;
}

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
                    