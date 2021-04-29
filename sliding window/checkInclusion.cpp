// 给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。

// 换句话说，第一个字符串的排列之一是第二个字符串的 子串 。

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      int len = s1.size();
      if (len > s2.size()) return false;

      unordered_map<char, int> ori, temp;
      for (int i = 0; i != len; ++i){
        ++ori[s1[i]];
        ++temp[s2[i]];
      }
      int start = 0, end = len + start - 1;
      int flag = 0;
      while (end < s2.size()){
        flag = 0;
        for (const auto &p : ori){
          if (temp[p.first] != p.second){
            // 将窗口后移
            --temp[s2[start++]];
            ++temp[s2[++end]];
            flag = 1;
            break;
          }
        }
        if(!flag) return true;
      }
      return false;
    }
};