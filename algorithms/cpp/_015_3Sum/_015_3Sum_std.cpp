#include <iostream>
#include <vector>

using namespace std;

class _015 {
public:
    vector<vector<int> > threeSum(vector<int> &num) {

        vector<vector<int> > res;

        std::sort(num.begin(), num.end());

        for (int i = 0; i < num.size(); i++) {

            int target = -num[i];
            int front = i + 1;
            int back = num.size() - 1;

            while (front < back) {

                int sum = num[front] + num[back];

                // Finding answer which start from number num[i]
                if (sum < target)
                    front++;

                else if (sum > target)
                    back--;

                else {
                    vector<int> triplet(3, 0);
                    triplet[0] = num[i];
                    triplet[1] = num[front];
                    triplet[2] = num[back];
                    res.push_back(triplet);

                    // Processing duplicates of Number 2
                    // Rolling the front pointer to the next different number forwards
                    while (front < back && num[front] == triplet[1]) front++;

                    // Processing duplicates of Number 3
                    // Rolling the back pointer to the next different number backwards
                    while (front < back && num[back] == triplet[2]) back--;
                }

            }

            // Processing duplicates of Number 1
            while (i + 1 < num.size() && num[i + 1] == num[i])
                i++;

        }

        return res;

    }
};


// 完全依赖hash table的话 去重是nightmare

// 一共有 3 个数字: a + b + c = total (本题total=0)
// for 循环 a 数字， 转化为 求两个数字two sum 的和为 total - a 的问题

// 思路: 转化为 Two Sum Unique Pairs 问题来做

// 联系比较 3Sum Closest

class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @return: Find all unique triplets in the array which gives the sum of zero.
     */
    // 3Sum 去重模版 转化为Two Sum去重
    vector<vector<int>> threeSum(vector<int> &numbers) {
        // write your code here
        vector<vector<int>> results;
        int n = numbers.size();
        if (n < 3) { //至少要有3个数
            return results;
        }

        // !!先排序
        std::sort(numbers.begin(), numbers.end());

        // 一共 O(n^2)
        for (int i = 0; i < n - 2; i++) { //O(n)
            // 去重 选代表的思路
            // skip duplicate triplets with the same first number
            if (i > 0 && numbers[i] == numbers[i - 1]) {
                continue;
            }

            // 转化为 Two Sum Unique Pairs问题
            // !!仔细看边界 现在"固定"了第一个数在index i
            // 剩下两个数范围[i+1, n-1]
            int left = i + 1;
            int right = n - 1;
            int target = -numbers[i]; // Two Sums to this target

            twoSum(numbers, left, right, target, results); // O(n)
        }
        return results;
    }

private:
    // Two Sum Unique Pair: 在[left, right]范围内对sorted数组找加起来
    // 等于target的Unique Pairs.
    // left right是左右边界 也是首尾双指针
    void twoSum(vector<int> &nums, int left, int right, int target,
                vector<vector<int>> &results) {
        // nums数组已经从小到大排序了
        // std::sort(nums.begin(), nums.end()); //模版中语句

        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == target) {
                // -target就是numbers[i]但是这个函数不知道i
                results.emplace_back(vector<int>{-target, nums[left], nums[right]});

                //!!爽完了一定要update 双指针 left 和 right
                left++;
                right--;

                //!!去重 数组已有序 左指针不断和左边比 右指针不断和右边比

                // 左指针的数如果和左边一样 结果重复 要skip
                // skip duplicate pairs with same left
                while (left < right && nums[left] == nums[left - 1]) {
                    left++;
                }
                //右指针的数如果和右边一样 结果重复 要skip
                // skip duplicate pairs with same right
                while (left < right && nums[right] == nums[right + 1]) {
                    right--;
                }
            } else if (sum < target) {
                left++; //right已经是最大的 所以左边要增大
            } else { // sum > target
                right--; //left已经是最小的 所以右边要减小
            }
        } //while(left<right)
    }
};

int main() {
//    Given array nums = [-1, 0, 1, 2, -1, -4],
//    A solution set is:
//    [
//    [-1, 0, 1],
//    [-1, -1, 2]
//    ]

//    vector<int> nums{-1, 0, 1, 2, -1, -4};
    vector<int> nums{};

    auto *so = new _015();
    vector<vector<int>> res = so->threeSum(nums);

    for (vector<int> vect:res)
        for (int x:vect)
            cout << x << endl;
}
