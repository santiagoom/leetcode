
#include <iostream>
#include <cppUtils.h>
using namespace std;

                    
class Solution_317_ShortestDistancefromAllBuildings_3 {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        // Next four directions.
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Total Mtrix to store total distance sum for each empty cell.
        vector<vector<int>> total(rows, vector<int> (cols, 0));

        int emptyLandValue = 0;
        int minDist = INT_MAX;

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {

                // Start a bfs from each house.
                if (grid[row][col] == 1) {
                    minDist = INT_MAX;

                    // Use a queue to perform a BFS, starting from the cell located at (row, col).
                    queue<pair<int, int>> q;
                    q.push({ row, col });
                    
                    int steps = 0;

                    while (!q.empty()) {
                        steps++;

                        for (int level = q.size(); level > 0; --level) {
                            auto curr = q.front();
                            q.pop();

                            for (auto& dir : dirs) {
                                int nextRow = curr.first + dir[0];
                                int nextCol = curr.second + dir[1];

                                // For each cell with the value equal to empty land value
                                // add distance and decrement the cell value by 1.
                                if (nextRow >= 0 && nextRow < rows &&
                                    nextCol >= 0 && nextCol < cols &&
                                    grid[nextRow][nextCol] == emptyLandValue) {
                                    grid[nextRow][nextCol]--;
                                    total[nextRow][nextCol] += steps;

                                    q.push({ nextRow, nextCol });
                                    minDist = min(minDist, total[nextRow][nextCol]);
                                }
                            }
                        }
                    }

                    // Decrement empty land value to be searched in next iteration.
                    emptyLandValue--;
                }
            }
        }

        return minDist == INT_MAX ? -1 : minDist;
    }
};

int main() {
auto *so = new Solution_317_ShortestDistancefromAllBuildings_3();
vector<int> nums{2, 7, 11, 15};
int target = 26;
string s = "aa";
vector<vector<int>> arrays;
CppUtils::print(s);
CppUtils::print_1d_vector(nums);
CppUtils::print_2d_vector(arrays);
return 0;
}
                    