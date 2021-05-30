// 给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。

// 需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。

// 检查栈顶的字符是否在后面出现
// 溢出，无法发现问题

class Solution {
public:
    string removeDuplicateLetters(string s) {
      stack<char> chrs;
      string res = "";
      for (int i = 0; i != s.size(); ++i){
        while (chrs.top()){
          if (s[i] > chrs.top()){
            for (int j = i; j != s.size(); ++j){
              if (s[j] == chrs.top()){
                chrs.pop();
                break;
              }
              chrs.push(s[i]);
            }
          }else if (s[i] == chrs.top()){
            break;
          }else{
            chrs.push(s[i]);
          }
        }
      }
      while (!chrs.empty()){
        res = chrs.top() + res;
        chrs.pop();
      }
      return res;
    }
};

class Solution {
public:
    string removeDuplicateLetters(string s) {
      vector<int> vis(26), num(26);
      // 统计所有的字母的个数
      for (auto ch : s){
        num[ch - 'a']++;
      }

      string stk;
      for (auto ch : s){
        if (!vis[ch - 'a']){
          while (!stk.empty() && stk.back() > ch){
            if (num[stk.back() - 'a'] > 0){
              vis[stk.back() - 'a'] = 0;
              stk.pop_back();
            }else{
              // num的对应字母个数为0，不需要压出
              break;
            }
          }
          vis[ch - 'a'] = 1;
          stk.push_back(ch);
        }
        num[ch - 'a'] -= 1;
      }
      return stk;
    }
};