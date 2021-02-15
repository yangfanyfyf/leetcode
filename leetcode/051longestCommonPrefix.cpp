// 编写一个函数来查找字符串数组中的最长公共前缀。

// 如果不存在公共前缀，返回空字符串 ""。

string longestCommonPrefix(vector<string>& strs) {
  if (strs.empty()) return string();
  sort(strs.begin(), strs.end());
  string st = strs.front(), en = strs.back();
  int i, num = min(st.size(), en.size());
  for(i = 0; i < num && st[i] == en[i]; ++i);
  return string(st, 0, i);
}