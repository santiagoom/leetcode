
#include <iostream>
#include <cppUtils.h>
using namespace std;

                    
class Solution_313_SuperUglyNumber_1 {
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

int main() {
auto *so = new Solution_313_SuperUglyNumber_1();
vector<int> nums{2, 7, 11, 15};
int target = 26;
string s = "aa";
vector<vector<int>> arrays;
CppUtils::print(s);
CppUtils::print_1d_vector(nums);
CppUtils::print_2d_vector(arrays);
return 0;
}
                    