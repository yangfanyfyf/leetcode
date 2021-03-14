// 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret(numRows);
        for (int i = 0; i != numRows; ++i){
          // 每一行有i + 1个数字
          ret[i].resize(i + 1);
          ret[i][0] = ret[i][i] = 1;
          for(int j = 1; j < i; ++j){
            ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
          }
        }
        return ret;
    }
};