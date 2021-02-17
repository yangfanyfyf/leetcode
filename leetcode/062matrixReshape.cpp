// 给出一个由二维数组表示的矩阵，以及两个正整数r和c，分别表示想要的重构的矩阵的行数和列数。

// 重构后的矩阵需要将原始矩阵的所有元素以相同的行遍历顺序填充。
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
  if (!(r * c == nums.size() * nums[0].size())){
    return nums;
  }
  vector<vector<int>> ret(r, vector<int>(c, 0));
  int rNum = 0;
  int cNum = 0;
  for (int i = 0; i != nums.size(); ++i){
    for (int j = 0; j != nums[0].size(); ++j){
      ret[rNum][cNum++] = nums[i][j];
      if (cNum == c){
        cNum = 0;
        ++rNum;
      }
    }
  }
  return ret;
}
