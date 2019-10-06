#include <iostream>
#include <vector>
#include <unordered_map>
#include <myutils.h>

using namespace std;

/**
* This reference program is provided by @jiuzhang.com
* Copyright is reserved. Please indicate the source for forwarding
*/

// Definition for a point.
struct Point {
    int x;
    int y;

    Point() : x(0), y(0) {}

    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    /**
     * @param points an array of point
     * @return an integer
     */
    int maxPoints(vector<Point> &points) {
        // Write your code here
        unordered_map<float, int> mp;
        int maxNum = 0;
        for (int i = 0; i < points.size(); i++) {
            mp.clear();
            mp[INT_MIN] = 0;
            int duplicate = 1;
            for (int j = 0; j < points.size(); j++) {
                if (j == i) continue;
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    duplicate++;
                    continue;
                }
                float k = points[i].x == points[j].x ? INT_MAX : (float) (points[j].y - points[i].y) /
                                                                 (points[j].x - points[i].x);
                mp[k]++;
            }
            unordered_map<float, int>::iterator it = mp.begin();
            for (; it != mp.end(); it++)
                if (it->second + duplicate > maxNum)
                    maxNum = it->second + duplicate;
        }
        return maxNum;
    }
};

int main() {
    auto *so = new Solution();
    vector<int> nums{};
    delete so;
    return 0;
}
