// 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。
// 如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。


class Solution {
public:
    unordered_map<char, int> ori, cnt;
    // 保证cnt中的字母，包含了ori中的
    bool check(){
      for (const auto &p : ori){
        if (cnt[p.first] < p.second){
          return false;
        }
      }
      return true;
    }
    string minWindow(string s, string t) {
      // 将t存储到ori中
      for (const auto &c : t){
        ++ori[c];
      }
      int l = 0, r = -1;
      int len = INT_MAX, ansL = -1, ansR = -1;
      // 开始遍历S
      while (r < int(s.size())){
        // 向cnt中添加
        if (ori.find(s[++r]) != ori.end()){
          // 在
          ++cnt[s[r]];
        }
        // 移动l
        while (check() && l <= r){
          if (r - l + 1 < len){
            len = r - l + 1;
            ansL = l;
          }
          if (ori.find(s[l]) != ori.end()){
            --cnt[s[l]];
          }
          ++l;
        }
      }
      return ansL == -1 ? string() : s.substr(ansL, len);
    }
};