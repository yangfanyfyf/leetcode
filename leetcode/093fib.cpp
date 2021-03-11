// 斐波那契数，通常用 F(n) 表示，形成的序列称为 斐波那契数列 。

// 该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。
#include <iostream>
#include <vector>
using namespace std;
// class Solution {
// public:
//     int fib(int n) {
//         if (n < 2){
//             return n;
//         }
//         return fib(n - 1) + fib(n - 2);
//     }
// };

// // DP
// class Solution {
// public:
    int fib(int n) {
      if (n < 2){
        return n;
      }
      vector<int> dp(n, 0);
      for (int i = 2; i != n + 1; ++i){
        dp[i] = dp[i - 1] + dp[i - 2];
      }
      return dp[n];
    }
// };

int main(){
  cout << fib(1) << endl;
}