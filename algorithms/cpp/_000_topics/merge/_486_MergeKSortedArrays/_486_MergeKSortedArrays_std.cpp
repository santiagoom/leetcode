#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    /**
     * @param arrays: k sorted integer arrays
     * @return: a sorted array
     */
    vector<int> mergekSortedArrays(vector<vector<int>> &arrays) {
        // write your code here
        if(arrays.size() == 0) return {};
        if(arrays.size() == 1) return arrays[0];
        vector<int> res = mergeHelper(arrays,0,arrays.size() -1);
        return res;
    }

    vector<int> mergeHelper(vector<vector<int>>& arrays, int start, int end)
    {
        if(start >= end) return arrays[start];
        int mid = (end - start)/2 + start;
        vector<int> left = mergeHelper(arrays,start,mid);
        vector<int> right = mergeHelper(arrays,mid+1,end);
        return merge(left,right);
    }

    vector<int> merge(vector<int>& a, vector<int>& b)
    {
        vector<int> newArray;
        int a_idx = 0, b_idx = 0;
        while(a_idx < a.size() && b_idx < b.size())
        {
            if(a[a_idx] < b[b_idx])
            {
                newArray.push_back(a[a_idx]);
                a_idx++;
            }
            else
            {
                newArray.push_back(b[b_idx]);
                b_idx++;
            }
        }
        while(a_idx < a.size())
        {
            newArray.push_back(a[a_idx]);
            a_idx++;
        }
        while(b_idx < b.size())
        {
            newArray.push_back(b[b_idx]);
            b_idx++;
        }
        return newArray;
    }
};

int main() {
    auto *so = new Solution();
    cout << "new file!" << endl;
    return 0;
}
