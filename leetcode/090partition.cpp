// 给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

// 返回 s 所有可能的分割方案。


class Solution {
private:
    vector<vector<int>> f;
    vector<vector<string>> ret;
    vector<string> ans;
    int n;
public:
    void dfs(const string& s, int i){
      if (i == n){
        ret.push_back(ans);
        return;
      }
      // i 是起始位置
      for (int j = i; j != n; ++j){
        // 将子字符串放入
        if (f[i][j]){
          // substr第二个输入是字符串的长度
          ans.push_back(s.substr(i, j - i + 1));
          dfs(s, j + 1);
          ans.pop_back();
        }
      }
    }

    vector<vector<string>> partition(string s) {
      n = s.size();
      // n * n 的矩阵
      f.assign(n, vector<int>(n, true));
      // 动态规划，从最后开始？最后的就是最简单的状态
      for (int i = n - 1; i >= 0; --i){
        for (int j = i + 1; j < n; ++j){
          // i, j对应位置相同，并且内部的字母也是回文
          f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];
        }
      }

      dfs(s, 0);
      return ret;
    }
};