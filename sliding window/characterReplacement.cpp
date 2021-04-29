// 给你一个仅由大写英文字母组成的字符串，你可以将任意位置上的字符替换成另外的字符，总共可最多替换 k 次。

// 在执行上述操作后，找到包含重复字母的最长子串的长度。

class Solution {
public:
    int characterReplacement(string s, int k) {
      vector<int> nums(26);
      int maxn = 0;
      int left = 0, right = 0;
      while (right < s.size()){
        ++nums[s[right] - 'A'];
        maxn = max(maxn, nums[s[right] - 'A']);
        if (right - left + 1 - maxn > k){
          --nums[s[left++] - 'A'];
        }
        ++right;
      }
      return right - left;
    }
};