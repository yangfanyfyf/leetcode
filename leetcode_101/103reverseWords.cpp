// 给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

class Solution {
public:
    void swapWord(string& s, int start, int end){
      while (start < end){
        swap(s[start++], s[end--]);
      }
    }
    string reverseWords(string s) {
      int st = 0;
      for (int i = 0; i <= s.size(); ++i){
        if (s[i] == ' ' || i == s.size()){
          swapWord(s, st, i - 1);
          st = i + 1;
        }
      }
      return s;
    }
};