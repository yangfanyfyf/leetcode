// 在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0){
          return false;
        }
        if (target >= matrix[matrix.size() - 1][0] && target <= matrix[matrix.size() - 1][matrix[0].size() -1]){
          for (int i = 0; i != matrix[0].size(); ++i){
            if (target == matrix[matrix.size() - 1][i]){
              return true;
            }
          } 
        }
        for (int i = 0; i != matrix.size() - 2; ++i){
          if (target >= matrix[i][0] && target < matrix[i + 1][0]){
            for (int j = 0; j != matrix[i].size(); ++j){
              if (target == matrix[i][j]){
                return true;
              }
            }
          }
        }
        return false;
    }
};

// 先按列查找，再按行查找
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
      // 遍历到最后一个位置
      // 该值大于下一个值
      if (matrix.size() == 0 || matrix[0].size() == 0){
        return false;
      }
      int i = 0;
      while(i != matrix.size()){
        for(int j = 0; j != matrix[0].size(); ++j){
          if (target == matrix[i][j]){
            return true;
          }
          if (target > matrix[i][j] && target < matrix[i][j + 1] || j == matrix[0].size()){
            ++i;
            break;
          }
        }
      }
      return false;
    }
};