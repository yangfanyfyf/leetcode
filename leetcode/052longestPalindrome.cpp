// 给你一个字符串 s，找到 s 中最长的回文子串。
#include <string>
#include <iostream>
using namespace std;

// 枚举所有的大于2的字符串，然后依次判断是否是回文
string longestPalindrome(string s){
  int n = s.size();
  vector<vector<int>> dp(n, vector<int>(n));
  string ans;
  // l 是长度
  for (int l = 0; l != n; ++l){
    for (int i = 0; i + l != n; ++i){
      int j = i + l;
      if (l == 0){
        // 单个字母一定是回文
        dp[i][j] = 1;
      }else if (l == 1){
        // 两个字母要求相等
        dp[i][j] = (s[i] == s[j]);
      }else {
        // 状态转移
        dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
      }
      if (dp[i][j] && l + 1 >ans.size()){
        ans = s.substr(i, l + 1);
      }
    }
  }
  return ans;
}