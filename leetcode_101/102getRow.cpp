// 给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。

// 利用组合数
// 超过范围
class Solution {
public:
    int fac(int i){
      if (i == 0 || i == 1){
        return 1;
      } else {
        return i * fac(i - 1);
      }

    }
    vector<int> getRow(int rowIndex) {
      vector<int> ret(rowIndex + 1, 0);
      ret[0] = ret[rowIndex] = 1;
      int facN = fac(rowIndex);
      for (int i = 1; i != rowIndex; ++i){
        int facM = fac(i);
        int facNM = fac(rowIndex - i);
        ret[i] = facN / facM / facNM;
      }
      return ret;
    }
};



class Solution {
public:
    vector<int> getRow(int rowIndex) {
      vector<int> row(rowIndex + 1);
      row[0] = 1;
      for (int i = 1; i <= rowIndex; ++i){
        // 1LL用于将int 转换为long long
        row[i] = 1LL * row[i - 1] * (rowIndex - i + 1) / i;
      }
      return row;
    }
};
