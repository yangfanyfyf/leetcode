// 给定一个二维矩阵，计算其子矩形范围内元素的总和，该子矩阵的左上角为 (row1, col1) ，右下角为 (row2, col2) 。


// 假设不适用预处理，每次遍历
// 超出时间限制
class NumMatrix {
public:
    vector<vector<int> > vec;
    int sum;
    NumMatrix(vector<vector<int>>& matrix) {
      vec = matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
      sum = 0;
      for (int i = row1; i != row2 + 1; ++i){
        for (int j = col1; j != col2 + 1; ++j){
          sum += vec[i][j];
        }
      }
      return sum;
    }
};

// 使用类似于单个数组的预处理
class NumMatrix {
public:
    vector<vector<int> > vec;
    NumMatrix(vector<vector<int>>& matrix) {
      if (matrix.size() > 0){
        vec.resize(matrix.size(), vector<int> (matrix[0].size() + 1));
        for (int i = 0; i != matrix.size(); ++i){
            for (int j = 0; j != matrix[0].size(); ++j){
            vec[i][j + 1] = vec[i][j] + matrix[i][j];
            }
        }
      }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
      int sum = 0;
      for (int i = row1; i != row2 + 1; ++i){
        sum += vec[i][col2 + 1] - vec[i][col1];
      }
      return sum;
    }
};