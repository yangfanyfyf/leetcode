// 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。

// 如果 word 存在于网格中，返回 true ；否则，返回 false 。

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
      rows = board.size();
      cols = board[0].size();
      for (int i = 0; i != rows; ++i){
        for (int j = 0; j != cols; ++j){
          if (dfs(board, word, i, j, 0)){
            return true;
          }
        }
      }
      return false;
    }
private:
    int rows, cols;
    bool dfs(vector<vector<char>> &board, string word, int i, int j, int k){
      // 判断越界，以及不相等的情况
      if (i >= rows || i < 0 || j >= cols || j < 0 || board[i][j] != word[k]) return false;
      // 检测了所有的字母
      if (k == word.size() - 1) return true;
      // 标记为已访问
      board[i][j] = '\0';
      bool res = dfs(board, word, i + 1, j, k + 1) || dfs(board, word, i - 1, j, k + 1) || 
                  dfs(board, word, i, j + 1, k + 1) || dfs(board, word, i , j - 1, k + 1);
      board[i][j] = word[k];
      return res;
    }
};