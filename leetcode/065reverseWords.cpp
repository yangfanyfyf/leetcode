// 给定一个字符串，逐个翻转字符串中的每个单词。



class Solution {
public:
    string reverseWords(string s) {
      string ret;
      // 使用vector保存每一个单词
      // 之后翻转输出
      vector<string> temp;
      int k = 0;
      temp.push_back("");
      for (int i = 0; i != s.size(); ++i){
        if (s[i] != ' '){
          temp[k] += s[i];
        }else if (s[i] == ' ' && temp[k] != ""){
          ++k;
          temp.push_back("");
        }
      }
      for (int i = temp.size() - 1; i >= 0; --i){
        if (ret.empty()) {
          ret = temp[i];
          continue;
        }else{
          ret += ' ' + temp[i];
        }
      }
      return ret;
    }
};

// 使用自带的reverse函数
// 先翻转整个字符串，再翻转每一个单词
string reverseWords(string s) {
  reverse(s.begin(), s.end());

  int n = s.size();
  int  idx = 0;
  for (int start = 0; start < n; ++start){
    // 从非空格开始
    if (s[start] != ' ') {
      // idx != 0, 表明已经有了翻转后的单词，需要添加一个空格
      if (idx != 0) s[idx++] = ' ';

      int end = start;
      while (end < n && s[end] != ' '){
        s[idx++] = s[end++];
      }

      reverse(s.begin() + idx - (end - start), s.begin() + idx);

      start = end;
    }
  }
  s.erase(s.begin() + idx, s.end());
  return s;

}