## 301_RemoveInvalidParentheses
```
class Solution(object):

    def __init__(self):
        self.valid_expressions = None
        self.min_removed = None

    def reset(self):
        self.valid_expressions = set()
        self.min_removed = float("inf")

    """
        string: The original string we are recursing on.
        index: current index in the original string.
        left: number of left parentheses till now.
        right: number of right parentheses till now.
        ans: the resulting expression in this particular recursion.
        ignored: number of parentheses ignored in this particular recursion.
    """
    def remaining(self, string, index, left_count, right_count, expr, rem_count):
        # If we have reached the end of string.
        if index == len(string):

            # If the current expression is valid. The only scenario where it can be
            # invalid here is if left > right. The other way around we handled early on in the recursion.
            if left_count == right_count:

                if rem_count <= self.min_removed:
                    # This is the resulting expression.
                    # Strings are immutable in Python so we move around a list in the recursion
                    # and eventually join to get the final string.
                    possible_ans = "".join(expr)

                    # If the current count of brackets removed < current minimum, ignore
                    # previous answers and update the current minimum count.
                    if rem_count < self.min_removed:
                        self.valid_expressions = set()
                        self.min_removed = rem_count

                    self.valid_expressions.add(possible_ans)    
        else:        

            current_char = string[index]

            # If the current character is not a parenthesis, just recurse one step ahead.
            if current_char != '(' and  current_char != ')':
                expr.append(current_char)
                self.remaining(string, index + 1, left_count, right_count, expr, rem_count)
                expr.pop()
            else:
                # Else, one recursion is with ignoring the current character.
                # So, we increment the ignored counter and leave the left and right untouched.
                self.remaining(string, index + 1, left_count, right_count, expr, rem_count + 1)

                expr.append(current_char)

                # If the current parenthesis is an opening bracket, we consider it
                # and increment left and  move forward
                if string[index] == '(':
                    self.remaining(string, index + 1, left_count + 1, right_count, expr, rem_count)
                elif right_count < left_count:
                    # If the current parenthesis is a closing bracket, we consider it only if we
                    # have more number of opening brackets and increment right and move forward.
                    self.remaining(string, index + 1, left_count, right_count + 1, expr, rem_count)

                expr.pop()

    def removeInvalidParentheses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """

        # Reset the class level variables that we use for every test case.
        self.reset()

        # Recursive call
        self.remaining(s, 0, 0, 0, [], 0)
        return list(self.valid_expressions)
```
```
class Solution:
    def removeInvalidParentheses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """

        left = 0
        right = 0

        # First, we find out the number of misplaced left and right parentheses.
        for char in s:

            # Simply record the left one.
            if char == '(':
                left += 1
            elif char == ')':
                # If we don't have a matching left, then this is a misplaced right, record it.
                right = right + 1 if left == 0 else right

                # Decrement count of left parentheses because we have found a right
                # which CAN be a matching one for a left.
                left = left - 1 if left > 0 else left

        result = {}
        def recurse(s, index, left_count, right_count, left_rem, right_rem, expr):
            # If we reached the end of the string, just check if the resulting expression is
            # valid or not and also if we have removed the total number of left and right
            # parentheses that we should have removed.
            if index == len(s):
                if left_rem == 0 and right_rem == 0:
                    ans = "".join(expr)
                    result[ans] = 1
            else:

                # The discard case. Note that here we have our pruning condition.
                # We don't recurse if the remaining count for that parenthesis is == 0.
                if (s[index] == '(' and left_rem > 0) or (s[index] == ')' and right_rem > 0):
                    recurse(s, index + 1,
                            left_count,
                            right_count,
                            left_rem - (s[index] == '('),
                            right_rem - (s[index] == ')'), expr)

                expr.append(s[index])    

                # Simply recurse one step further if the current character is not a parenthesis.
                if s[index] != '(' and s[index] != ')':
                    recurse(s, index + 1,
                            left_count,
                            right_count,
                            left_rem,
                            right_rem, expr)
                elif s[index] == '(':
                    # Consider an opening bracket.
                    recurse(s, index + 1,
                            left_count + 1,
                            right_count,
                            left_rem,
                            right_rem, expr)
                elif s[index] == ')' and left_count > right_count:
                    # Consider a closing bracket.
                    recurse(s, index + 1,
                            left_count,
                            right_count + 1,
                            left_rem,
                            right_rem, expr)

                # Pop for backtracking.
                expr.pop()                 

        # Now, the left and right variables tell us the number of misplaced left and
        # right parentheses and that greatly helps pruning the recursion.
        recurse(s, 0, 0, 0, left, right, [])     
        return list(result.keys())
```
```
```
```
```
```
```
## 302_SmallestRectangleEnclosingBlackPixels
```
public class Solution {
    public int minArea(char[][] image, int x, int y) {
        int top = x, bottom = x;
        int left = y, right = y;
        for (x = 0; x < image.length; ++x) {
            for (y = 0; y < image[0].length; ++y) {
                if (image[x][y] == '1') {
                    top = Math.min(top, x);
                    bottom = Math.max(bottom, x + 1);
                    left = Math.min(left, y);
                    right = Math.max(right, y + 1);
                }
            }
        }
        return (right - left) * (bottom - top);
    }
}
```
```
public class Solution {
    private int top, bottom, left, right;
    public int minArea(char[][] image, int x, int y) {
        if(image.length == 0 || image[0].length == 0) return 0;
        top = bottom = x;
        left = right = y;
        dfs(image, x, y);
        return (right - left) * (bottom - top);
    }
    private void dfs(char[][] image, int x, int y){
        if(x < 0 || y < 0 || x >= image.length || y >= image[0].length ||
          image[x][y] == '0')
            return;
        image[x][y] = '0'; // mark visited black pixel as white
        top = Math.min(top, x);
        bottom = Math.max(bottom, x + 1);
        left = Math.min(left, y);
        right = Math.max(right, y + 1);
        dfs(image, x + 1, y);
        dfs(image, x - 1, y);
        dfs(image, x, y - 1);
        dfs(image, x, y + 1);
    }
}
```
```
public class Solution {
    public int minArea(char[][] image, int x, int y) {
        int m = image.length, n = image[0].length;
        int left = searchColumns(image, 0, y, 0, m, true);
        int right = searchColumns(image, y + 1, n, 0, m, false);
        int top = searchRows(image, 0, x, left, right, true);
        int bottom = searchRows(image, x + 1, m, left, right, false);
        return (right - left) * (bottom - top);
    }
    private int searchColumns(char[][] image, int i, int j, int top, int bottom, boolean whiteToBlack) {
        while (i != j) {
            int k = top, mid = (i + j) / 2;
            while (k < bottom && image[k][mid] == '0') ++k;
            if (k < bottom == whiteToBlack) // k < bottom means the column mid has black pixel
                j = mid; //search the boundary in the smaller half
            else
                i = mid + 1; //search the boundary in the greater half
        }
        return i;
    }
    private int searchRows(char[][] image, int i, int j, int left, int right, boolean whiteToBlack) {
        while (i != j) {
            int k = left, mid = (i + j) / 2;
            while (k < right && image[mid][k] == '0') ++k;
            if (k < right == whiteToBlack) // k < right means the row mid has black pixel
                j = mid;
            else
                i = mid + 1;
        }
        return i;
    }
}
```
```
```
```
```
## 303_RangeSumQuery-Immutable
```
class NumArray {

private int[] data;

public NumArray(int[] nums) {
    data = nums;
}

public int sumRange(int i, int j) {
    int sum = 0;
    for (int k = i; k <= j; k++) {
        sum += data[k];
    }
    return sum;
}
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(left,right);
 */
```
```
class NumArray {

private Map<Pair<Integer, Integer>, Integer> map = new HashMap<>();

public NumArray(int[] nums) {
    for (int i = 0; i < nums.length; i++) {
        int sum = 0;
        for (int j = i; j < nums.length; j++) {
            sum += nums[j];
            map.put(Pair.create(i, j), sum);
        }
    }
}

public int sumRange(int i, int j) {
    return map.get(Pair.create(i, j));
}
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(left,right);
 */
```
```
class NumArray {

private int[] sum;

public NumArray(int[] nums) {
    sum = new int[nums.length + 1];
    for (int i = 0; i < nums.length; i++) {
        sum[i + 1] = sum[i] + nums[i];
    }
}

public int sumRange(int i, int j) {
    return sum[j + 1] - sum[i];
}
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(left,right);
 */
```
```
```
```
```
## 304_RangeSumQuery2D-Immutable
```
class NumMatrix {
    private int[][] data;

    public NumMatrix(int[][] matrix) {
        data = matrix;
    }

    public int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int r = row1; r <= row2; r++) {
            for (int c = col1; c <= col2; c++) {
                sum += data[r][c];
            }
        }
        return sum;
    }
}
```
```
class NumMatrix {
    private int[][] dp;

    public NumMatrix(int[][] matrix) {
        if (matrix.length == 0 || matrix[0].length == 0) return;
        dp = new int[matrix.length][matrix[0].length + 1];
        for (int r = 0; r < matrix.length; r++) {
            for (int c = 0; c < matrix[0].length; c++) {
                dp[r][c + 1] = dp[r][c] + matrix[r][c];
            }
        }
    }

    public int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int row = row1; row <= row2; row++) {
            sum += dp[row][col2 + 1] - dp[row][col1];
        }
        return sum;
    }
}
```
```
class NumMatrix {
    private int[][] dp;

    public NumMatrix(int[][] matrix) {
        if (matrix.length == 0 || matrix[0].length == 0) return;
        dp = new int[matrix.length + 1][matrix[0].length + 1];
        for (int r = 0; r < matrix.length; r++) {
            for (int c = 0; c < matrix[0].length; c++) {
                dp[r + 1][c + 1] = dp[r + 1][c] + dp[r][c + 1] + matrix[r][c] - dp[r][c];
            }
        }
    }

    public int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2 + 1][col2 + 1] - dp[row1][col2 + 1] - dp[row2 + 1][col1] + dp[row1][col1];
    }
}
```
```
```
```
```
## 305_NumberofIslandsII
```
class Solution {
private:
  void dfs(vector<vector<char>>& grid, int r, int c, vector<vector<bool>>& visited) {
    int nr = grid.size();
    int nc = grid[0].size();

    if (r < 0 || c < 0 || r >= nr || c >= nc || grid[r][c] == '0' || visited[r][c]) return;

    visited[r][c] = true;
    dfs(grid, r - 1, c, visited);
    dfs(grid, r + 1, c, visited);
    dfs(grid, r, c - 1, visited);
    dfs(grid, r, c + 1, visited);
  }

  int numIslands(vector<vector<char>>& grid) {
    int nr = grid.size();
    int nc = grid[0].size();

    vector<vector<bool>> visited (nr, vector<bool>(nc, false));
    int num_islands = 0;
    for (int r = 0; r < nr; ++r) {
      for (int c = 0; c < nc; ++c) {
        if (grid[r][c] == '1' && !visited[r][c]) {
          ++num_islands;
          dfs(grid, r, c, visited);
        }
      }
    }

    return num_islands;
  }

public:
  vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
    vector<int> ans;
    vector<vector<char>> grid (m, vector<char>(n, '0'));
    for (auto pos : positions) {
      grid[pos.first][pos.second] = '1';
      ans.push_back(numIslands(grid));
    }

    return ans;
  }
};
```
```
class Solution {
public:
  vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
    vector<int> ans;
    unordered_map<int, int> land2id; // land index : island ID
    int num_islands = 0;
    int island_id = 0;
    for (auto pos : positions) {
      int r = pos.first;
      int c = pos.second;
      // check pos's neighbors to see if they are in the existing islands or not
      unordered_set<int> overlap; // how many existing islands overlap with 'pos'
      if (r - 1 >= 0 && land2id.count((r-1) * n + c)) overlap.insert(land2id[(r-1) * n + c]);
      if (r + 1 < m && land2id.count((r+1) * n + c)) overlap.insert(land2id[(r+1) * n + c]);
      if (c - 1 >= 0 && land2id.count(r * n + c - 1)) overlap.insert(land2id[r * n + c - 1]);
      if (c + 1 < n && land2id.count(r * n + c + 1)) overlap.insert(land2id[r * n + c + 1]);

      if (overlap.empty()) { // no overlap
        ++num_islands;
        land2id[r * n + c] = island_id++; // new island
      } else if (overlap.size() == 1) { // one overlap, just append
        auto it = overlap.begin();
        land2id[r * n + c] = *it;
      } else { // more than 1 overlaps, merge
        auto it = overlap.begin();
        int root_id = *it;
        for (auto& kv : land2id) { // update island id
          if (overlap.count(kv.second)) kv.second = root_id;
        }
        land2id[r * n + c] = root_id;
        num_islands -= (overlap.size() - 1);
      }

      ans.push_back(num_islands);
    }

    return ans;
  }
};
```
```
class UnionFind {
public:
  UnionFind(int N) {
    count = 0;
    for (int i = 0; i < N; ++i) {
      parent.push_back(-1);
      rank.push_back(0);
    }
  }

  bool isValid(int i) const {
    return parent[i] >= 0;
  }

  void setParent(int i) {
    parent[i] = i;
    ++count;
  }

  int find(int i) { // path compression
    if (parent[i] != i) parent[i] = find(parent[i]);
    return parent[i];
  }

  void Union(int x, int y) { // union with rank
    int rootx = find(x);
    int rooty = find(y);
    if (rootx != rooty) {
      if (rank[rootx] > rank[rooty]) parent[rooty] = rootx;
      else if (rank[rootx] < rank[rooty]) parent[rootx] = rooty;
      else {
        parent[rooty] = rootx; rank[rootx] += 1;
      }
      --count;
    }
  }

  int getCount() const {
    return count;
  }

private:
  vector<int> parent;
  vector<int> rank;
  int count; // # of connected components
};

class Solution {
public:
  vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
    vector<int> ans;
    UnionFind uf (m * n);

    for (auto& pos : positions) {
      int r = pos.first;
      int c = pos.second;
      // check pos's neighbors to see if they are in the existing islands or not
      vector<int> overlap; // how many existing islands overlap with 'pos'
      if (r - 1 >= 0 && uf.isValid((r-1) * n + c)) overlap.push_back((r-1) * n + c);
      if (r + 1 < m && uf.isValid((r+1) * n + c)) overlap.push_back((r+1) * n + c);
      if (c - 1 >= 0 && uf.isValid(r * n + c - 1)) overlap.push_back(r * n + c - 1);
      if (c + 1 < n && uf.isValid(r * n + c + 1)) overlap.push_back(r * n + c + 1);

      int index = r * n + c;
      uf.setParent(index);
      for (auto i : overlap) uf.Union(i, index);
      ans.push_back(uf.getCount());
    }

    return ans;
  }
};
```
```
class Solution {
  public List<Integer> numIslands2(int m, int n, int[][] positions) {
    List<Integer> ans = new ArrayList<>();
    HashMap<Integer, Integer> land2id = new HashMap<Integer, Integer>();
    int num_islands = 0;
    int island_id = 0;

    for (int[] pos : positions) {
      int r = pos[0], c = pos[1];
      Set<Integer> overlap = new HashSet<Integer>();

      if (r - 1 >= 0 && land2id.containsKey((r-1) * n + c)) {
        overlap.add(land2id.get((r-1) * n + c));
      }
      if (r + 1 < m && land2id.containsKey((r+1) * n + c)) {
        overlap.add(land2id.get((r+1) * n + c));
      }
      if (c - 1 >= 0 && land2id.containsKey(r * n + c - 1)) {
        overlap.add(land2id.get(r * n + c - 1));
      }
      if (c + 1 < n && land2id.containsKey(r * n + c + 1)) {
        overlap.add(land2id.get(r * n + c + 1));
      }

      if (overlap.isEmpty()) {
        ++num_islands;
        land2id.put(r * n + c, island_id++);
      } else if (overlap.size() == 1) {
        land2id.put(r * n + c, overlap.iterator().next());
      } else {
        int root_id = overlap.iterator().next();
        for (Map.Entry<Integer, Integer> entry : land2id.entrySet()) {
          int k = entry.getKey();
          int id = entry.getValue();
          if (overlap.contains(id)) {
            land2id.put(k, root_id);
          }
        }
        land2id.put(r * n + c, root_id);
        num_islands -= (overlap.size() - 1);
      }
      ans.add(num_islands);
    }

    return ans;
  }
}
```
```
class Solution {   
  class UnionFind {
    int count; // # of connected components
    int[] parent;
    int[] rank;

    public UnionFind(char[][] grid) { // for problem 200
      count = 0;
      int m = grid.length;
      int n = grid[0].length;
      parent = new int[m * n];
      rank = new int[m * n];
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (grid[i][j] == '1') {
            parent[i * n + j] = i * n + j;
            ++count;
          }
          rank[i * n + j] = 0;
        }
      }
    }

    public UnionFind(int N) { // for problem 305 and others
      count = 0;
      parent = new int[N];
      rank = new int[N];
      for (int i = 0; i < N; ++i) {
        parent[i] = -1;
        rank[i] = 0;
      }
    }

    public boolean isValid(int i) { // for problem 305
      return parent[i] >= 0;
    }

    public void setParent(int i) {
      parent[i] = i;
      ++count;
    }

    public int find(int i) { // path compression
      if (parent[i] != i) parent[i] = find(parent[i]);
      return parent[i];
    }

    public void union(int x, int y) { // union with rank
      int rootx = find(x);
      int rooty = find(y);
      if (rootx != rooty) {
        if (rank[rootx] > rank[rooty]) {
          parent[rooty] = rootx;
        } else if (rank[rootx] < rank[rooty]) {
          parent[rootx] = rooty;
        } else {
          parent[rooty] = rootx; rank[rootx] += 1;
        }
        --count;
      }
    }

    public int getCount() {
      return count;
    }
  }

  public List<Integer> numIslands2(int m, int n, int[][] positions) {
    List<Integer> ans = new ArrayList<>();
    UnionFind uf = new UnionFind(m * n);

    for (int[] pos : positions) {
      int r = pos[0], c = pos[1];
      List<Integer> overlap = new ArrayList<>();

      if (r - 1 >= 0 && uf.isValid((r-1) * n + c)) overlap.add((r-1) * n + c);
      if (r + 1 < m && uf.isValid((r+1) * n + c)) overlap.add((r+1) * n + c);
      if (c - 1 >= 0 && uf.isValid(r * n + c - 1)) overlap.add(r * n + c - 1);
      if (c + 1 < n && uf.isValid(r * n + c + 1)) overlap.add(r * n + c + 1);

      int index = r * n + c;
      uf.setParent(index);
      for (int i : overlap) uf.union(i, index);
      ans.add(uf.getCount());
    }

    return ans;
  }
}
```
```
class Solution {
int[][] dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

public List<Integer> numIslands2(int m, int n, int[][] positions) {
    List<Integer> result = new ArrayList<>();
    if(m <= 0 || n <= 0) return result;

    int count = 0;                      // number of islands
    int[] roots = new int[m * n];       // one island = one tree
    Arrays.fill(roots, -1);            

    for(int[] p : positions) {
        int root = n * p[0] + p[1];     // assume new point is isolated island
        roots[root] = root;             // add new island
        count++;

        for(int[] dir : dirs) {
            int x = p[0] + dir[0]; 
            int y = p[1] + dir[1];
            int nb = n * x + y;
            if(x < 0 || x >= m || y < 0 || y >= n || roots[nb] == -1) continue;
            
            int rootNb = findIsland(roots, nb);
            if(root != rootNb) {        // if neighbor is in another island
                roots[root] = rootNb;   // union two islands 
                root = rootNb;          // current tree root = joined tree root
                count--;               
            }
        }

        result.add(count);
    }
    return result;
}

public int findIsland(int[] roots, int id) {
    while(id != roots[id]) id = roots[id];
    return id;
}
}
```



## 306_AdditiveNumber

```
class Solution {
public:
        bool isAdditiveNumber(string num) {
            for(int i=1; i<=num.size()/2; i++){
                for(int j=1; j<=(num.size()-i)/2; j++){
                    if(check(num.substr(0,i), num.substr(i,j), num.substr(i+j))) return true;
                }
            }
            return false;
        }
        bool check(string num1, string num2, string num){
            if(num1.size()>1 && num1[0]=='0' || num2.size()>1 && num2[0]=='0') return false;
            string sum=add(num1, num2);
            if(num==sum) return true;
            if(num.size()<=sum.size() || sum.compare(num.substr(0,sum.size()))!=0) return false;
            else return check(num2, sum, num.substr(sum.size()));
        } 
        string add(string n, string m){
            string res;
            int i=n.size()-1, j=m.size()-1, carry=0;
            while(i>=0 || j>=0){
                int sum=carry+(i>=0 ? (n[i--]-'0') : 0) + (j>=0?  (m[j--]-'0') : 0);
                res.push_back(sum%10+'0');
                carry=sum/10;
            }
            if(carry) res.push_back(carry+'0');
            reverse(res.begin(), res.end());
            return res;
        }
    };
```
```
```
```
```
```
```
```
```
## 307_RangeSumQuery-Mutable
```
private int[] nums;
public int sumRange(int i, int j) {
    int sum = 0;
    for (int l = i; l <= j; l++) {
        sum += data[l];
    }
    return sum;
}

public int update(int i, int val) {
    nums[i] = val;
}
// Time Limit Exceeded
```
```
class NumArray {

private int[] b;
private int len;
private int[] nums;

public NumArray(int[] nums) {
    this.nums = nums;
    double l = Math.sqrt(nums.length);
    len = (int) Math.ceil(nums.length/l);
    b = new int [len];
    for (int i = 0; i < nums.length; i++)
        b[i / len] += nums[i];
}

public int sumRange(int i, int j) {
    int sum = 0;
    int startBlock = i / len;
    int endBlock = j / len;
    if (startBlock == endBlock) {
        for (int k = i; k <= j; k++)
            sum += nums[k];
    } else {
        for (int k = i; k <= (startBlock + 1) * len - 1; k++)
            sum += nums[k];
        for (int k = startBlock + 1; k <= endBlock - 1; k++)
            sum += b[k];
        for (int k = endBlock * len; k <= j; k++)
            sum += nums[k];
    }
    return sum;
}

public void update(int i, int val) {
    int b_l = i / len;
    b[b_l] = b[b_l] - nums[i] + val;
    nums[i] = val;
}
// Accepted
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(index,val);
 * int param_2 = obj.sumRange(left,right);
 */
```
```

```
```

```
```

```
## 308_RangeSumQuery2D-Mutable
```
class NumMatrix {
private:
    int rows, cols;
    vector<vector<int>> bit; // The BIT matrix

    int lsb(int n) {
        // the line below allows us to directly capture the right most non-zero bit of a number
        return n & (-n);
    }

    void updateBIT(int r, int c, int val) {
        // keep adding lsb(i) to i, lsb(j) to j and add val to bit[i][j]
        // Using two nested for loops, one for the rows and one for the columns
        for (int i = r; i <= rows; i += lsb(i)) {
            for (int j = c; j <= cols; j += lsb(j)) {
                this->bit[i][j] += val;
            }
        }
    }

    int queryBIT(int r, int c) {
        int sum = 0;
        // keep subtracting lsb(i) to i, lsb(j) to j and obtain the final sum as the sum of non-overlapping sub-rectangles
        // Using two nested for loops, one for the rows and one for the columns
        for (int i = r; i > 0; i -= lsb(i)) {
            for (int j = c; j > 0; j -= lsb(j)) {
                sum += this->bit[i][j];
            }
        }
        return sum;
    }

    void buildBIT(vector<vector<int>> &matrix) {
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                // call update function on each of the entries present in the matrix
                int val = matrix[i - 1][j - 1];
                updateBIT(i, j, val);
            }
        }
    }

public:

    NumMatrix(vector<vector<int>>& matrix) {
        rows = matrix.size();
        if (!rows) return;
        cols = matrix[0].size();
        bit.resize(rows + 1);
        // Using 1 based indexing, hence resizing the bit array to (rows + 1, cols + 1)
        for (int i = 1; i <= rows; ++i)
            bit[i].resize(cols + 1, 0);
        buildBIT(matrix);
    }

    void update(int row, int col, int val) {
        int old_val = sumRegion(row, col, row, col);
        // handling 1-based indexing
        row++; col++;
        int diff = val - old_val;
        updateBIT(row, col, diff);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        // handling 1-based indexing
        row1++; col1++; row2++; col2++;
        int a = queryBIT(row2, col2);
        int b = queryBIT(row1 - 1, col1 - 1);
        int c = queryBIT(row2, col1 - 1);
        int d = queryBIT(row1 - 1, col2);
        return (a + b) - (c + d);
    }
};
```
```
```
```
```
```
```
```
```
## 309_BestTimetoBuyandSellStockwithCooldown
```
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        sold, held, reset = float('-inf'), float('-inf'), 0

        for price in prices:
            # Alternative: the calculation is done in parallel.
            # Therefore no need to keep temporary variables
            #sold, held, reset = held + price, max(held, reset-price), max(reset, sold)

            pre_sold = sold
            sold = held + price
            held = max(held, reset - price)
            reset = max(reset, pre_sold)

        return max(sold, reset)
```
```
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        L = len(prices)
        # padding the array with additional zero to simply the logic
        MP = [0] * (L + 2)

        for i in range(L-1, -1, -1):
            C1 = 0
            # Case 1). buy and sell the stock
            for sell in range(i + 1, L):
                profit = (prices[sell] - prices[i]) + MP[sell + 2]
                C1 = max(profit, C1)

            # Case 2). do no transaction with the stock p[i]
            C2 = MP[i + 1]

            # sum up two cases
            MP[i] = max(C1, C2)

        return MP[0]
```
```
```
```
```
```
```
## 310_MinimumHeightTrees
```
class Solution:
    def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:

        # edge cases
        if n <= 2:
            return [i for i in range(n)]

        # Build the graph with the adjacency list
        neighbors = [set() for i in range(n)]
        for start, end in edges:
            neighbors[start].add(end)
            neighbors[end].add(start)

        # Initialize the first layer of leaves
        leaves = []
        for i in range(n):
            if len(neighbors[i]) == 1:
                leaves.append(i)

        # Trim the leaves until reaching the centroids
        remaining_nodes = n
        while remaining_nodes > 2:
            remaining_nodes -= len(leaves)
            new_leaves = []
            # remove the current leaves along with the edges
            while leaves:
                leaf = leaves.pop()
                # the only neighbor left for the leaf node
                neighbor = neighbors[leaf].pop()
                # remove the only edge left
                neighbors[neighbor].remove(leaf)
                if len(neighbors[neighbor]) == 1:
                    new_leaves.append(neighbor)

            # prepare for the next round
            leaves = new_leaves

        # The remaining nodes are the centroids of the graph
        return leaves
```
```
```
```
```
```
```
```
```
## 311_SparseMatrixMultiplication
```
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int n = mat1.size();
        int k = mat1[0].size();
        int m = mat2[0].size();
        
        // Product matrix will have 'n x m' size.
        vector<vector<int>> ans (n, vector<int>(m, 0));
        
        for (int rowIndex = 0; rowIndex < n; ++rowIndex) {
            for (int elementIndex = 0; elementIndex < k; ++elementIndex) {
                // If current element of mat1 is non-zero then iterate over all columns of mat2.
                if (mat1[rowIndex][elementIndex] != 0)  {
                    for (int colIndex = 0; colIndex < m; ++colIndex) {
                        ans[rowIndex][colIndex] += mat1[rowIndex][elementIndex] * mat2[elementIndex][colIndex];
                    }
                }
            }
        }
        
        return ans;
    }
};
```
```
class Solution {
public:
    vector<vector<pair<int, int>>> compressMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<pair<int, int>>> compressedMatrix(rows);
        
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (matrix[row][col] != 0) {
                    compressedMatrix[row].push_back({matrix[row][col], col}); 
                }
            }
        }
        return compressedMatrix;
    }
    
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int m = mat1.size();
        int k = mat1[0].size();
        int n = mat2[0].size();
        
        // Store the non-zero values of each matrix.
        vector<vector<pair<int, int>>> A = compressMatrix(mat1);
        vector<vector<pair<int, int>>> B = compressMatrix(mat2);
        
        vector<vector<int>> ans(m, vector<int>(n, 0));
        
        for (int mat1Row = 0; mat1Row < m; ++mat1Row) {
            // Iterate on all current 'row' non-zero elements of mat1.
            for (auto [element1, mat1Col] : A[mat1Row]) {

                // Multiply and add all non-zero elements of mat2
                // where the row is equal to col of current element of mat1.
                for (auto [element2, mat2Col] : B[mat1Col]) {
                    ans[mat1Row][mat2Col] += element1 * element2;
                }
            }
        }
        
        return ans;
    }
};
```
```
class SparseMatrix {
public:
    int cols = 0, rows = 0;
    vector<int> values, colIndex, rowIndex;

    // Compressed Sparse Row
    SparseMatrix(vector<vector<int>>& matrix) {
        rows = matrix.size();
        cols = matrix[0].size(); 
        rowIndex.push_back(0);
        
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (matrix[row][col]) {
                    values.push_back(matrix[row][col]);
                    colIndex.push_back(col);
                }
            }
            rowIndex.push_back(values.size());
        }
    }

    // Compressed Sparse Column
    SparseMatrix(vector<vector<int>>& matrix, bool colWise) {
        rows = matrix.size();
        cols = matrix[0].size();
        colIndex.push_back(0);
        
        for (int col = 0; col < cols; ++col) {
            for (int row = 0; row < rows; ++row) {
                if (matrix[row][col]) {
                    values.push_back(matrix[row][col]);
                    rowIndex.push_back(row);
                }
            }
            colIndex.push_back(values.size());
        }
    }
};

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        SparseMatrix A (mat1); 
        SparseMatrix B (mat2, true);
        
        vector<vector<int>> ans(mat1.size(), vector<int>(mat2[0].size(), 0));
        
        for (int row = 0; row < ans.size(); ++row) {
            for (int col = 0; col < ans[0].size(); ++col) {
                
                // Row element range indices
                int matrixOneRowStart = A.rowIndex[row];
                int matrixOneRowEnd = A.rowIndex[row + 1];
                
                // Column element range indices
                int matrixTwoColStart = B.colIndex[col];
                int matrixTwoColEnd = B.colIndex[col + 1];
                
                // Iterate over both row and column.
                while (matrixOneRowStart < matrixOneRowEnd && matrixTwoColStart < matrixTwoColEnd) {
                    if (A.colIndex[matrixOneRowStart] < B.rowIndex[matrixTwoColStart]) {
                        matrixOneRowStart++;
                    } else if (A.colIndex[matrixOneRowStart] > B.rowIndex[matrixTwoColStart]) {
                        matrixTwoColStart++;
                    } else {
                        // Row index and col index are same so we can multiply these elements.
                        ans[row][col] += A.values[matrixOneRowStart] * B.values[matrixTwoColStart];
                        matrixOneRowStart++;
                        matrixTwoColStart++;
                    }
                }
            }
        }
        
        return ans;
    }
};
```
```
```
```
```
## 312_BurstBalloons
```
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // add 1 before and after nums
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        // cache the results of dp
        vector<vector<int>> memo(nums.size(), vector<int>(nums.size(), 0));
        // we can not burst the first one and the last one
        // since they are both fake balloons added by ourselves
        return dp(memo, nums, 1, nums.size() - 2);
    }
	
    int dp(vector<vector<int>>& memo, vector<int>& nums, int left, int right) {
        // return maximum if we burst all nums[left]...nums[right], inclusive
        if (right - left < 0) {
            return 0;
        }

        // we've already seen this, return from cache
        if (memo[left][right] > 0) {
            return memo[left][right];
        }

        // find the last burst one in nums[left]...nums[right]
        int result = 0;
        for (int i = left; i <= right; i++) {
            // nums[i] is the last burst one
            int gain = nums[left - 1] * nums[i] * nums[right + 1];
            // nums[i] is fixed, recursively call left side and right side
            int remaining = dp(memo, nums, left, i - 1) + dp(memo, nums, i + 1, right);
            result = max(result, remaining + gain);
        }
        // add to the cache
        memo[left][right] = result;
        return result;
    }
};
```
```
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // add 1 before and after nums
        nums.insert(nums.begin(), 1);
        nums.emplace_back(1);
        // dp[i][j] represents
        // maximum if we burst all nums[left]...nums[right], inclusive
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
        // do not include the first one and the last one
        // since they are both fake balloons added by ourselves and we can not burst them
        for (int left = nums.size() - 2; left >= 1; left--) {
            for (int right = left; right <= nums.size() - 2; right++) {
                // find the last burst one in nums[left]...nums[right]
                for (int i = left; i <= right; i++) {
                    // nums[i] is the last burst one
                    int gain = nums[left - 1] * nums[i] * nums[right + 1];
                    // recursively call left side and right side
                    int remaining = dp[left][i - 1] + dp[i + 1][right];
                    // update
                    dp[left][right] = max(remaining + gain, dp[left][right]);
                }
            }
        }
        // burst newNums[1]...newNums[n-2], excluding the first one and the last one
        return dp[1][nums.size() - 2];
    }
};
```
```
```
```
```
```
```
## 313_SuperUglyNumber
```
class Solution {
public:
int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int>arri(primes.size());
  vector<long>arrn(primes.size());
    vector<long>dp(n+1);
    dp[0]=1;
    for(int j=0;j<n;j++){
        long  mini=INT_MAX;
        for(int i=0;i<arri.size();i++){
            arrn[i]=dp[arri[i]]*primes[i];
            mini=min(mini,arrn[i]);
        }
      for(int i=0;i<arri.size();i++){
          if(mini==arrn[i]){
              dp[j+1]=arrn[i];
              arri[i]++;
          }
      }
  
    }

  return dp[n-1]; 
}
};
```
```
```
```
```
```
```
```
```
## 314_BinaryTreeVerticalOrderTraversal
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import defaultdict
class Solution:
    def verticalOrder(self, root: TreeNode) -> List[List[int]]:
        columnTable = defaultdict(list)
        queue = deque([(root, 0)])

        while queue:
            node, column = queue.popleft()

            if node is not None:
                columnTable[column].append(node.val)
                
                queue.append((node.left, column - 1))
                queue.append((node.right, column + 1))
                        
        return [columnTable[x] for x in sorted(columnTable.keys())]
```
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import defaultdict
class Solution:
    def verticalOrder(self, root: TreeNode) -> List[List[int]]:
        if root is None:
            return []

        columnTable = defaultdict(list)
        min_column = max_column = 0
        queue = deque([(root, 0)])

        while queue:
            node, column = queue.popleft()

            if node is not None:
                columnTable[column].append(node.val)
                min_column = min(min_column, column)
                max_column = max(max_column, column)

                queue.append((node.left, column - 1))
                queue.append((node.right, column + 1))

        return [columnTable[x] for x in range(min_column, max_column + 1)]
```
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import defaultdict
class Solution:
    def verticalOrder(self, root: TreeNode) -> List[List[int]]:
        if root is None:
            return []

        columnTable = defaultdict(list)
        min_column = max_column = 0

        def DFS(node, row, column):
            if node is not None:
                nonlocal min_column, max_column
                columnTable[column].append((row, node.val))
                min_column = min(min_column, column)
                max_column = max(max_column, column)

                # preorder DFS
                DFS(node.left, row + 1, column - 1)
                DFS(node.right, row + 1, column + 1)

        DFS(root, 0, 0)

        # order by column and sort by row
        ret = []
        for col in range(min_column, max_column + 1):
            columnTable[col].sort(key=lambda x:x[0])
            colVals = [val for row, val in columnTable[col]]
            ret.append(colVals)

        return ret
```
```
```
```
```
## 315_CountofSmallerNumbersAfterSelf
```
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int offset = 1e4;        // offset negative to non-negative
        int size = 2 * 1e4 + 1;  // total possible values in nums
        vector<int> tree(size * 2);
        vector<int> result;

        for (int i = nums.size() - 1; i >= 0; i--) {
            int smaller_count = query(0, nums[i] + offset, tree, size);
            result.push_back(smaller_count);
            update(nums[i] + offset, 1, tree, size);
        }
        reverse(result.begin(), result.end());
        return result;
    }

    // implement segment tree
    void update(int index, int value, vector<int>& tree, int size) {
        index += size;  // shift the index to the leaf
        // update from leaf to root
        tree[index] += value;
        while (index > 1) {
            index /= 2;
            tree[index] = tree[index * 2] + tree[index * 2 + 1];
        }
    }

    int query(int left, int right, vector<int>& tree, int size) {
        // return sum of [left, right)
        int result = 0;
        left += size;  // shift the index to the leaf
        right += size;
        while (left < right) {
            // if left is a right node
            // bring the value and move to parent's right node
            if (left % 2 == 1) {
                result += tree[left];
                left++;
            }
            // else directly move to parent
            left /= 2;
            // if right is a right node
            // bring the value of the left node and move to parent
            if (right % 2 == 1) {
                right--;
                result += tree[right];
            }
            // else directly move to parent
            right /= 2;
        }
        return result;
    }
};
```
```
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int offset = 1e4;        // offset negative to non-negative
        int size = 2 * 1e4 + 2;  // total possible values in nums plus one dummy
        vector<int> tree(size);
        vector<int> result;

        for (int i = nums.size() - 1; i >= 0; i--) {
            int smaller_count = query(nums[i] + offset, tree);
            result.push_back(smaller_count);
            update(nums[i] + offset, 1, tree, size);
        }
        reverse(result.begin(), result.end());
        return result;
    }

    // implement Binary Index Tree
    void update(int index, int value, vector<int>& tree, int size) {
        index++;  // index in BIT is 1 more than the original index
        while (index < size) {
            tree[index] += value;
            index += index & -index;
        }
    }

    int query(int index, vector<int>& tree) {
        // return sum of [0, index)
        int result = 0;
        while (index >= 1) {
            result += tree[index];
            index -= index & -index;
        }
        return result;
    }
};
```
```
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        vector<int> indices(n);  // record the index. we are going to sort this array
        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }
        // sort indices with their corresponding values in nums, i.e., nums[indices[i]]
        mergeSort(indices, 0, n, result, nums);
        return result;
    }

    void mergeSort(vector<int>& indices, int left, int right, vector<int>& result,
                   vector<int>& nums) {
        if (right - left <= 1) {
            return;
        }
        int mid = (left + right) / 2;
        mergeSort(indices, left, mid, result, nums);
        mergeSort(indices, mid, right, result, nums);
        merge(indices, left, right, mid, result, nums);
    }

    void merge(vector<int>& indices, int left, int right, int mid, vector<int>& result,
               vector<int>& nums) {
        // merge [left, mid) and [mid, right)
        int i = left;  // current index for the left array
        int j = mid;   // current index for the right array
        // use temp to temporarily store sorted array
        vector<int> temp;
        while (i < mid && j < right) {
            if (nums[indices[i]] <= nums[indices[j]]) {
                // j - mid numbers jump to the left side of indices[i]
                result[indices[i]] += j - mid;
                temp.push_back(indices[i]);
                i++;
            } else {
                temp.push_back(indices[j]);
                j++;
            }
        }
        // when one of the subarrays is empty
        while (i < mid) {
            // j - mid numbers jump to the left side of indices[i]
            result[indices[i]] += j - mid;
            temp.push_back(indices[i]);
            i++;
        }
        while (j < right) {
            temp.push_back(indices[j]);
            j++;
        }
        // restore from temp
        move(temp.begin(), temp.end(), indices.begin() + left);
    }
};
```
```
```
```
```
## 316_RemoveDuplicateLetters
```
from collections import Counter

class Solution:
    def removeDuplicateLetters(self, s: str) -> str:

        # find pos - the index of the leftmost letter in our solution
        # we create a counter and end the iteration once the suffix doesn't have each unique character
        # pos will be the index of the smallest character we encounter before the iteration ends
        c = Counter(s)
        pos = 0
        for i in range(len(s)):
            if s[i] < s[pos]: pos = i
            c[s[i]] -=1
            if c[s[i]] == 0: break
        # our answer is the leftmost letter plus the recursive call on the remainder of the string
        # note we have to get rid of further occurrences of s[pos] to ensure that there are no duplicates
        return s[pos] + self.removeDuplicateLetters(s[pos:].replace(s[pos], "")) if s else ''

```
```
class Solution:
    def removeDuplicateLetters(self, s) -> int:

        stack = []

        # this lets us keep track of what's in our solution in O(1) time
        seen = set()

        # this will let us know if there are no more instances of s[i] left in s
        last_occurrence = {c: i for i, c in enumerate(s)}


        for i, c in enumerate(s):

            # we can only try to add c if it's not already in our solution
            # this is to maintain only one of each character
            if c not in seen:
                # if the last letter in our solution:
                #    1. exists
                #    2. is greater than c so removing it will make the string smaller
                #    3. it's not the last occurrence
                # we remove it from the solution to keep the solution optimal
                while stack and c < stack[-1] and i < last_occurrence[stack[-1]]:
                    seen.discard(stack.pop())
                seen.add(c)
                stack.append(c)
        return ''.join(stack)

```
```
```
```
```
```
```
## 317_ShortestDistancefromAllBuildings
```
class Solution {
private:
    int bfs(vector<vector<int>>& grid, int row, int col, int totalHouses) {
        // Next four directions.
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        int rows = grid.size();
        int cols = grid[0].size();
        int distanceSum = 0;
        int housesReached = 0;

        // Queue to do a bfs, starting from (r,c) cell
        queue<pair<int, int>> q;
        q.push({ row, col });

        // Keep track of visited cells
        vector<vector<bool>> vis(rows, vector<bool> (cols, false));
        vis[row][col] = true;

        int steps = 0;

        while (!q.empty() && housesReached != totalHouses) {
            for (int i = q.size(); i > 0; --i) {
                auto curr = q.front();
                q.pop();

                row = curr.first;
                col = curr.second;

                // If this cell is a house, then add the distance from the source to this cell
                // and we go past from this cell.
                if (grid[row][col] == 1) {
                    distanceSum += steps;
                    housesReached++;
                    continue;
                }

                // This cell was an empty cell, hence traverse the next cells which is not a blockage.
                for (auto& dir : dirs) {
                    int nextRow = row + dir[0];
                    int nextCol = col + dir[1];

                    if (nextRow >= 0 && nextCol >= 0 && nextRow < rows && nextCol < cols) {
                        if (!vis[nextRow][nextCol] && grid[nextRow][nextCol] != 2) {
                            vis[nextRow][nextCol] = true;
                            q.push({nextRow, nextCol});
                        }
                    }
                }
            }
            
            // After traversing one level cells, increment the steps by 1 to reach to next level.
            steps++;
        }

        // If we did not reach all houses, then any cell visited also cannot reach all houses.
        // Set all cells visted to 2 so we do not check them again and return INT_MAX.
        if (housesReached != totalHouses) {
            for (row = 0; row < rows; row++) {
                for (col = 0; col < cols; col++) {
                    if (grid[row][col] == 0 && vis[row][col]) {
                        grid[row][col] = 2;
                    }
                }
            }
            return INT_MAX;
        }
        // If we have reached all houses then return the total distance calculated.
        return distanceSum;
    }

public:
    int shortestDistance(vector<vector<int>>& grid) {
        int minDistance = INT_MAX;
        int rows = grid.size();
        int cols = grid[0].size();
        int totalHouses = 0;

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 1) { 
                    totalHouses++;
                }
            }
        }

        // Find the min distance sum for each empty cell.
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 0) {
                    minDistance = min(minDistance, bfs(grid, row, col, totalHouses));
                }
            }
        }

        // If it is impossible to reach all houses from any empty cell, then return -1.
        if (minDistance == INT_MAX) {
            return -1;
        }
        return minDistance;
    }
};
```
```
class Solution {
private:
    void bfs(vector<vector<int>>& grid, vector<vector<vector<int>>>& distances, int row, int col) {
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        int rows = grid.size(), cols = grid[0].size();
        
        // Queue to do a bfs, starting from each cell located at (r,c).
        queue<pair<int, int>> q;
        q.push({ row, col });
        
        // Keep track of visited cells.
        vector<vector<bool>> vis (rows, vector<bool>(cols, false));
        vis[row][col] = true;
        
        int steps = 0;
        
        while (!q.empty()) {
            for (int i = q.size(); i > 0; --i) {
                auto curr = q.front();
                q.pop();
                row = curr.first;
                col = curr.second;
                
                // If we reached an empty cell, then add the distance
                // and increment the count of houses reached at this cell.
                if (grid[row][col] == 0) {
                    distances[row][col][0] += steps;
                    distances[row][col][1] += 1;
                }
                
                // Traverse the next cells which is not a blockage.
                for (auto& dir : dirs) {
                    int nextRow = row + dir[0];
                    int nextCol = col + dir[1];
                    if (nextRow >= 0 && nextCol >= 0 && nextRow < rows && nextCol < cols) {
                        if (!vis[nextRow][nextCol] && grid[nextRow][nextCol] == 0) {
                            vis[nextRow][nextCol] = true;
                            q.push({ nextRow, nextCol });
                        }
                    }
                }
            }
            
            // After traversing one level cells, increment the steps by 1.
            steps++;
        }
    }
    
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int minDistance = INT_MAX;
        int rows = grid.size();
        int cols = grid[0].size();
        int totalHouses = 0;
        
        // Store { total_dist, houses_count } for each cell.
        vector<vector<vector<int>>> distances (rows, vector<vector<int>> (cols, {0, 0}));
        
        // Count houses and start bfs from each house.
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (grid[row][col] == 1) {
                    totalHouses++;
                    bfs(grid, distances, row, col);
                }
            }
        }
        
        // Check all empty lands with houses count equal to total houses and find the min ans.
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (distances[row][col][1] == totalHouses) {
                    minDistance = min(minDistance, distances[row][col][0]);
                }
            }
        }
        
        // If we haven't found a valid cell return -1.
        if (minDistance == INT_MAX) {
            return -1;
        }
        return minDistance;
    }
};
```
```
class Solution {
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
```
```
```
```
```
## 318_MaximumProductofWordLengths
```
class Solution:
    def maxProduct(self, words: List[str]) -> int:
        def no_common_letters(s1, s2):
            # TODO
            
        n = len(words)
        max_prod = 0
        for i in range(n):
            for j in range(i + 1, n):
                if no_common_letters(words[i], words[j]):
                    max_prod = max(max_prod, len(words[i]) * len(words[j]))
        return max_prod
```
```
class Solution:
    def maxProduct(self, words: List[str]) -> int:
        n = len(words)
        masks = [0] * n
        lens = [0] * n
        bit_number = lambda ch : ord(ch) - ord('a')
        
        for i in range(n):
            bitmask = 0
            for ch in words[i]:
                # add bit number bit_number in bitmask
                bitmask |= 1 << bit_number(ch)
            masks[i] = bitmask
            lens[i] = len(words[i])
            
        max_val = 0
        for i in range(n):
            for j in range(i + 1, n):
                if masks[i] & masks[j] == 0:
                    max_val = max(max_val, lens[i] * lens[j])
        return max_val
```
```
from collections import defaultdict
class Solution:
    def maxProduct(self, words: List[str]) -> int:
        hashmap = defaultdict(int)
        bit_number = lambda ch : ord(ch) - ord('a')
        
        for word in words:
            bitmask = 0
            for ch in word:
                # add bit number bit_number in bitmask
                bitmask |= 1 << bit_number(ch)
            # there could be different words with the same bitmask
            # ex. ab and aabb
            hashmap[bitmask] = max(hashmap[bitmask], len(word))
        
        max_prod = 0
        for x in hashmap:
            for y in hashmap:
                if x & y == 0:
                    max_prod = max(max_prod, hashmap[x] * hashmap[y])
        return max_prod
```
```
```
```
```
## 319_BulbSwitcher
```
class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};
```
```
```
```
```
```
```
```
```
## 320_GeneralizedAbbreviation
```
public class Solution {
    public List<String> generateAbbreviations(String word){
        List<String> ans = new ArrayList<String>();
        backtrack(ans, new StringBuilder(), word, 0, 0);
        return ans;
    }

    // i is the current position
    // k is the count of consecutive abbreviated characters
    private void backtrack(List<String> ans, StringBuilder builder, String word, int i, int k){
        int len = builder.length(); // keep the length of builder
        if(i == word.length()){
            if (k != 0) builder.append(k); // append the last k if non zero
            ans.add(builder.toString());
        } else {
            // the branch that word.charAt(i) is abbreviated
            backtrack(ans, builder, word, i + 1, k + 1);

            // the branch that word.charAt(i) is kept
            if (k != 0) builder.append(k);
            builder.append(word.charAt(i));
            backtrack(ans, builder, word, i + 1, 0);
        }
        builder.setLength(len); // reset builder to the original state
    }
}
```
```
public class Solution {
    public List<String> generateAbbreviations(String word) {
        List<String> ans = new ArrayList<>();
        for (int x = 0; x < (1 << word.length()); ++x) // loop through all possible x
            ans.add(abbr(word, x));
        return ans;
    }

    // build the abbreviation for word from number x
    private String abbr(String word, int x) {
        StringBuilder builder = new StringBuilder();
        int k = 0, n = word.length(); // k is the count of consecutive ones in x
        for (int i = 0; i < n; ++i, x >>= 1) {
            if ((x & 1) == 0) { // bit is zero, we keep word.charAt(i)
                if (k != 0) { // we have abbreviated k characters
                    builder.append(k);
                    k = 0; // reset the counter k
                }
                builder.append(word.charAt(i));
            }
            else // bit is one, increase k
                ++k;
        }
        if (k != 0) builder.append(k); //don't forget to append the last k if non zero
        return builder.toString();
    }
}
```
```
```
```
```
```
```
## 321_CreateMaximumNumber
```
class Solution {
public:
    #define MIN(a,b) (a<b?a:b)
    #define MAX(a,b) (a>b?a:b)
    // create max number of length t from single non-empty vector
    void getMax(int* num, int& len, int* result, int& t, int& sortedLen)
    {
    	int n, top = 0;
    	result[0] = num[0];
    	const int need2drop = len - t;
    	for (int i = 1; i < len; ++i){
    		n = num[i];
    		while (top >= 0 && result[top] < n && (i - top) <= need2drop) --top; // i - top means already dropped i - top numbers
    		if (i - top > need2drop){
    			sortedLen = MAX(1,top);
    			while (++top < t) result[top] = num[i++];
    			return;
    		}
    		if (++top < t) result[top] = n;
    		else top = t - 1;
    	}
    }
    // create max number of different length from single vector
    void dp(int *num, int len, int&sortedLen, int& minL, int& maxL, int *res, int &k){
    	int  j, *head, *prevhead = res;
    	const int soi = sizeof(int);
    	getMax(num, len, res, maxL,sortedLen);
    	for (int l = maxL; l > MAX(minL,1); --l){
    		head = prevhead + k;
    		memcpy(head, prevhead, l*soi);
    		for (j = sortedLen; j < l; ++j){
    			if (head[j] > head[j - 1]){
    				sortedLen = MAX(1, j - 1);
    				memcpy(head + j - 1, prevhead + j, soi*(l - j));
    				break;
    			}
    		}
    		if (j == l) sortedLen = l;
    		prevhead = head;
    	}
    }
    // merge max number created from single vector
    void merge(int* num1,int len1,int* num2,int len2,int* result,int& resSize){
    	int i = 0, j = 0, k = 0;
    	while (i < resSize){
    		if (j < len1 && k < len2){
    			if (num1[j] > num2[k])
    				result[i++] = num1[j++];
    			else if (num1[j] < num2[k])
    				result[i++] = num2[k++];
    			else{
    				int remaining1 = len1 - j, remaining2 = len2 - k, tmp = num1[j];
    				int flag = memcmp(num1 + j, num2 + k, sizeof(int) * MIN(remaining1, remaining2));
    				flag = (flag == 0 ? (remaining1>remaining2 ? 1 : -1) : flag);
    				int * num = flag > 0 ? num1 : num2;
    				int & cnt = flag > 0 ? j : k;
    				int len = flag > 0 ? len1 : len2;
    				while (num[cnt]==tmp && cnt < len && i<resSize) result[i++] = num[cnt++];
    			}
    		}
    		else if (j < len1) result[i++] = num1[j++];
    		else result[i++] = num2[k++];
    	}
    }
    
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k){
    	int soi = sizeof(int), len1 = nums1.size(), len2 = nums2.size(), step = k*soi;
    	int minL1 = MAX(0, k - len2), maxL1 = MIN(k, len1), minL2 = k - maxL1, maxL2 = k - minL1, range = maxL1 - minL1 + 1;
    	int * res = new int[range * k * 2 + 2 * k], *dp1 = res + k, *dp2 = res + range*k+k, *tmp=res+range*2*k+k;
    	memset(res, 0, step);
    	int sortedLen1 = 1, sortedLen2 = 1;
    	if (len1 == 0 && len2 > 0) getMax(&nums2[0], len2, res, k, sortedLen2);
    	else if (len1 > 0 && len2 == 0) getMax(&nums1[0], len1, res, k, sortedLen2);
    	else if (len1 > 0 && len2 > 0){
    		dp(&nums1[0], len1, sortedLen1, minL1, maxL1, dp1,k);
    		dp(&nums2[0], len2, sortedLen2, minL2, maxL2, dp2,k);
    		if (sortedLen1 + sortedLen2 > k){
    			merge(dp1 + k*(maxL1 - sortedLen1), sortedLen1, dp2 + k*(maxL2 - sortedLen2), sortedLen2, tmp, k);
    			vector<int> resv(tmp, tmp + k);
    			delete[] res;
    			return resv;
    		}
    		for (int i = minL1; i <= maxL1; ++i){
    			merge(dp1+k*(maxL1-i), i, dp2+k*(maxL2-k+i), (k-i), tmp,k);
    			if (memcmp(res, tmp, step) < 0) memcpy(res, tmp, step);
    		}
    	}
    	vector<int> resv(res, res + k);
    	delete[] res;
    	return resv;
    }
};
```
```
```
```
```
```
```
```
```
## 322_CoinChange
```
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        n = len(coins)

        def dfs(idx, amount):
            if amount == 0:
                return 0
            if idx < n and amount > 0:
                min_cost = float('inf')
                for x in range(0, amount // coins[idx] + 1):
                    res = dfs(idx + 1, amount-x * coins[idx])
                    if res != -1:
                        min_cost = min(min_cost, res + x)
                return -1 if min_cost == float('inf') else min_cost
            return -1

        return dfs(0, amount)

    # Time Limit Exceeded
```
```
from functools import lru_cache


class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:

        @lru_cache(None)
        def dfs(rem):
            if rem < 0:
                return -1
            if rem == 0:
                return 0
            min_cost = float('inf')
            for coin in coins:
                res = dfs(rem - coin)
                if res != -1:
                    min_cost = min(min_cost, res + 1)
            return min_cost if min_cost != float('inf') else -1

        return dfs(amount)
```
```
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [float('inf')] * (amount + 1)
        dp[0] = 0
        
        for coin in coins:
            for x in range(coin, amount + 1):
                dp[x] = min(dp[x], dp[x - coin] + 1)
        return dp[amount] if dp[amount] != float('inf') else -1 
```
```
```
```
```
## 323_NumberofConnectedComponentsinanUndirectedGraph
```
class Solution {
public:
    void dfs(vector<int> adjList[], vector<int> &visited, int src) {
        visited[src] = 1;
        
        for (int i = 0; i < adjList[src].size(); i++) {
            if (visited[adjList[src][i]] == 0) {
                dfs(adjList, visited, adjList[src][i]);
            }
        }
    }
    
    int countComponents(int n, vector<vector<int>>& edges) {
        if (n == 0) return 0;
      
        int components = 0;
        vector<int> visited(n, 0);
        vector<int> adjList[n];
    
        for (int i = 0; i < edges.size(); i++) {
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                components++;
                dfs(adjList, visited, i);
            }
        }
        return components;
    }
};
```
```
class Solution {
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
```
```
```
```
```
```
```
## 324_WiggleSortII
```
class Solution:
    def wiggleSort(self, nums):
        nums.sort()
        half = len(nums[::2])
        nums[::2], nums[1::2] = nums[:half][::-1], nums[half:][::-1]

```
```
```
```
```
```
```
```
```
## 325_MaximumSizeSubarraySumEqualsk
```
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int prefixSum = 0;
        int longestSubarray = 0;
        unordered_map<int, int> indices;
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];

            // Check if all of the numbers seen so far sum to k.
            if (prefixSum == k) {
                longestSubarray = i + 1;
            }
            
            // If any subarray seen so far sums to k, then
            // update the length of the longest_subarray. 
            if (indices.find(prefixSum - k) != indices.end()) {
                longestSubarray = max(longestSubarray, i - indices[prefixSum - k]);
            }

            // Only add the current prefix_sum index pair to the 
            // map if the prefix_sum is not already in the map.
            if (indices.find(prefixSum) == indices.end()) {
                indices[prefixSum] = i;
            }
        }
        
        return longestSubarray;
    }
};
```
```
class Solution:
    def maxSubArrayLen(self, nums: List[int], k: int) -> int:
        prefix_sum = longest_subarray = 0
        indices = {}
        
        for i, num in enumerate(nums):
            prefix_sum += num
            
            # Check if all of the numbers seen so far sum to k.
            if prefix_sum == k:
                longest_subarray = i + 1
                
            # If any subarray seen so far sums to k, then
            # update the length of the longest_subarray. 
            if prefix_sum - k in indices:
                longest_subarray = max(longest_subarray, i - indices[prefix_sum - k])
                
            # Only add the current prefix_sum index pair to the 
            # map if the prefix_sum is not already in the map.
            if prefix_sum not in indices:
                indices[prefix_sum] = i
        
        return longest_subarray
```
```
```
```
```
```
```
## 326_PowerofThree
```
public class Solution {
    public boolean isPowerOfThree(int n) {
        if (n < 1) {
            return false;
        }

        while (n % 3 == 0) {
            n /= 3;
        }

        return n == 1;
    }
}
```
```
public class Solution {
    public boolean isPowerOfThree(int n) {
        return Integer.toString(n, 3).matches("^10*$");
    }
}
```
```
```
```
```
```
```
## 327_CountofRangeSum
```
class Solution {
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
```
```
```
```
```
```
```
```
```
## 328_OddEvenLinkedList
```
public class Solution {
    public ListNode oddEvenList(ListNode head) {
        if (head == null) return null;
        ListNode odd = head, even = head.next, evenHead = even;
        while (even != null && even.next != null) {
            odd.next = even.next;
            odd = odd.next;
            even.next = odd.next;
            even = even.next;
        }
        odd.next = evenHead;
        return head;
    }
}
```
```
```
```
```
```
```
```
```
## 329_LongestIncreasingPathinaMatrix
```
// Naive DFS Solution
// Time Limit Exceeded
public class Solution {
  private static final int[][] dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  private int m, n;

  public int longestIncreasingPath(int[][] matrix) {
      if (matrix.length == 0) return 0;
      m = matrix.length;
      n = matrix[0].length;
      int ans = 0;
      for (int i = 0; i < m; ++i)
          for (int j = 0; j < n; ++j)
              ans = Math.max(ans, dfs(matrix, i, j));
      return ans;
  }

  private int dfs(int[][] matrix, int i, int j) {
      int ans = 0;
      for (int[] d : dirs) {
          int x = i + d[0], y = j + d[1];
          if (0 <= x && x < m && 0 <= y && y < n && matrix[x][y] > matrix[i][j])
              ans = Math.max(ans, dfs(matrix, x, y));
      }
      return ++ans;
  }
}
```
```
// DFS + Memoization Solution
// Accepted and Recommended
public class Solution {
    private static final int[][] dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    private int m, n;

    public int longestIncreasingPath(int[][] matrix) {
        if (matrix.length == 0) return 0;
        m = matrix.length; n = matrix[0].length;
        int[][] cache = new int[m][n];
        int ans = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                ans = Math.max(ans, dfs(matrix, i, j, cache));
        return ans;
    }

    private int dfs(int[][] matrix, int i, int j, int[][] cache) {
        if (cache[i][j] != 0) return cache[i][j];
        for (int[] d : dirs) {
            int x = i + d[0], y = j + d[1];
            if (0 <= x && x < m && 0 <= y && y < n && matrix[x][y] > matrix[i][j])
                cache[i][j] = Math.max(cache[i][j], dfs(matrix, x, y, cache));
        }
        return ++cache[i][j];
    }
}
```
```
// Topological Sort Based Solution
// An Alternative Solution
public class Solution {
    private static final int[][] dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    private int m, n;
    public int longestIncreasingPath(int[][] grid) {
        int m = grid.length;
        if (m == 0) return 0;
        int n = grid[0].length;
        // padding the matrix with zero as boundaries
        // assuming all positive integer, otherwise use INT_MIN as boundaries
        int[][] matrix = new int[m + 2][n + 2];
        for (int i = 0; i < m; ++i)
            System.arraycopy(grid[i], 0, matrix[i + 1], 1, n);

        // calculate outdegrees
        int[][] outdegree = new int[m + 2][n + 2];
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                for (int[] d: dir)
                    if (matrix[i][j] < matrix[i + d[0]][j + d[1]])
                        outdegree[i][j]++;

        // find leaves who have zero out degree as the initial level
        n += 2;
        m += 2;
        List<int[]> leaves = new ArrayList<>();
        for (int i = 1; i < m - 1; ++i)
            for (int j = 1; j < n - 1; ++j)
                if (outdegree[i][j] == 0) leaves.add(new int[]{i, j});

        // remove leaves level by level in topological order
        int height = 0;
        while (!leaves.isEmpty()) {
            height++;
            List<int[]> newLeaves = new ArrayList<>();
            for (int[] node : leaves) {
                for (int[] d:dir) {
                    int x = node[0] + d[0], y = node[1] + d[1];
                    if (matrix[node[0]][node[1]] > matrix[x][y])
                        if (--outdegree[x][y] == 0)
                            newLeaves.add(new int[]{x, y});
                }
            }
            leaves = newLeaves;
        }
        return height;
    }
}
```
```
```
```
```
## 330_PatchingArray
```
```
```
```
```
```
```
```
```
```
## 331_VerifyPreorderSerializationofaBinaryTree
```
```
```
```
```
```
```
```
```
```
## 332_ReconstructItinerary
```
```
```
```
```
```
```
```
```
```
## 333_LargestBSTSubtree
```
```
```
```
```
```
```
```
```
```
## 334_IncreasingTripletSubsequence
```
```
```
```
```
```
```
```
```
```
## 335_SelfCrossing
```
```
```
```
```
```
```
```
```
```
## 336_PalindromePairs
```
```
```
```
```
```
```
```
```
```
## 337_HouseRobberIII
```
```
```
```
```
```
```
```
```
```
## 338_CountingBits
```
```
```
```
```
```
```
```
```
```
## 339_NestedListWeightSum
```
```
```
```
```
```
```
```
```
```
## 340_LongestSubstringwithAtMostKDistinctCharacters
```
```
```
```
```
```
```
```
```
```
## 341_FlattenNestedListIterator
```
```
```
```
```
```
```
```
```
```
## 342_PowerofFour
```
```
```
```
```
```
```
```
```
```
## 343_IntegerBreak
```
```
```
```
```
```
```
```
```
```
## 344_ReverseString
```
```
```
```
```
```
```
```
```
```
## 345_ReverseVowelsofaString
```
```
```
```
```
```
```
```
```
```
## 346_MovingAveragefromDataStream
```
```
```
```
```
```
```
```
```
```
## 347_TopKFrequentElements
```
```
```
```
```
```
```
```
```
```
## 348_DesignTic-Tac-Toe
```
```
```
```
```
```
```
```
```
```
## 349_IntersectionofTwoArrays
```
```
```
```
```
```
```
```
```
```
## 350_IntersectionofTwoArraysII
```
```
```
```
```
```
```
```
```
```
## 351_AndroidUnlockPatterns
```
```
```
```
```
```
```
```
```
```
## 352_DataStreamasDisjointIntervals
```
```
```
```
```
```
```
```
```
```
## 353_DesignSnakeGame
```
```
```
```
```
```
```
```
```
```
## 354_RussianDollEnvelopes
```
```
```
```
```
```
```
```
```
```
## 355_DesignTwitter
```
```
```
```
```
```
```
```
```
```
## 356_LineReflection
```
```
```
```
```
```
```
```
```
```
## 357_CountNumberswithUniqueDigits
```
```
```
```
```
```
```
```
```
```
## 358_RearrangeStringkDistanceApart
```
```
```
```
```
```
```
```
```
```
## 359_LoggerRateLimiter
```
```
```
```
```
```
```
```
```
```
## 360_SortTransformedArray
```
```
```
```
```
```
```
```
```
```
## 361_BombEnemy
```
```
```
```
```
```
```
```
```
```
## 362_DesignHitCounter
```
```
```
```
```
```
```
```
```
```
## 363_MaxSumofRectangleNoLargerThanK
```
```
```
```
```
```
```
```
```
```
## 364_NestedListWeightSumII
```
```
```
```
```
```
```
```
```
```
## 365_WaterandJugProblem
```
```
```
```
```
```
```
```
```
```
## 366_FindLeavesofBinaryTree
```
```
```
```
```
```
```
```
```
```
## 367_ValidPerfectSquare
```
```
```
```
```
```
```
```
```
```
## 368_LargestDivisibleSubset
```
```
```
```
```
```
```
```
```
```
## 369_PlusOneLinkedList
```
```
```
```
```
```
```
```
```
```
## 370_RangeAddition
```
```
```
```
```
```
```
```
```
```
## 371_SumofTwoIntegers
```
```
```
```
```
```
```
```
```
```
## 372_SuperPow
```
```
```
```
```
```
```
```
```
```
## 373_FindKPairswithSmallestSums
```
```
```
```
```
```
```
```
```
```
## 374_GuessNumberHigherorLower
```
```
```
```
```
```
```
```
```
```
## 375_GuessNumberHigherorLowerII
```
```
```
```
```
```
```
```
```
```
## 376_WiggleSubsequence
```
```
```
```
```
```
```
```
```
```
## 377_CombinationSumIV
```
```
```
```
```
```
```
```
```
```
## 378_KthSmallestElementinaSortedMatrix
```
```
```
```
```
```
```
```
```
```
## 379_DesignPhoneDirectory
```
```
```
```
```
```
```
```
```
```
## 380_InsertDeleteGetRandomO(1)
```
```
```
```
```
```
```
```
```
```
## 381_InsertDeleteGetRandomO(1)-Duplicatesallowed
```
```
```
```
```
```
```
```
```
```
## 382_LinkedListRandomNode
```
```
```
```
```
```
```
```
```
```
## 383_RansomNote
```
```
```
```
```
```
```
```
```
```
## 384_ShuffleanArray
```
```
```
```
```
```
```
```
```
```
## 385_MiniParser
```
```
```
```
```
```
```
```
```
```
## 386_LexicographicalNumbers
```
```
```
```
```
```
```
```
```
```
## 387_FirstUniqueCharacterinaString
```
```
```
```
```
```
```
```
```
```
## 388_LongestAbsoluteFilePath
```
```
```
```
```
```
```
```
```
```
## 389_FindtheDifference
```
```
```
```
```
```
```
```
```
```
## 390_EliminationGame
```
```
```
```
```
```
```
```
```
```
## 391_PerfectRectangle
```
```
```
```
```
```
```
```
```
```
## 392_IsSubsequence
```
```
```
```
```
```
```
```
```
```
## 393_UTF-8Validation
```
```
```
```
```
```
```
```
```
```
## 394_DecodeString
```
```
```
```
```
```
```
```
```
```
## 395_LongestSubstringwithAtLeastKRepeatingCharacters
```
```
```
```
```
```
```
```
```
```
## 396_RotateFunction
```
```
```
```
```
```
```
```
```
```
## 397_IntegerReplacement
```
```
```
```
```
```
```
```
```
```
## 398_RandomPickIndex
```
```
```
```
```
```
```
```
```
```
## 399_EvaluateDivision
```
```
```
```
```
```
```
```
```
```
## 400_NthDigit
```
```
```
```
```
```
```
```
```
```

