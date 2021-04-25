// 给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。

// 字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。

// 作者：liweiwei1419
// 链接：https://leetcode-cn.com/leetbook/read/learning-algorithms-with-leetcode/x10umm/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
      unordered_map<char, int> ori, temp;
      // 初始化
      for (int i = 0; i != p.size(); ++i){
        ++ori[p[i]];
        ++temp[s[i]];
      }

      vector<int> ret;
      int start = 0, end = p.size() + start - 1;

      int flag = 0;

      while (end < s.size()){
        for (const auto &p : ori){
          if (temp[p.first] != p.second){
            flag = 1;
            // --temp[s[start++]];
            // ++temp[s[++end]];
            break;
          }
          
        }
        if (!flag) ret.push_back(start);
        --temp[s[start++]];
        ++temp[s[++end]];
        flag = 0;
      }
      return ret;
    }
};