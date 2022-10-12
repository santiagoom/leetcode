
#include <iostream>
#include <cppUtils.h>

using namespace std;

                    
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        // Collect and sort the unique positions of all the edges.
        set<int> edgeSet;
        for (auto building : buildings) {
            edgeSet.insert(building[0]);
            edgeSet.insert(building[1]);
        }
        vector<int> positions(edgeSet.begin(), edgeSet.end());
        
        vector<vector<int>> answer;
            
        // For each position, draw an imaginary vertical line.
        for (auto position : positions) {
            int maxHeight = 0;
            // Check if any buildings intersect with the line at position.
            for (auto building : buildings) {
                int left = building[0], right = building[1], height = building[2];
                
                // Update 'maxHeight' if necessary.
                if (position >= left and position < right) {
                    maxHeight = max(maxHeight, height);
                }
            }
            
            // Add all the positions where the height changes to 'answer'.
            if (answer.empty() || answer[answer.size() - 1][1] != maxHeight) {
                answer.push_back({position, maxHeight});
            }
        }
        return answer;
    }
};

                    
int main() {
    vector<int> nums{2, 7, 11, 15};
    int target = 26;
    string s = "aa";
    auto *so = new Solution();
    vector<vector<int>> arrays;
    CppUtils::print(s);
    CppUtils::print_1d_vector(nums);
    CppUtils::print_2d_vector(arrays);
    delete so;
    return 0;
}
                    