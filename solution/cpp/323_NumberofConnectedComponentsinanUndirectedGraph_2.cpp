
#include <iostream>
#include <cppUtils.h>
using namespace std;

                    
class Solution_323_NumberofConnectedComponentsinanUndirectedGraph_2 {
public:
    int find(vector<int> &representative, int vertex) {
        if (vertex == representative[vertex]) {
            return vertex;
        }
        
        return representative[vertex] = find(representative, representative[vertex]);
    }
    
    int combine(vector<int> &representative, vector<int> &size, int vertex1, int vertex2) {
        vertex1 = find(representative, vertex1);
        vertex2 = find(representative, vertex2);
        
        if (vertex1 == vertex2) {
            return 0;
        } else {
            
            if (size[vertex1] > size[vertex2]) {
                size[vertex1] += size[vertex2];
                representative[vertex2] = vertex1;
            } else {
                size[vertex2] += size[vertex1];
                representative[vertex1] = vertex2;
            }
            return 1;
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> representative(n), size(n);
        
        for (int i = 0; i < n; i++) {
            representative[i] = i;
            size[i] = 1;
        }
        
        int components = n;
        for (int i = 0; i < edges.size(); i++) {
            components -= combine(representative, size, edges[i][0], edges[i][1]);
        }

        return components;
    }
};

int main() {
auto *so = new Solution_323_NumberofConnectedComponentsinanUndirectedGraph_2();
vector<int> nums{2, 7, 11, 15};
int target = 26;
string s = "aa";
vector<vector<int>> arrays;
CppUtils::print(s);
CppUtils::print_1d_vector(nums);
CppUtils::print_2d_vector(arrays);
return 0;
}
                    