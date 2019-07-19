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
            while (i + 1 < num.size() && num[i] == num[i + 1]) i++;

        }

        return res;

    }
};


int main() {
//    Given array nums = [-1, 0, 1, 2, -1, -4],
//    A solution set is:
//    [
//    [-1, 0, 1],
//    [-1, -1, 2]
//    ]

    vector<int> nums{-1, 0, 1, 2, -1, -4};

    auto *so = new _015();
    vector<vector<int>> res = so->threeSum(nums);

    for (vector<int> vect:res)
        for (int x:vect)
            cout << x << endl;
}
