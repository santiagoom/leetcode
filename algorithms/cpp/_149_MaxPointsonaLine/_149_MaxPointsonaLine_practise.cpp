#include <iostream>
#include <vector>
#include <unordered_map>
#include <myutils.h>

using namespace std;

// Definition for a point.
struct Point {
    int x;
    int y;

    Point() : x(0), y(0) {}

    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<vector<int>> &vec_points) {
        vector<Point> points;
        for (auto &level:vec_points) {
            points.push_back(Point(level[0], level[1]));
        }

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
    vector<vector<int>> points{
            {1, 1},
            {3, 2},
            {5, 3},
            {4, 1},
            {2, 3},
            {1, 4}
    };
    int res = so->maxPoints(points);
    print(res);
    delete so;
    return 0;
}
