// 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
using namespace std;

// 双指针，当出现重复字母时，重置
// int lengthOfLongestSubstring(string s) {
//   int len = s.size();
//   int ret = 0;
//   int start = 0, end = 0;
//   while (end < len){
//     if (find(s.begin() + start, s.begin() + end, s[end]) != s.begin() + end){
//       start = ;
//     }
//     ret = max(ret, end - start + 1);
//     cout << ret << endl;
//     ++end;
//   }
//   return ret;
// }

// 如何处理循环的边界？
int lengthOfLongestSubstring(string s) {
  unordered_set<char> occ;
  int n = s.size();
  int rk = -1, ans = 0;
  // 枚举左指针的位置 
  for (int i = 0; i != n; ++i){
    if(i != 0){
      occ.erase(s[i - 1]);
    }
    while (rk + 1 < n && !occ.count(s[rk + 1])){
      // 不断的移动右指针，单独的循环
      occ.insert(s[rk + 1]);
      ++rk;
    }
    ans = max(ans, rk - i + 1);
  }
  return ans;
}



int main() {
  string s = "pwwkew";
  int ret = lengthOfLongestSubstring(s);

  cout << ret << endl;
}
